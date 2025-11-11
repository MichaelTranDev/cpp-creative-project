#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <string>
using namespace std;

// Struct to store superhero information
struct Superhero {
    string name;
    string superpower;
    int age;
    int powerLevel;
};

// Function declarations
void addHero(Superhero heroes[], int &count);
void displayHero(Superhero heroes[], int count); // Display all heroes
void displayHero(Superhero heroes[], int count, int index); // Overloaded: display by index
void displayHero(Superhero heroes[], int count, string name); // Overloaded: display by name
int searchHero(Superhero heroes[], int count, string name); // Returns index or -1
void saveToFile(Superhero heroes[], int count, string filename);
void loadFromFile(Superhero heroes[], int &count, string filename);

#endif

