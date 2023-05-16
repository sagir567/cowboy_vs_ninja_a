#ifndef COWBOY_HPP
#define COWBOY_HPP
#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel{

class Cowboy: public Character
{
private:
    int amount_of_balls;//=6
    Character character;
    
public:
    Cowboy(/* args */);
    ~Cowboy();

    bool hasboolets();
    void reload();


};





}



#endif