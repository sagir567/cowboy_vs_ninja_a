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
        ammo =6;
     }

     void Cowboy::shoot(Character *c) {
    // if their ammo are not zero,  and cowboy is alive dealt 10 damage

    if(!isAlive()) return;
    if(!hasboolets()){
        cout<< "reloading...\n";
        reload();
        return;
    }
    ammo--;
    c->hit(10);


     }
     string Cowboy::print(){
         return "Cowboy";
     }

     string Cowboy::getName(){
         return Character::getName();
     }

 }