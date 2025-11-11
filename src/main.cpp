#include <iostream>
#include "Superhero.h"
using namespace std;

int main() {
    Superhero heroes[100];
    int heroCount = 0;
    int choice;
    string filename = "heroes.txt";

    do {
        cout << "\n===== Superhero Database Manager =====\n";
        cout << "1. Add New Superhero\n";
        cout << "2. Display All Superheroes\n";
        cout << "3. Search Superhero by Name\n";
        cout << "4. Display Hero by Index\n";
        cout << "5. Save Database to File\n";
        cout << "6. Load Database from File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }
        cin.ignore(); // Clear newline

        switch(choice) {
            case 1:
                addHero(heroes, heroCount);
                break;
            case 2:
                displayHero(heroes, heroCount);
                break;
            case 3: {
                string name;
                cout << "Enter superhero name to search: ";
                getline(cin, name);
                displayHero(heroes, heroCount, name);
                break;
            }
            case 4: {
                int index;
                cout << "Enter hero index: ";
                if(!(cin >> index)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input!\n";
                    break;
                }
                displayHero(heroes, heroCount, index-1); // user-friendly index
                break;
            }
            case 5:
                saveToFile(heroes, heroCount, filename);
                break;
            case 6:
                loadFromFile(heroes, heroCount, filename);
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while(choice != 7);

    return 0;
}

