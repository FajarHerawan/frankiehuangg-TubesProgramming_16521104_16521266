#ifndef __ROBOT_HPP__
#define __ROBOT_HPP__

#include <iostream>

using namespace std;

// STRUCT/CLASS
struct Coordinate
{
    int x,y;
};

class Character
{
public:
    int healthPoint;
    Coordinate position;

private:
    int attackDamage;
    int attackRange;

private:
    Coordinate enemyDistance(Character enemy);

public:
    Character();
    Character(int health, int damage, int range, Coordinate pos);
    void attackEnemy(Character enemy);
    void moveCharacter(Coordinate direction);
    void printStatus();
};


// VARIABLES
extern const int sizeX;
extern const int sizeY;
extern Coordinate U,D,L,R;


// FUNCTION
void printDistance(Character c1, Character c2);

void printMap(int sizeX, int sizeY, Coordinate c1, Coordinate c2);

#endif  //__ROBOT_HPP__
