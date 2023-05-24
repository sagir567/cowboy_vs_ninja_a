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


    Character *Team2::replaceCap() {
        return nullptr;
    }


    Character *Team2::findVictim(Character *captainFoes) {
        if (captainFoes == nullptr)
            throw runtime_error("Error: foe captain is null\n");
        else {
            Character *victim = nullptr;
            double dist = numeric_limits<double>::max();

            // Find a victim among team members
            for (Character *teammate: teammates) {
                if (teammate->isAlive() && teammate->distance(captainFoes) < dist) {
                    victim = teammate;
                    dist = teammate->distance(captainFoes);
                }
            }

            if (victim == nullptr) {
                cout << "Victory!!\n";
            }
            return victim;
        }
    }

    void Team2::attack(Team *foe) {
        if (foe == nullptr) {
            throw std::invalid_argument("Invalid argument pointer");

        }
        if (foe->stillAlive() > 0) {
            // Attack with Cowboys
            for (auto chr = teammates.begin(); chr != teammates.end(); ++chr) {
                if ((*chr)->isAlive() > 0) {

                    if (foe->stillAlive() > 0) {
                        attackT(*chr, foe);
                    } else {
                        return;
                    }

                }

            }

        } else {
            throw runtime_error("cannot attack dead team");
        }
    }


} // namespace ariel
