#include <iostream>
#include <fstream>
#include <limits>
#include "Superhero.h"
using namespace std;

// Adds a new superhero with input validation
void addHero(Superhero heroes[], int &count) {
    if(count >= 100) {
        cout << "Database full! Cannot add more heroes.\n";
        return;
    }

    Superhero h;
    cout << "Enter superhero name: ";
    getline(cin, h.name);

    cout << "Enter superpower: ";
    getline(cin, h.superpower);

    // Input validation for age
    while(true) {
        cout << "Enter age: ";
        if(cin >> h.age && h.age > 0) break;
        else {
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Input validation for power level
    while(true) {
        cout << "Enter power level (0-100): ";
        if(cin >> h.powerLevel && h.powerLevel >= 0 && h.powerLevel <= 100) break;
        else {
            cout << "Invalid input. Enter a number between 0 and 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(); // Clear newline
    heroes[count] = h;
    count++;
    cout << "Superhero added successfully!\n";
}

// Display all superheroes
void displayHero(Superhero heroes[], int count) {
    if(count == 0) {
        cout << "No superheroes in database.\n";
        return;
    }
    for(int i = 0; i < count; i++) {
        cout << "\nHero #" << i+1 << endl;
        cout << "Name: " << heroes[i].name << endl;
        cout << "Superpower: " << heroes[i].superpower << endl;
        cout << "Age: " << heroes[i].age << endl;
        cout << "Power Level: " << heroes[i].powerLevel << endl;
    }
}

// Overloaded: Display superhero by index
void displayHero(Superhero heroes[], int count, int index) {
    if(index < 0 || index >= count) {
        cout << "Invalid index!\n";
        return;
    }
    cout << "\nHero #" << index+1 << endl;
    cout << "Name: " << heroes[index].name << endl;
    cout << "Superpower: " << heroes[index].superpower << endl;
    cout << "Age: " << heroes[index].age << endl;
    cout << "Power Level: " << heroes[index].powerLevel << endl;
}

// Overloaded: Display superhero by name
void displayHero(Superhero heroes[], int count, string name) {
    int idx = searchHero(heroes, count, name);
    if(idx == -1) {
        cout << "Superhero not found!\n";
    } else {
        displayHero(heroes, count, idx);
    }
}

// Search superhero by name
int searchHero(Superhero heroes[], int count, string name) {
    for(int i = 0; i < count; i++) {
        if(heroes[i].name == name) return i;
    }
    return -1;
}

// Save superheroes to file
void saveToFile(Superhero heroes[], int count, string filename) {
    ofstream file(filename);
    if(!file) {
        cout << "Error opening file for writing!\n";
        return;
    }

    for(int i = 0; i < count; i++) {
        file << heroes[i].name << ","
             << heroes[i].superpower << ","
             << heroes[i].age << ","
             << heroes[i].powerLevel << endl;
    }
    file.close();
    cout << "Database saved to " << filename << endl;
}

// Load superheroes from file
void loadFromFile(Superhero heroes[], int &count, string filename) {
    ifstream file(filename);
    if(!file) {
        cout << "Error opening file for reading!\n";
        return;
    }

    count = 0;
    string line;
    while(getline(file, line) && count < 100) {
        size_t pos = 0;
        string token;
        string data[4];
        int i = 0;
        while((pos = line.find(',')) != string::npos && i < 3) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[3] = line;

        heroes[count].name = data[0];
        heroes[count].superpower = data[1];
        heroes[count].age = stoi(data[2]);
        heroes[count].powerLevel = stoi(data[3]);
        count++;
    }
    file.close();
    cout << "Database loaded from " << filename << endl;
}

