/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#include <iostream>
#include <stdlib.h>
#include "town_header.h"
using namespace std;

Pant::Pant()
{
  m_loc.x = -1;
  m_loc.y = 1;
}

void Pant::placeMe(Town & town)
{
  int x, y;
  town.findRandEmptySpot(x, y);
  move(town, x, y);
  return;
}

bool Pant::move(Town & town, const int x, const int y)
{
  bool set = false;
  
  // try to set in new location
  set = town.setChar(x, y, PANT_ICON);
  
  // if successful
  if (set)
  {
    // clear old location
    town.clearChar(m_loc.x, m_loc.y);
    
    // move pants loc
    m_loc.x = x;
    m_loc.y = y;
  }
  
  return set;
}

void Pant::chase(Tailor & tailor, Town & town)
{
  int x = m_loc.x;
  int y = m_loc.y;
  
  if ((x - tailor.getLoc().x) < 0)
    move(town, x + 1, y);
  else if ((x - tailor.getLoc().x) > 0)
    move(town, x - 1, y);
  
  if ((y - tailor.getLoc().y) < 0)
    move(town, x, y + 1);
  else if ((y - tailor.getLoc().y) > 0)
    move(town, x, y - 1);
  
  x = m_loc.x;
  y = m_loc.y;
  
  return;
}

void Pant::kill(Tailor & tailor)
{
  tailor.removeHealth(100);
  cout << "The tailor was attacked by pants!" << endl;
  
  return;
}