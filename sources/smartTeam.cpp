#include "smartTeam.hpp"
#include <limits>

namespace ariel {

    SmartTeam::SmartTeam(Character* player) : Team(player) {
    }

    SmartTeam::~SmartTeam() {
        for (Character* character : teammates) {
            delete character;
        }
        teammates.clear();
    }

    void SmartTeam::add(Character* player) {
        if (player->getStat())
            throw std::runtime_error("ERROR: character already in another team");
        if (capacity < MAX) {
            teammates.push_back(player);
            capacity++;
            player->setStat(true);

            if (auto* cowboy = dynamic_cast<Cowboy*>(player)) {
                //
            } else if (auto* ninja = dynamic_cast<Ninja*>(player)) {
                //
            } else {
                std::cout << "Invalid Character type: " << typeid(*player).name()
                          << ", name: " << player->getName() << "\n";
                throw std::runtime_error("Invalid Character type!\n");
            }
        } else {
            throw std::runtime_error("ERROR: Team is full!");
        }
    }

    void SmartTeam::attack(Team* foe) {
        if (foe == nullptr) {
            throw std::invalid_argument("Invalid argument pointer");
        }
        if (foe->stillAlive() <= 0) {
            throw std::runtime_error("ERROR: cannot attack dead team");
        }

        // Separate cowboys and ninjas
        std::vector<Cowboy*> cowboys;
        std::vector<Ninja*> ninjas;
        for (Character* character : teammates) {
            if (auto* cowboy = dynamic_cast<Cowboy*>(character)) {
                cowboys.push_back(cowboy);
            } else if (auto* ninja = dynamic_cast<Ninja*>(character)) {
                ninjas.push_back(ninja);
            }
        }

        // Attack cowboys first
        for (Cowboy* cowboy : cowboys) {
            if (cowboy->isAlive() && foe->stillAlive() > 0) {
                Character* victim = closeToo(cowboy, foe->getTeam());
                if (cowboy->hasboolets()) {
                    cowboy->shoot(victim);
                } else {
                    cowboy->reload();
                }
            } else {
                return;
            }
        }

        // Attack ninjas
        for (Ninja* ninja : ninjas) {
            if (ninja->isAlive() && foe->stillAlive() > 0) {
                Character* victim = closeToo(ninja, foe->getTeam());
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

} // namespace ariel
