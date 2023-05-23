#include "Team.hpp"
#include <iostream>

#include <limits>


using namespace std;
 namespace ariel {


     Team::Team(Character *cap) {
         if(cap->getStat()) throw runtime_error ("ERROR: character allready in team");
         if (cap == nullptr)throw runtime_error("ERROR : cannot initiate teammates with null captain\n");
         teammates.reserve(10);
         captain = cap;
         cap->setStat(true);
         teammates.push_back(cap);
         capacity++;
     }


     Team::~Team() = default;


     Character *Team::findVictim(Character *captainFoes) {

         if (captainFoes == nullptr)
             throw runtime_error("Error: foe captain is null\n");
         else {
             Character *vict = nullptr;
             double dist = numeric_limits<double>::max(); // Use double for dist

             // Find a victim among cowboys
             for (Character *character: teammates) {
                 auto *cowboy = dynamic_cast<Cowboy *>(character);
                 if (cowboy != nullptr && cowboy->isAlive()) {
                     if (cowboy->distance(captainFoes) < dist) {
                         vict = cowboy;
                         dist = cowboy->distance(captainFoes); // Update dist
                     }
                 }
             }

             // Find a victim among ninjas
             for (Character *character: teammates) {
                 auto *ninja = dynamic_cast<Ninja *>(character);
                 if (ninja != nullptr && ninja->isAlive()) {
                     if (ninja->distance(captainFoes) < dist) {
                         vict = ninja;
                         dist = ninja->distance(captainFoes); // Update dist
                     }
                 }
             }

             if (vict == nullptr) {
                 cout << "Victory!!!\n";
             }
             return vict;
         }
     }


     Team::Team(const Team &other) : captain(nullptr), capacity(0) {
         captain = other.captain;

         for (const Character *character: other.teammates) {
             if (const auto *cowboy = dynamic_cast<const Cowboy *>(character)) {
                 auto *newCowboy = new Cowboy(*cowboy);
                 teammates.push_back(newCowboy);
                 capacity++;
             } else if (const auto *ninja = dynamic_cast<const Ninja *>(character)) {
                 auto *newNinja = new Ninja(*ninja);
                 teammates.push_back(newNinja);
                 capacity++;
             }
         }
     }


     Character *Team::getCap() {
         if (stillAlive() == 0) {
             cout << "captain is dead";
             return nullptr;
         }
         if (captain == nullptr) {
             return nullptr;
         }
         if (!(captain->isAlive()) && stillAlive() == 0) {
             cout << "teammates hase lost !!! \nnone characters left alive \n";
             return nullptr;
         } else if (!captain->isAlive() && stillAlive() > 0) {
             captain = replaceCap();

         }

         return captain;
     }

     Character *Team::replaceCap() {
         if (captain->isAlive())
             return captain;

         Character *newCap = nullptr;
         double dist = numeric_limits<double>::max();

         // Replace captain with the closest living cowboy
         for (Character *teammate: teammates) {
             if (auto *cowboy = dynamic_cast<Cowboy *>(teammate)) {
                 if (captain->distance(cowboy) < dist && cowboy->isAlive()) {
                     newCap = cowboy;
                     dist = captain->distance(cowboy);
                 }
             }
         }

         // Replace captain with the closest living ninja
         for (Character *teammate: teammates) {
             if (auto *ninja = dynamic_cast<Ninja *>(teammate)) {
                 if (captain->distance(ninja) < dist && ninja->isAlive()) {
                     newCap = ninja;
                     dist = captain->distance(ninja);
                 }
             }
         }
            this->captain =newCap;
         return newCap;
     }

     void Team::add(Character *player) {
         if(player->getStat()) throw runtime_error ("ERROR: character already in other team");
         if (capacity < MAX) {
             teammates.push_back(player);
             capacity++;
             player->setStat(true);

             if (auto *cowboy = dynamic_cast<Cowboy *>(player)) {
//                 cout << cowboy->getName() << " joined the team!!!\n";
             } else if (auto *ninja = dynamic_cast<Ninja *>(player)) {
//                 cout << ninja->getName() << " joined the team!!!\n";
             } else {
                 cout << "Invalid Character type: " << typeid(*player).name() << ", name: " << player->getName()
                      << "\n";
                 throw runtime_error("Invalid Character type!\n");
             }
         } else {
             throw runtime_error("ERROR: Team is full!");
         }
     }


     void Team::attack(Team *foes) {

         if(foes == nullptr ) throw invalid_argument ("ERROR: enemy team is null");
         if(foes->stillAlive()==0) throw runtime_error ("ERROR:cannot attack dead team");
         Character *cap = getCap();
         Character *victim;

         if (cap == nullptr) {

             cap = replaceCap();
             if(cap== nullptr) return;
             if(!cap ->isAlive()) return;
         }

         for (Character *teammate: teammates) {
             if (auto *cowboy = dynamic_cast<Cowboy *>(teammate)) {
                 victim = foes->findVictim(cap);
                 if (victim == nullptr) {
                     cout << "Enemy teammates eliminated!!\n";
                     return;
                 } else  if(cowboy->isAlive()){
                     cowboy->shoot(victim);
                 }
             } else if (auto *ninja = dynamic_cast<Ninja *>(teammate)) {
                 victim = foes->findVictim(cap);
                 if (victim == nullptr) {
                     cout << "Enemy teammates eliminated!!\n";
                     return;
                 } else if ((ninja->distance(victim) < 1 )&& ninja->isAlive()) {
                     ninja->slash(victim);
                 } else if(ninja->isAlive()){
                     ninja->move(victim);
                 }
             }
         }
     }


     int Team::stillAlive() {

         int count = 0;
         for (Character *character: teammates) {
             auto *cowboy = dynamic_cast<Cowboy *>(character);
             if (cowboy != nullptr && cowboy->isAlive()) {
                 count++;
             }
         }
         for (Character *character: teammates) {
             auto *ninja = dynamic_cast<Ninja *>(character);
             if (ninja != nullptr && ninja->isAlive()) {
                 count++;
             }
         }
         return count;
     }

     void Team::print() {
         for (Character *character: teammates) {
             auto *cowboy = dynamic_cast<Cowboy *>(character);
             if (cowboy != nullptr) {
                 cowboy->print();
             }
         }
         for (Character *character: teammates) {
             auto *ninja = dynamic_cast<Ninja *>(character);
             if (ninja != nullptr) {
                 ninja->print();
             }
         }
     }
 }
