#include "RPG.h"
#include <iostream>

using namespace std;


RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    setSkills();
}

RPG::RPG(string name, int health, int strength, int defense, string type) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();
}

void RPG::setSkills() {
    if (type == "mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    }
    else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    }
    else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    }
    else { 
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}


void RPG::printAction(string skill, RPG opponent) {
    cout << name << " uses " << skill << " on " << opponent.getName() << endl;
}

void RPG::updateHealth(int new_health) {
    health = new_health;
}

bool RPG::isAlive() const {
    return health > 0;
}
