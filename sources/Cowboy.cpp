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
         if(!isAlive())throw std::runtime_error ("ERROR:  Dead cowboy can not reload");
        ammo =6;
     }

     void Cowboy::shoot(Character *foe) {
    // if their ammo is not zero, and cowboy is alive dealt 10 damage
         if(foe == this) throw std::runtime_error("ERROR self damage");
         if(!isAlive())throw runtime_error ("ERROR: dead characters cannot attack");
         if(!foe)throw runtime_error("ERROR : foe is null");
         if(!foe->isAlive())throw runtime_error("ERROR : foe is dead");


    if(!hasboolets()){
//        cout<< "reloading...\n";
        reload();
        return;
    }
    ammo--;
    foe->hit(10);


     }
     string Cowboy::print(){
         return "Cowboy";
     }

     string Cowboy::getName(){
         return Character::getName();
     }

 }