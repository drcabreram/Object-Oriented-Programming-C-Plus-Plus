#ifndef RPG_H
#define RPG_H

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
public:
    RPG();
    RPG(string name, int health, int strength, int defense, string type);
    void setSkills();
    void printAction(string, RPG);
    void updateHealth(int);
    void attack(RPG*);
    void useSkill(RPG*);
    void useSkill(RPG*, int skillIndex);
    bool isAlive() const;
    string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    void printSkills() const;

private:
    string name;
    int health;
    int strength;
    int defense;
    string type;
    string skills[SKILL_SIZE];
};

#endif
