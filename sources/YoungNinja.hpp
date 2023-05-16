#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel{


class YoungNinja: public Character
{
private:
    int speed;
    Character character;
public:
    YoungNinja(/* args */);
    ~YoungNinja();
};

void move(Character*);
void slash();






}
#endif