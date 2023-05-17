#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel{


class OldNinja: public Character
{
private:
    int speed;
    Character character;
public:
    OldNinja(string name, Point point);
    ~OldNinja();

    void move(Character*);
    void slash(Character*);


};








}



#endif