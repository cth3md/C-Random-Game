/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#ifndef BULLY_HEADER_H
#define BULLY_HEADER_H

#include "header.h"
#include "town_header.h"
using namespace std;

const int MIN_POWER = 30;
const int MAX_POWER = 50;
const int PROBABILITY = 80;
const int PUNCH_DAMAGE = 10;

/*
Description: The Bully function is a constructor that sets a random name,
sets random power between MIN_POWER and MAX_POWER, and sets PROBABILITY.
Pre: None
Post: The constructed Bully is made.
*/

/*
Description: The punch function moves tailor to random spot, decreases
their health, money, and drops a pair of pants randomly.
Pre: None
Post: The passed tailor is changed and pants are placed in the town.
*/

/*
Description: The getRandString function returns a random line from the
passed input file string.
Pre: None
Post: Random string from file.
*/

class Bully
{
  public:
    Bully();
    void punch(Tailor & tailor, Town & town);
    string getRandString(string fileName);
  
  private:
    string m_name;
    short m_power;
    short m_probability;
};

#endif
