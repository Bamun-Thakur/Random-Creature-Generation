#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature {
public:
    // Attributes
    string name;
    int strength;
    int intelligence;
    int speed;
    string species;

    // Constructor
    Creature(string creatureName, string creatureSpecies) {
        name = creatureName;
        species = creatureSpecies;
        strength = rand() % 101;      // Random strength between 0-100
        intelligence = rand() % 101;  // Random intelligence between 0-100
        speed = rand() % 101;         // Random speed between 0-100
    }

    // Method to display creature's traits
    void displayTraits() {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Strength: " << strength << "/100" << endl;
        cout << "Intelligence: " << intelligence << "/100" << endl;
        cout << "Speed: " << speed << "/100" << endl;
    }
};

string getRandomSpecies() {
    string speciesList[] = {"Dragon", "Unicorn", "Griffin", "Phoenix", "Goblin"};
    int randomIndex = rand() % 5;
    return speciesList[randomIndex];
}

int main() {
    srand(time(0));  // Seed for random number generation

    string name;
    cout << "Enter the name of your creature: ";
    cin >> name;

    string species = getRandomSpecies();

    // Create the creature
    Creature newCreature(name, species);
    
    // Display the creature's traits
    cout << "\nYour creature has been created!\n";
    newCreature.displayTraits();

    return 0;
}