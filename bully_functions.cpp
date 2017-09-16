/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "bully_header.h"
using namespace std;

Bully::Bully()
{
  m_name = getRandString(BULLY_NAMES);
  m_power = MIN_POWER + rand() % (MAX_POWER - MIN_POWER);
  m_probability = PROBABILITY;
}


void Bully::punch(Tailor & tailor, Town & town)
{
  // move tailor to random spot
  tailor.placeMe(town);
  
  // remove money, 50 power = 50% etc.
  if (tailor.getMoney() != 0 && m_power != 0)
    tailor.removeMoney(tailor.getMoney() / (100 / m_power));
  
  // reduce tailor health
  tailor.removeHealth(PUNCH_DAMAGE);
  
  // drop pants
  if (town.getActivePants() < PANTS_AMT)
  {
    int activePantAmt = town.getActivePants();
    
    Pant pant = town.getPant(activePantAmt);
    pant.placeMe(town);
    town.setPant(activePantAmt, pant);
    
    town.setActivePants(activePantAmt + 1);
  }
  
  return;
}

string Bully::getRandString(string fileName)
{
  int count = 0;
  int choice;
  string output;
  
  ifstream fin;
  fin.open(fileName.c_str());

  // count amount of lines
  while (getline(fin, output, '\n'))
    count++;
  
  // pick random one
  choice = (rand() % count) + 1;
  
  fin.close();
  fin.open(fileName.c_str());
  
  // loop until that one, stopping at it
  for (int i = 1; i <= choice; i++)
    getline(fin, output, '\n');
  
  return output;
}