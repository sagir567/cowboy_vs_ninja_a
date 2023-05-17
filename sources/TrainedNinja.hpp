#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel{


class TrainedNinja: public Character
{
private:
    int speed;
    Character character;
public:
    TrainedNinja(string name, Point point);
    ~TrainedNinja();
    void move(Character*);
    void slash(Character*); 
};








}
#endif