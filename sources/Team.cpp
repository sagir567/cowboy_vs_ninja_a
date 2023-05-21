#include "Team.hpp"
#include <iostream>
#include <typeinfo>

using namespace std;
 namespace ariel {


     Team::Team(Character *cap) : Team_I(cap) {
         this->add(cap);
         captain = cap;
     }

     Team::~Team() {
     }


     Character* Team::getCap() {
         if(captain == nullptr){
             throw runtime_error("ERROR captain is null!!!");
         }
         if (!(captain->isAlive()) && stillAlive()  == 0) {
            cout << "team hase lost !!! \nnone characters left alive ";
             return nullptr;
          }
         else if(!captain->isAlive() && stillAlive()>0) {
            captain =replaceCap();

         }
         return captain;
     }

     Character *Team::replaceCap() {
         if(captain->isAlive()) return captain;
         Character *newCap;
         int dist =0;
         for(Character *c:cowboys){
             if(captain->distance(c)>dist&& c->isAlive()) newCap = c;}
         for(Character *n:ninjas){
             if(captain->distance(n)>dist && n->isAlive()) newCap = n;}

         return newCap;
     }

     void Team::add(Character *player) {
         if (capacity <= 10) {
              if (Cowboy* cowboyPlayer = dynamic_cast<Cowboy*>(player)) {
                 // Player is of type Cowboy
                 cowboys.push_back(cowboyPlayer);
                 capacity++;
             }
              else if (Ninja* ninjaPlayer = dynamic_cast<Ninja*>(player)) {
                  ninjas.push_back(ninjaPlayer);
                  capacity++;
              }
             else{
                 cout << typeid(player).name();
                 throw runtime_error("invalid Character type!!!");
             }
         }
     }

     void Team::attack(Team_I *foes) {
         Character *foe = foes->getCap();
         if(foe == nullptr){
             cout << "VICOTRY!!!\n enemy team is dead ";
         }
         else {
             foe->print();
             for (Cowboy *c: cowboys) {
                 c->shoot(foe);
                 if(!foe->isAlive()) foes->replaceCap();
             }
             for (Ninja *n: ninjas) {
                 if(n->distance(foe) > 1){
                     n->slash(foe);
                     if(!foe->isAlive()) foes->replaceCap();
                 }
                 else{
                     n->move(foe);
                 }
             }

         }
     }

     int Team::stillAlive() {
         // Check if the team is still alive
         int count =0;
         for (Ninja *n :ninjas){
             if(n->isAlive()) count++;
         }
         for (Cowboy *c :cowboys){
             if(c->isAlive()) count++;
         }
         return count;
     }

     void Team::print() {
         // Print the team's information
         // Implementation goes here
     }
 };
