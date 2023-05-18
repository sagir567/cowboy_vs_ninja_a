#include "Character.hpp"
#include <iostream>

using namespace std;
 namespace ariel {


     Character::Character(int hp, string _name, Point p) : HP(hp), name(_name), pos(p) {
     };

     Character::~Character() {
     }



     bool Character::isAlive() {
         return HP>0;
     }

     double Character::distance(Character *player) {
         return 2.0;
     }

     void Character::hit(int hit) {
        HP -=hit;
     }

     string Character::getName() {
         return name;
     }

     Point Character::getLocation() {
         return pos;
     }


     string Character::print() {
         return "jonney";
     }



     void Character::setName(std::string s) {
         name = s;
     }
     int Character::getHP() {
         return HP;
     }
 }