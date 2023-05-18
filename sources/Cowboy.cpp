#include "Cowboy.hpp"
#include <iostream>

using namespace std;
 namespace ariel {

     Cowboy::Cowboy(string name, Point pos): Character(110,name,pos),ammo (6){}

     Cowboy::~Cowboy() {
     }

     bool Cowboy::hasboolets() {
         return ammo >0;
     }

     void Cowboy::reload() {

     }

     void Cowboy::shoot(Character *) {

     }
     string Cowboy::print(){
         return "Cowboy";
     }

     string Cowboy::getName(){
         return Character::getName();
     }

 }