#include "Team2.hpp"

#include <limits>

using namespace std;

namespace ariel {

    Team2::Team2(Character* player) : Team(player) {
//        teammates.push_back(player);
//        player->setStat(true);
    }


    Team2::~Team2() {
        for (Character* character : teammates) {
            delete character;
        }
        teammates.clear();
    }

    void Team2::add(ariel::Character *player) {
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


    void Team2::attack(Team* foes) {
        if (foes == nullptr)
            throw invalid_argument("ERROR: enemy team is null");
        if(foes->stillAlive()==0) throw invalid_argument("ERROR:cannot attack dead team");

        Character* cap = getCap();
        Character* victim;

        if (cap == nullptr) {

            if(!(cap = replaceCap()))return;
            if(!cap ->isAlive())return;

        }

        for (Character* teammate : teammates) {
            if (auto* cowboy = dynamic_cast<Cowboy*>(teammate)) {
                victim = foes->findVictim(cap);
                if (victim == nullptr) {
                    cout << "Enemy teammates eliminated!!\n";
                    return;
                } else if(cowboy->isAlive()){
                    cowboy->shoot(victim);
                }
            } else if (auto* ninja = dynamic_cast<Ninja*>(teammate)) {
                victim = foes->findVictim(cap);
                if (victim == nullptr) {
                    cout << "Enemy teammates eliminated!!\n";
                    return;
                } else if ((ninja->distance(victim) < 1)&& ninja->isAlive()) {
                    ninja->slash(victim);
                } else {
                    ninja->move(victim);
                }
            }
        }
    }


    int Team2::stillAlive(){

        int count = 0;

        for (Character* a : this->teammates){

            if(a->isAlive())
                count++;
        }
        return count;
    }
    void Team2::print() {
        for (Character* character : teammates) {
            character->print();
        }
    }


    Character* Team2::replaceCap() {
        return nullptr;
    }

    Character* Team2::findVictim(Character* captainFoes) {
        if (captainFoes == nullptr)
            throw runtime_error("Error: foe captain is null\n");
        else {
            Character* victim = nullptr;
            double dist = numeric_limits<double>::max();

            // Find a victim among team members
            for (Character* teammate : teammates) {
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


    Team2::Team2(const Team &other1) : Team(other1) {

        }


} // namespace ariel
