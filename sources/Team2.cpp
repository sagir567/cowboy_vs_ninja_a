#include "Team2.hpp"
#include <iostream>
#include "Team_I.hpp"

using namespace std;
 namespace ariel {


     Team2::Team2(Character *player) : Team_I(player) {
     }

     Team2::~Team2() {
     }

     void Team2::add(Character *player) {
         this->teammates.push_back(player);

     }
     Character* Team2::getCap() {
         return nullptr;
     }
     Character* Team2::replaceCap(){
         return nullptr;
     }

     void Team2::attack(Team_I *foes) {

     }

     int Team2::stillAlive() {
         return 0;
     }

     void Team2::print() {

     }
 }