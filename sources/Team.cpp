#include "Team.hpp"
#include <iostream>

#include <limits>


using namespace std;
namespace ariel {


    void Team::attack(Team *foe) {
        if (foe == nullptr) {
            throw std::invalid_argument("Invalid argument pointer");
        }
        if (foe->stillAlive() <= 0) {
            throw std::runtime_error("Dead team");
        }

        attackWithCowboys(foe);
        attackWithNinjas(foe);
    }

    void Team::attackWithCowboys(Team *foe) {
        for (auto chr = teammates.begin(); chr != teammates.end(); ++chr) {
            if ((*chr)->isAlive()) {
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(*chr)) {
                    if (foe->stillAlive() > 0) {
                        Character *victim = closeToo(captain, foe->getTeam());
                        if (captain->isAlive() <= 0) {
                            this->captain = closeToo(captain, getTeam());
                        }

                        if (cowboy->hasboolets()) {
                            cowboy->shoot(victim);
                        } else {
                            cowboy->reload();
                        }
                    } else {
                        return;
                    }
                }
            }
        }
    }

    void Team::attackWithNinjas(Team *foe) {
        for (auto chr = teammates.begin(); chr != teammates.end(); ++chr) {
            if ((*chr)->isAlive()) {
                if (Ninja *ninja = dynamic_cast<Ninja *>(*chr)) {
                    if (foe->stillAlive() > 0) {
                        Character *victim = closeToo(captain, foe->getTeam());
                        if (captain->isAlive() <= 0) {
                            this->captain = closeToo(captain, getTeam());
                        }

                        if (ninja->distance(victim) < 1) {
                            ninja->slash(victim);
                        } else {
                            ninja->move(victim);
                        }
                    } else {
                        return;
                    }
                }
            }
        }
    }



    //---------------------------------------------
    Team::Team(Character *cap) {
        if (cap->getStat()) throw runtime_error("ERROR: character allready in team");
        if (cap == nullptr)throw runtime_error("ERROR : cannot initiate teammates with null captain\n");
        teammates.reserve(10);
        captain = cap;
        cap->setStat(true);
        teammates.push_back(cap);
        capacity++;
    }


    Team::~Team() = default;



    Team::Team(Team &other) : captain(nullptr), capacity(0) {
        captain = other.captain;

        for (Character *character: other.teammates) {
            if (auto *cowboy = dynamic_cast< Cowboy *>(character)) {
                auto *newCowboy = new Cowboy(*cowboy);
                teammates.push_back(newCowboy);
                capacity++;
            } else if (auto *ninja = dynamic_cast< Ninja *>(character)) {
                auto *newNinja = new Ninja(*ninja);
                teammates.push_back(newNinja);
                capacity++;
            }
        }
    }


    Character *Team::closeToo(Character *player, vector<Character *> team) {
        if (player == nullptr)return nullptr;
        Character *temp;
        double dist = numeric_limits<double>::max();

        for (Character *chr: team) {

            if (player->distance(chr) < dist && chr->isAlive()) {
                temp = chr;
                dist = player->distance(chr);
            }
        }
        return temp;
    }






    void Team::add(Character *player) {
        if (player->getStat()) throw runtime_error("ERROR: character already in other team");
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
