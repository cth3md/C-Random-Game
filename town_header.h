/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#ifndef TOWN_HEADER_H
#define TOWN_HEADER_H

#include "pants_header.h"
using namespace std;

/*
Description: The setChar changes the character display of a location 
on the grid, if empty
Pre: int x and int y should be within the town's walls and an empty location
Post: Returns whether or not the character was able to be set in the location
*/

/*
Description: The clearChar function resets the character display of a 
location to a space (nothing).
Pre: int x and int y should be within the town's walls
Post: The location is reset to contain nothing. 
*/

/*
Description: The clear function resets every location in the 
grid to a space (nothing).
Pre: None
Post: Every location in the grid is reset to a space. 
*/

/*
Description: The build function sets up the town by running placeHouses,
placeBullies, and placeWalls
Pre: None
Post: The town is edited with houses, bullies, and walls added.
*/

/*
Description: The isWithinWalls function checks to see if the given position 
is within the town's walls
Pre: int x and int y should be less than MAX
Post: Returns whether or not the location is within the walls
*/

/*
Description: Town is a constructor that creates a town giving it a size,
houses, bullies, and builds it.
Pre: Size must be > MIN and < MAX.
Post: A Town object is created.
*/

/*
Description: ostream function overloads the insertion operator to
display to the screen the values of the town passed to it. 
Pre: None
Post: The town is displayed on the screen. 
*/

/*
Description: The getSize function is an accessor that returns the town's size.
Pre: None
Post: The size of the town is returned. 
*/

/*
Description: The findNewSpotByDir function randomly chooses direction and 
will loop until it finds an empty direction and returns true if found. 
Pre: None
Post: An empty direction is found and a true value is returned. 
*/

/*
Description: The findRandEmptySpot function searches constantly for an empty 
spot in the town. 
Pre: None
Post: A random spot in the town is always being searched for. 
*/

/*
Description: The findNearestChar function returns the a character if it
is up, down, left, or right to the current space (with the exception of 
the wall character). 
Pre: None
Post: The character closest to the space is retuned. 
*/

/*
Description: The setActivePants function is a mutator that passes an amount
to assign to the town's active pants variable. 
Pre: None
Post: The active pants variable is assigned to the amount passed. 
*/

/*
Description: The getActivePants function is an accessor that returns the
town's active pants number. 
Pre: None
Post: The active pants number is returned. 
*/

/*
Description: The getChar function is an accesor that returns the character
at the current position in the town. 
Pre: None
Post: The character at the current location is returned. 
*/

/*
Description: The setHasThrown function is a mutator that update's the
character's thrown property.
Pre: None
Post: The character's location thrown value is updated.
*/

/*
Description: The getHasThrown function is an accessor that returns true
if the character has been thrown. 
Pre: None
Post: The boolean value is returned depending on if the character was 
thrown. 
*/

/*
Description: The placeWalls function places characters in the town 
to represent walls. 
Pre: None
Post: Wall characters are placed in the town. 
*/

/*
Description: The placeHouses function places characters in the town 
to represent houses. 
Pre: None 
Post: House characters are placed in the town. 
*/

/*
Description: The placeBullies function places characters in the town
to represent bullies.
Pre: None
Post: Bully characters are placed in the town. 
*/

/*
Description: The getPant function is an accesor that returns the
pant element requested.
Pre: None
Post: The pant element.
*/

/*
Description: The setPant function is a mutator that sets the pant
in the town.
Pre: None
Post: The pant element is updated.
*/

class Town
{
  public:
    // size must be > MIN and < MAX
    Town(short size, short houses, short bullies); 
    friend ostream & operator <<(ostream & os, Town & town); // overload
    void clearChar(const int x, const int y);
    bool findNewSpotByDir(int & x, int & y);
    void findRandEmptySpot(int & x, int & y);
    char findNearestChar(int & x, int & y);
    bool setChar(const int x, const int y, const char icon);
    void setActivePants(const int amt) { m_activePants = amt; return; }
    void setHasThrown(const int x, const int y, const bool thrown)
      { m_map[x][y].hasThrown = thrown; return; }
    void setPant(const int i, const Pant & pant) { m_pant[i] = pant; return; }
    short getSize() const { return m_size; }
    int getActivePants() const { return m_activePants; }
    char getChar(const int x, const int y) const { return m_map[x][y].icon; }
    bool getHasThrown(const int x, const int y) const
      { return m_map[x][y].hasThrown; }
    Pant getPant(const int i) const { return m_pant[i]; }
  
  private:
    Location m_map[MAX][MAX];
    short m_size;
    short m_houses;
    short m_bullies;
    void clear();
    void build();
    bool isWithinWalls(const int x, const int y) const;
    int m_activePants;    
    void placeWalls();
    void placeHouses();
    void placeBullies();
    Pant m_pant[PANTS_AMT];
};

#endif
