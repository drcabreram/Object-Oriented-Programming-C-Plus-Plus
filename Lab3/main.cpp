#include <iostream>
#include "RPG.h"

using namespace std;

void gameLoop(RPG* p1, RPG* p2);
void displayStats(RPG* p1, RPG* p2);
void displayEnd(RPG p1, RPG p2);

int main() {
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();
    p2.setSkills();
    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
}

void gameLoop(RPG* p1, RPG* p2) {
    p1->setSkills();
    p2->setSkills();

    while (p1->isAlive() && p2->isAlive()) {
        cout << p1->getName() << "'s turn" << endl;
        displayStats(p1, p2);
        p1->useSkill(p2);
        if (!p2->isAlive()) break;

        cout << "===========================" << endl;

        cout << p2->getName() << "'s turn" << endl;
        displayStats(p1, p2);
        p2->useSkill(p1);

        cout << "===========================" << endl;
    }
}

void displayStats(RPG* p1, RPG* p2) {
    cout << p1->getName() << " HP: " << p1->getHealth()
        << " | " << p2->getName() << " HP: " << p2->getHealth() << endl;
}

void displayEnd(RPG p1, RPG p2) {
    if (p1.isAlive())
        cout << p1.getName() << " defeated " << p2.getName() << "....p1 wins" << endl;
    else
        cout << p2.getName() << " defeated " << p1.getName() << "....p2 wins" << endl;
}
