/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#include <iostream>
#include <stdlib.h>
#include "bully_header.h"
using namespace std;

Tailor::Tailor(const string name, const char icon)
{
  m_name = name;
  m_icon = icon;
  
  // between min and max
  m_money = START_MONEY_MIN + rand() % (START_MONEY_MAX - START_MONEY_MIN);
  m_health = START_HEALTH;  
  m_loc.x = -1;
  m_loc.y = 1;
  m_isAlive = true;
  m_pantTotal = START_PANTS;
}

ostream & operator <<(ostream & os, Tailor & tailor)
{
  os << tailor.m_name << " [" << tailor.m_icon << "] is ";
  os << (tailor.m_isAlive ? "alive" : "dead") << " at (" << tailor.m_loc.x;
  os << ", " << tailor.m_loc.y << ") with $" << tailor.m_money << ", ";
  os << tailor.m_health << " health, and " << tailor.m_pantTotal << " pants.";
  os << endl;
  return os;
}

bool Tailor::move(Town & town, const int x, const int y)
{
  bool set = false;
  
  // try to set in new location
  set = town.setChar(x, y, m_icon);
  
  // if successful
  if (set)
  {
    // clear old location
    town.clearChar(m_loc.x, m_loc.y);
    
    // move tailor loc
    m_loc.x = x;
    m_loc.y = y;
  }
  
  return set;
}

void Tailor::placeMe(Town & town)
{
  int x, y;
  town.findRandEmptySpot(x, y);
  move(town, x, y);
  return;
}

void Tailor::randWalk(Town & town, Bully & bully)
{
  int tempX = m_loc.x, tempY = m_loc.y;
  
  char closeChar;
  bool hasThrown;
    
  if (town.findNewSpotByDir(tempX, tempY))
  {
    move(town, tempX, tempY);

    closeChar = town.findNearestChar(tempX, tempY);    
    hasThrown = town.getHasThrown(tempX, tempY);
    
    // if near a house    
    if (closeChar == HOUSE_ICON && !hasThrown && rand() % 100 < HOUSE_CHANCE)
    {
      if (m_pantTotal <= 0)
        cout << endl << "EXIT: All pants were sold" << endl;
      
      town.setHasThrown(tempX, tempY, true);
      m_money += PANT_SELL_AMT;
      m_pantTotal--;
    }
    
    // if near a bully
    if (closeChar == BULLY_ICON)
    {
      if (rand() % 100 < BULLY_CHANCE)
        bully.punch(*this, town);
      else
        cout << "The bully says, " << bully.getRandString(BULLY_MESSAGES);
        cout << endl;
    }
    
    // if near pants
    if (closeChar == PANT_ICON)
    {
        Pant pant;
        pant.kill(*this);
    }
    
    // pant walk
    if (rand() % 100 < PANT_STEP_CHANCE && town.getActivePants() > 0)
    {
      for (int i = 0; i < town.getActivePants(); i++)
      {
        Pant pant = town.getPant(i);
        pant.chase(*this, town);
        town.setPant(i, pant);
      }
    }
    
  }
  // if the tailor gets stuck, exit
  else
  {
    cout << endl << "EXIT: Could not move" << endl;
    exit(2);
  }
  
  return;
}

void Tailor::removeMoney(const int amt)
{
  m_money -= amt;
  return;
}

void Tailor::removeHealth(const int amt)
{
  m_health -= amt;
  if (m_health <= 0)
  {
    m_isAlive = false;
    m_health = 0;
    cout << endl << "EXIT: The tailor died" << endl;
  }
  return;
}