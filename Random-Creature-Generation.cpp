#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature {
public:
    // Attributes
    string name;
    string species;
    int age;
    int healthPoints;
    int strength;
    int intelligence;
    int speed;
    string specialSkill;

    // Constructor
    Creature(string creatureName, string creatureSpecies, int creatureAge, int hp) {
        name = creatureName;
        species = creatureSpecies;
        age = creatureAge;
        healthPoints = hp;
        strength = rand() % 101;      // Random strength between 0-100
        intelligence = rand() % 101;  // Random intelligence between 0-100
        speed = rand() % 101;         // Random speed between 0-100
        specialSkill = getRandomSkill(); // Random skill for each creature
    }

    // Method to display creature's traits
    void displayTraits() {
        cout << "\n---- Creature Details ----\n";
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Age: " << age << " years\n";
        cout << "Health Points (HP): " << healthPoints << endl;
        cout << "Strength: " << strength << "/100" << endl;
        cout << "Intelligence: " << intelligence << "/100" << endl;
        cout << "Speed: " << speed << "/100" << endl;
        cout << "Special Skill: " << specialSkill << endl;
    }

    // Method to evolve the creature based on certain criteria
    void evolve() {
        if (age >= 10 || strength > 80) {
            cout << "\n*** Your creature is evolving! ***\n";
            strength += rand() % 21;  // Increase strength by 0-20
            intelligence += rand() % 21; // Increase intelligence by 0-20
            speed += rand() % 21;    // Increase speed by 0-20
            healthPoints += rand() % 51; // Increase health points by 0-50
            cout << name << " has evolved into a stronger form!\n";
        } else {
            cout << name << " does not meet the criteria for evolution yet.\n";
        }
    }

private:
    string getRandomSkill() {
        string skillList[] = {"Fire Breath", "Invisibility", "Lightning Speed", "Healing", "Mind Control"};
        int randomIndex = rand() % 5;
        return skillList[randomIndex];
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
    int age, hp;

    // Take user input for creature's name, age, and health points (HP)
    cout << "Enter the name of your creature: ";
    cin >> name;

    cout << "Enter the age of your creature: ";
    cin >> age;

    cout << "Enter the health points (HP) of your creature (0-100): ";
    cin >> hp;
    if (hp > 100) hp = 100;  // Ensure HP doesn't exceed 100

    // Randomly assign a species
    string species = getRandomSpecies();

    // Create the creature
    Creature newCreature(name, species, age, hp);
    
    // Display the creature's traits
    newCreature.displayTraits();

    // Ask if the user wants to evolve the creature
    char evolveChoice;
    cout << "\nDo you want to evolve your creature? (y/n): ";
    cin >> evolveChoice;

    if (evolveChoice == 'y' || evolveChoice == 'Y') {
        newCreature.evolve();
        newCreature.displayTraits(); // Show updated stats after evolution
    }

    return 0;
}
