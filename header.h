/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#ifndef HEADER_H
#define HEADER_H

using namespace std;

// Declare constants

const short MIN = 3; // min grid size of town
const short MAX = 25; // max grid size of town

const char EMPTY = ' '; // represents a clear spot
const char TAILOR_ICON = 'M'; // represents tailors, as default
const char WALL_ICON = 'W'; // represents walls
const char BULLY_ICON = 'B'; // represents bullies
const char HOUSE_ICON = 'H'; // represents houses
const char PANT_ICON = 'P'; // represents houses

const int TOWN_SIZE = 17; // curent town size
const int HOUSE_AMT = 40; // amount of houses in the town
const int BULLIES_AMT = 10; // amount of bullies in the town
const int PANTS_AMT = 3; // amount of pants in the town

const int MAX_STEPS = 1000; // max walking steps

const string BULLY_NAMES = "bullies.dat"; // list of bully names
const string BULLY_MESSAGES = "message.dat"; // list of bully messages


// Define structs

// Grid location
struct Location
{
  char icon;
  bool hasThrown;
  int x;
  int y;
};



#endif
