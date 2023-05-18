#pragma once
#include "Point.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

using namespace std;

namespace ariel{

    class Character:public Point
{
    protected:
    Point pos;
    int HP;
    string name;

public:
    Character(int HP, string name,Point pos);
    ~Character();


    void setName(string);
    bool isAlive();//Returns true/false if the character is alive
    double distance(Character*);//Returns the distance between the characters
    void hit(int);//Subtracts the appropriate amount of hit points from the character
    string getName();//Returns the name of the character.
    Point getLocation();//Returns the position of the character
    int getHP();// return HP amunt



    string print();

    bool hasBullets();//Indicates whether there are any bullets left in the morning's gun
    

};

}


#endif