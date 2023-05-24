#include "Team2.hpp"

#include <limits>

using namespace std;

namespace ariel {

    Team2::Team2(Character *player) : Team(player) {

    }


    Team2::~Team2() {
        for (Character *character: teammates) {
            delete character;
        }
        teammates.clear();
    }

    void Team2::add(ariel::Character *player) {
        if (player->getStat()) throw runtime_error("ERROR: character already in other team");
        if (capacity < MAX) {
            teammates.push_back(player);
            capacity++;
            player->setStat(true);

            if (auto *cowboy = dynamic_cast<Cowboy *>(player)) {
//
            } else if (auto *ninja = dynamic_cast<Ninja *>(player)) {
//
            } else {
                cout << "Invalid Character type: " << typeid(*player).name() << ", name: " << player->getName()
                     << "\n";
                throw runtime_error("Invalid Character type!\n");
            }
        } else {
            throw runtime_error("ERROR: Team is full!");
        }
    }


    int Team2::stillAlive() {

        int count = 0;

        for (Character *a: this->teammates) {

            if (a->isAlive())
                count++;
        }
        return count;
    }

    void Team2::print() {
        for (Character *character: teammates) {
            character->print();
        }
    }






    void Team2::attack(Team* foe) {
        if (foe == nullptr) {
            throw std::invalid_argument("Invalid argument pointer");
        }
        if (foe->stillAlive() <= 0) {
            throw std::runtime_error("ERROR: cannot attack dead team");
        }

        for (auto chr = teammates.begin(); chr != teammates.end(); ++chr) {
            if ((*chr)->isAlive()) {
                if (foe->stillAlive() > 0) {
                    Character* victim = closeToo(captain, foe->getTeam());
                    if (captain->isAlive() <= 0) {
                        this->captain = closeToo(captain, getTeam());
                    }

                    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(*chr)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(victim);
                        } else {
                            cowboy->reload();
                        }
                    } else if (Ninja* ninja = dynamic_cast<Ninja*>(*chr)) {
                        if (ninja->distance(victim) < 1) {
                            ninja->slash(victim);
                        } else {
                            ninja->move(victim);
                        }
                    }
                } else {
                    return;
                }
            }
        }
    }



} // namespace ariel
