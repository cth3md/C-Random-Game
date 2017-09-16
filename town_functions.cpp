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

Town::Town(short size, short houses, short bullies)
{
  // default to MAX if an invalid size is given
  if (size <= MIN || size > MAX)
    size = MAX;
  
  m_size = size;
  m_houses = houses;
  m_bullies = bullies;
  
  clear();
  build();
  
  setActivePants(0);
}

ostream & operator <<(ostream & os, Town & town)
{
  for (int r = 0; r < town.m_size; r++)
  {
    for (int c = 0; c < town.m_size; c++)
      os << "[" << town.m_map[r][c].icon << "]";
    os << endl;
  }
  os << endl;
  return os;
}

void Town::clear()
{
  for (int r = 0; r < MAX; r++)
  {
    for (int c = 0; c < MAX; c++)
    {
      m_map[r][c].icon = EMPTY;
      m_map[r][c].hasThrown = false;
    }
  }
  return;
}

void Town::findRandEmptySpot(int & x, int & y)
{
  do
  {
    x = rand() % (m_size - 2) + 1; // wall offset
    y = rand() % (m_size - 2) + 1; // wall offset
  } while(m_map[x][y].icon != EMPTY);
  return;
}

char Town::findNearestChar(int & x, int & y)
{
  char c = '\0';
  char left = getChar(x - 1, y);
  char right = getChar(x + 1, y);
  char down = getChar(x, y - 1);
  char up  = getChar(x, y + 1);
  
  if (left != EMPTY && left != WALL_ICON)
  {
    c = left;
    x--;
  }
  else if (right != EMPTY && right != WALL_ICON)
  {
    c = right;
    x++;
  }
  else if (down != EMPTY && down != WALL_ICON)
  {
    c = down;
    y--;
  }
  else if (up != EMPTY && up != WALL_ICON)
  {
    c = up;
    y++;
  }
  
  return c;  
}

bool Town::findNewSpotByDir(int & x, int & y)
{
  bool isEmpty = false;
  
  int runAmt = 0;
  int dirAmt = 4;
  int choice = rand() % dirAmt;
  
  int tempX, tempY;

  do
  {
    tempX = x;
    tempY = y;
    
    if (choice == 0) // left
      tempX--;
    else if (choice == 1) // right
      tempX++;
    else if (choice == 2) // down
      tempY--;
    else if (choice == 3) // up
      tempY++;
    
    if (getChar(tempX, tempY) == EMPTY)
    {
      isEmpty = true;
      x = tempX;
      y = tempY;
    }
    else
    {
      choice++;      
      // preventing stepping off
      if (choice >= dirAmt)
        choice = 0;
    }
    
    runAmt++;
  } while(!isEmpty && runAmt < dirAmt);
  
  return isEmpty;
}

void Town::placeWalls()
{
  for (int r = 0; r < m_size; r++)
    for (int c = 0; c < m_size; c++)
      // only place walls on the bordering edges
      if (r == 0 || r == m_size - 1 || c == 0 || c == m_size - 1)
        m_map[r][c].icon = WALL_ICON;
  return;
}

void Town::placeHouses()
{
  int x, y, total = 0;
  
  do
  {
    // get rand spot
    findRandEmptySpot(x, y);
    
    // place house
    m_map[x][y].icon = HOUSE_ICON;
    m_map[x][y].hasThrown = false;
    total++;
    
    // if needed & possible: place house near last
    if (total < m_houses && findNewSpotByDir(x, y))
    {
      // place house
      m_map[x][y].icon = HOUSE_ICON;
      m_map[x][y].hasThrown = false;
      total++;
    }
  } while(total <= m_houses);
  
  return;
}

void Town::placeBullies()
{
  int x, y;
  for (int i = 0; i < m_bullies; i++)
  {
    findRandEmptySpot(x, y);
    m_map[x][y].icon = BULLY_ICON;
  }
  return;
}

void Town::build()
{  
  placeHouses();
  placeBullies();
  placeWalls();
  
  return;
}

bool Town::isWithinWalls(const int x, const int y) const
{
  return (x > 0 && x < m_size && y > 0 && y < m_size);
}

void Town::clearChar(const int x, const int y)
{
  if (isWithinWalls(x, y))
    m_map[x][y].icon = EMPTY;
  return;
}

bool Town::setChar(const int x, const int y, const char icon)
{
  bool set = false;
  if (isWithinWalls(x, y) && m_map[x][y].icon == EMPTY)
  {
    m_map[x][y].icon = icon;
    set = true;
  }
  return set;
}