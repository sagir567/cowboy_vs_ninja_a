#include "Team.hpp"
#include <iostream>


using namespace std;
 namespace ariel {


     Team::Team(Character *cap) : Team_I(cap) {
         this->add(cap);
     }

     Team::~Team() {
     }

     void Team::add(Character *player) {
         // Add the player to the team
         // Implementation goes here
     }

     void Team::attack(Team_I *foes) {
         // Perform the attack on the specified team
         // Implementation goes here
     }

     int Team::stillAlive() {
         // Check if the team is still alive
         // Implementation goes here
         return 0;
     }

     void Team::print() {
         // Print the team's information
         // Implementation goes here
     }
 }