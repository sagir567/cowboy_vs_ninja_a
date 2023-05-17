#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;



Character::Character(/* args */)
{
}

Character::~Character()
{
}



bool Character:: isAlive(){
    return true;
}
double Character:: distance(Character* player){
    return 2.0;
}
void Character:: hit(int hit){

}
string Character:: getName(){
    return "matan";
}
Point Character:: getLocation(){
    return Point(2.0,3.0);
}


string Character:: print(){
    return "matan brimer";
}

bool Character:: hasboolets(){
    return true;
}