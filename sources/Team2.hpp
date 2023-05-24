#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"
#include <vector>

#define MAX 10

using namespace std;

namespace ariel {

    class Team2 : public Team {
    private:


    public:
         Team2( Character *player);
        Team2(const Team &other1);
        void add(Character* c) override;
        ~Team2();
        void attack(Team* foes) override;
        int stillAlive() override;
        void print() override;
        Character* replaceCap() override;
        Character* findVictim(Character* captainFoes) override;



    };

} // namespace ariel

#endif
