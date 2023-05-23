#include "Character.hpp"
#include <iostream>

using namespace std;
 namespace ariel {


     Character::Character(int hp, string _name, Point p) : HP(hp), name(_name), pos(p) {
     };

     Character::~Character() {
     }



     bool Character::isAlive() {
         if (HP>0 )return true;
         return false;
     }




     double Character::distance(Character *player) {
         return this->getLocation().distance(player->getLocation());
     }

     void Character::hit(int dmg) {
         if(dmg<0 ){
             throw std::invalid_argument  ("ERROR: damage cannot be negative");
             return;
         }
        HP -=dmg;


     }

     string Character::getName() {
         return name;
     }

     Point Character::getLocation() {
        Point p(pos);
        return p;
     }


     string Character::print() {
         string s="";
         (isAlive())?s.append("name:"+name):s.append("name: ("+name+")");
         (isAlive())?s.append("\nHP:"+ to_string(HP)):"";
         s.append("\nPosition:"+getLocation().toString());

        return s;
     }



     void Character::setName(std::string s) {
         name = s;
     }
     int Character::getHP() {
         return max(HP,0);
     }
 }