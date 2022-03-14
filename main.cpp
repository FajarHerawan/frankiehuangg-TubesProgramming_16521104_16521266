#include <iostream>
#include "robot.hpp"

using namespace std;

int main()
{
    const int sizeX = 20;
    const int sizeY = 20;
    char input;
    Coordinate U = {0,1}, D = {0,-1}, L = {-1,0}, R = {1,0};

    Character Robot, BunshinMechaKurama(100,20,5,{20,20});

    cout << "Help URO Village defeat Mecha-Kurama!" << endl;

    while (Robot.healthPoint > 0)
    {
        printMap(sizeX, sizeY, Robot.position, BunshinMechaKurama.position);
        cout << "a) Attack (A)\nb) Move (M)\nc) Status (S)\nUser Input: ";
        cin >> input;
        if (input == 'A' || input == 'a')
        {
            Robot.attackEnemy(BunshinMechaKurama);
        }
        else if (input == 'M' || input == 'm')
        {
            cout << "a)Up (U)\nb)Down(D)\nc)Left (L)\nd)Right (R)\nMove direction: ";
            cin >> input;
            if (input == 'U' || 'u')
                Robot.moveCharacter(U);
            else if (input == 'D' || 'd')
                Robot.moveCharacter(D);
            else if (input == 'L' || 'l')
                Robot.moveCharacter(L);
            else if (input == 'R' || 'r')
                Robot.moveCharacter(R);
            else
                cout << "Please input a valid option!" << endl;
        }
        else if (input == 'S' || input == 's')
        {
            Robot.printStatus();
        }
        else
        {
            cout << "Please input a valid option!" << endl;
            continue;
        }
    }

    return 0;
}
