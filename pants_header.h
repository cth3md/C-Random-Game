/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#ifndef PANTS_HEADER_H
#define PANTS_HEADER_H

#include "header.h"
#include "tailor_header.h"
using namespace std;

/*
Description: The Pants function is a constructor 
that sets an x and y location for the pants.
Pre: None
Post: A pair of pants is created with x and y coordinates
given. 
*/

/*
Description: The placeMe function places a pair of pants
at a random spot in the town. 
Pre: None
Post: A pair of pants are randomly placed in the passed town. 
*/

/*
Description: The chase function has the pants follow
the tailor throughout the town.
Pre: None 
Post: The pants moved towards the passed tailor, if possible.
*/

/*
Description: The move function tries to move the Pants to the x and y, 
on success updates their location
Pre: int x and int y should be within the town's walls and an empty location
Post: Whether or not it was able to move the Pants to an empty spot
*/

/*
Description: The kill function removes the health of the passed tailor.
Pre: None
Post: The health of the tailor passed is removed.
*/

class Town;

class Pant
{
  public:
    Pant();
    void placeMe(Town & town);
    void chase(Tailor & tailor, Town & town);
    void kill(Tailor & tailor);
  
  private:
    bool move(Town & town, const int x, const int y);
    Location m_loc;
};

#endif
