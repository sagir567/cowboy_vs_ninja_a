#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team_I.hpp"
#include <vector>

#define MAX 10

using namespace std;
namespace ariel{


    class Team2: public Team_I  //Cowboy,OldNinja,TrainedNinja,YoungNinja
    {
    private:
      vector<Character*> teammates;

    public:


        Team2(Character*);
        ~Team2();
        void add(Character* c) override;
        void attack(Team_I* foe) override;
        int stillAlive() override;
        void print()override;
//        ~Team2() override= default;
//        Team2(const Team2&) = delete;
//        Team2& operator=(const Team2&) = delete;
//        Team2(Team2&&) = delete;
//        Team2& operator=(Team2&&) = delete;
    };






}

#endif