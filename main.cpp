/*
Programmer: Adam Hoffmeister & Charles Hasty
Instructor: Clayton Price
Section: 1A
Date: 4/16/2017
Description: "High-water business simulation in 2D"
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "town_header.h"
#include "tailor_header.h"
#include "bully_header.h"
#include <fstream>
using namespace std;

int main()
{
  int stepAmt = 0, bullyChoice;
  string intro_art;
  ifstream fin;
  
  fin.open("intro.txt");
  while(fin >> intro_art)
  {
    getline(fin, intro_art, 'p');
	cout << intro_art << endl;
  }
  
  // randomize seed
  srand(time(NULL));
  
  
  // create town
  Town town(TOWN_SIZE, HOUSE_AMT, BULLIES_AMT);
  cout << town;
  
  // create tailor
  Tailor tailor("Milhouse", 'M');
  tailor.placeMe(town);
  cout << tailor;
  
  // create bullies
  Bully bullies[4];
  
  do
  {
    stepAmt++;
    bullyChoice = rand() % BULLIES_AMT;
    
    tailor.randWalk(town, bullies[bullyChoice]);
    if (stepAmt < 35)
    {
      cout << tailor;
      cout << town;
    }
    usleep(500000);
  } while(tailor.getIsAlive() &&
      tailor.getPantTotal() > 0 &&
      stepAmt < MAX_STEPS);
  
  // final output
  cout << tailor;
  cout << town;
  
  return 0;
}
