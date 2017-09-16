/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#ifndef TAILOR_HEADER_H
#define TAILOR_HEADER_H

using namespace std;

const int START_MONEY_MIN = 20;
const int START_MONEY_MAX = 40;
const int START_HEALTH = 100; // max of 100
const int START_PANTS = 30; // amt of pants started with
const int PANT_SELL_AMT = 10; // amt of money earned from selling pants

const int HOUSE_CHANCE = 70; // out of 100, likelyhood of pants being sold
const int BULLY_CHANCE = 80; // out of 100, likelyhood of getting bullied
const int PANT_STEP_CHANCE = 25; // out of 100, likelyhood of the pants moving

/*
Description: Tailor is a constructor that prepares the
tailor for use with the passed info.
Pre: None
Post: A tailor is created.
*/

/*
Description: ostream function overloads the insertion operator to
display to the screen the values of the tailor passed to it. 
Pre: None
Post: The member variables in tailor are displayed on the screen. 
*/

/*
Description: The placeMe function uses the move function
to set the Tailor to a random empty spot of the town.
Pre: None
Post: The tailor is moved.
*/

/*
Description: The randWalk function moves the Tailor randomly to the closest 
empty up, down, left, or right location. Also handles checks for bullies,
houses, and pants.
Pre: The tailor must have a free space to move, or the program will exit
Post: The tailor is moved either up, down, left, or right.
*/

/*
Description: The move function tries to move the Tailor to the x and y, 
on success updates their location
Pre: int x and int y should be within the town's walls and an empty location
Post: Whether or not it was able to move the Tailor to an empty spot
*/

/*
Description: The getMoney function is an accessor that returns
the amount of money that the tailor has. 
Pre: None
Post: The amount of money that the tailor has is returned. 
*/

/*
Description: The getLoc function is an accessor that returns the location
of the tailor. 
Pre: None
Post: The locaiton of the tailor is returned. 
*/

/*
Description: The removeMoney function removes the passed amount
of money from the tailor.
Pre: None
Post: The tailor's money is changed to the new value.
*/

/*
Description: The removeHealth function removes the passed
amount of health from the tailor.
Pre: None
Post: The tailor's health is changed to the new value.
*/

/*
Description: The setIsAlive function passes a bool to set
the tailor to being either alive or not. 
Pre: None
Post: The tailor is set to being alive or not. 
*/

/*
Description: The getIsAlive function is an accessor that returns
if the tailor is alive or not.
Pre: None
Post: Whether the tailor is alive or not.
*/

/*
Description: The getPantTotal function is an accessor that returns
the amount of pants the tailor has.
Pre: None
Post: The pant amount that the tailor has.
*/


// Forward declare
class Town;
class Bully;

class Tailor
{
  public:
    Tailor(const string name, const char icon = TAILOR_ICON);
    friend ostream & operator <<(ostream & os, Tailor & tailor); // overload
    void placeMe(Town & town);
    void randWalk(Town & town, Bully & bully);
    bool move(Town & town, const int x, const int y);
    void removeMoney(const int amt);
    void removeHealth(const int amt);
    void setIsAlive(const bool isAlive) { m_isAlive = isAlive; return; }
    float getMoney() const { return m_money; }
    Location getLoc() const { return m_loc; }    
    bool getIsAlive() const { return m_isAlive; }
    short getPantTotal() const { return m_pantTotal; }
  
  private:
    string m_name;
    char m_icon;
    float m_money;
    bool m_isAlive;
    Location m_loc;
    short m_health; // 0-100, 0 = death
    short m_pantTotal;
};

#endif
