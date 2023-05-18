#ifndef COWBOY_HPP
#define COWBOY_HPP
#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel{

class Cowboy: public Character
{
private:
    int ammo;//=6

public:
    Cowboy(string name, Point pos);
    ~Cowboy();

    bool hasboolets();
    void reload();
    void shoot(Character* c);
    string getName();
    string print();
};





}



#endif