#include <iostream>
#include "RPG.h"

RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "Slash";
    skills[1] = "parry";
}

RPG::RPG(string n, int h, int s, int d, string t) {
    name = n;
    health = h;
    strength = s;
    defense = d;
    type = t;
    skills[0] = "";
    skills[1] = "";
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

void RPG::printAction(string action, RPG target) {
    cout << name << " used " << action << " on " << target.getName() << endl;
}

void RPG::updateHealth(int value) {
    health += value;
    if (health < 0) health = 0;
}

void RPG::attack(RPG* enemy) {
    int damage = strength - enemy->getDefense();
    if (damage < 0) damage = 0;
    enemy->updateHealth(-damage);
    cout << enemy->getName() << " loses " << damage << " HP." << endl;
}

void RPG::useSkill(RPG* opponent) {
    for (int i = 0; i < SKILL_SIZE; ++i) {
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    int chosen_skill_index;
    cout << "Choose a skill to use: Enter 0 or 1" << endl;
    cin >> chosen_skill_index;

    if (chosen_skill_index < 0 || chosen_skill_index >= SKILL_SIZE) {
        cout << "Invalid input. Defaulting to skill 0." << endl;
        chosen_skill_index = 0;
    }

    string chosen_skill = skills[chosen_skill_index];
    printAction(chosen_skill, *opponent);
    attack(opponent);
}

void RPG::useSkill(RPG* opponent, int skillIndex) {
    if (skillIndex < 0 || skillIndex >= SKILL_SIZE) skillIndex = 0;
    printAction(skills[skillIndex], *opponent);
    int skillDamage = strength * 1.5 - opponent->getDefense();
    if (skillDamage < 0) skillDamage = 0;
    opponent->updateHealth(-skillDamage);
    cout << opponent->getName() << " loses " << skillDamage << " HP from skill!" << endl;
}

bool RPG::isAlive() const {
    return health > 0;
}

string RPG::getName() const { return name; }
int RPG::getHealth() const { return health; }
int RPG::getStrength() const { return strength; }
int RPG::getDefense() const { return defense; }

void RPG::printSkills() const {
    for (int i = 0; i < SKILL_SIZE; ++i) {
        cout << "Skill " << i << ": " << skills[i] << endl;
    }
}
