#include <iostream>
#include "RPG.h"

using namespace std;

int main() {

    RPG defaultCharacter;


    RPG customCharacter("Hero", 120, 15, 12, "mage");


    cout << "Default Character: " << defaultCharacter.getName() << endl;
    cout << "Health: " << defaultCharacter.getHealth() << endl;
    cout << "Strength: " << defaultCharacter.getStrength() << endl;
    cout << "Defense: " << defaultCharacter.getDefense() << endl;
    cout << "Is Alive? " << (defaultCharacter.isAlive() ? "Yes" : "No") << endl;

    cout << "\nCustom Character: " << customCharacter.getName() << endl;
    cout << "Health: " << customCharacter.getHealth() << endl;
    cout << "Strength: " << customCharacter.getStrength() << endl;
    cout << "Defense: " << customCharacter.getDefense() << endl;
    cout << "Is Alive? " << (customCharacter.isAlive() ? "Yes" : "No") << endl;


    cout << "\nUpdating default character's health to 0...\n";
    defaultCharacter.updateHealth(0);
    cout << "Health after update: " << defaultCharacter.getHealth() << endl;
    cout << "Is Alive after update? " << (defaultCharacter.isAlive() ? "Yes" : "No") << endl;

    return 0;
}
