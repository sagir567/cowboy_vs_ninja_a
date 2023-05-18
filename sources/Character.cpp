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
    return "sagi";
}
Point Character:: getLocation(){
    return Point(2.0,3.0);
}


string Character:: print(){
    return "jonney";
}

bool Character:: hasBullets(){
    return true;
}
void Character::setName(std::string s) {
    name =s;
}