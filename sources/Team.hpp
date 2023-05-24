#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include <limits.h>

#define MAX 10

using namespace std;
namespace ariel {

    class Team {
    protected:


        Character* captain;
        vector<Character*> teammates;

    public:
        int capacity = 0;

        Team(Character*);
        ~Team();
        Team(const Team& other);

        virtual void add(Character* c);

        virtual void attack(Team* foe);

        virtual int stillAlive();

        virtual void print();
       virtual Character* findVictim(Character *CapFoe);

        virtual Character *replaceCap();

        virtual  Character *getCap();


    };

} // namespace ariel

#endif
