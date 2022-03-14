#include <iostream>
#include "robot.hpp"

using namespace std;

// Default constructor
Character::Character()
{
    this->healthPoint = 100;
    this->attackDamage = 10;
    this->attackRange = 5;
    this->position = {0,0};
}

// Parameterized constructor
Character::Character(int health, int damage, int range, Coordinate pos)
{
    this->healthPoint = health;
    this->attackDamage = damage;
    this->attackRange = range;
    this->position = pos;
}

// enemyDistance(enemy) is an object function, returns the (x,y) distance (struct) of an object to another object
Coordinate Character::enemyDistance(Character enemy)
{
    int xCoord, yCoord;

    if ((enemy.position.x-position.x) >= 0)
        xCoord = enemy.position.x-position.x;
    else
        xCoord = position.x-enemy.position.x;

    if ((enemy.position.y-position.y) >= 0)
        yCoord = enemy.position.y-position.y;
    else
        yCoord = position.x-enemy.position.y;

    return {xCoord, yCoord};
}

// attackEnemy(enemy) is a void object function, reduce enemy HP depending on the distance
void Character::attackEnemy(Character enemy)
{
    if ((enemyDistance(enemy).x+enemyDistance(enemy).y) <= 5)
    {
        enemy.healthPoint -= attackDamage;
        cout << "Enemy received " << attackDamage << " damage!" << endl;
    }

    else
    {
        cout << "Attack missed!" << endl;
    }
}

// moveCharacter(direction) is a void object function, change the object position based on the user input
void Character::moveCharacter(Coordinate direction)
{
    this->position.x += direction.x;
    this->position.y += direction.y;
}

// printStatus() is a void object function, print the object status
void Character::printStatus()
{
    cout << "HP\t: " << healthPoint << endl;
    cout << "Damage\t: " << attackDamage << endl;
    cout << "Range\t: " << attackRange << endl;
    cout << "Pos\t: " << '(' << position.x << ',' << position.y << ')' << endl << endl;
}

// printDistance is a void function, print the distance between 2 objects
void printDistance(Character c1, Character c2)
{
    cout << "Dist\t: (" << abs(c1.position.x-c2.position.x) << ',' << abs(c1.position.y-c2.position.y) << ')' << endl;
}

void printMap(int sizeX, int sizeY, Coordinate c1, Coordinate c2)
{
    for (int i=sizeX-1; i>=0; i--)
    {
        for (int j=0; j<sizeY; j++)
        {
            if (j == c1.x && i == c1.y)
                cout << 'R';
            if (j == c2.x && i == c2.y)
                cout << 'K';
            else
                cout << '.';
        }
        cout << endl;
    }
}
