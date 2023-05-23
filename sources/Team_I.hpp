#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "Ninja.hpp"

namespace ariel{
    class Team_I{


    private:
        Character* captain;

    protected:
        Character* getCap()const{
            return captain;
        }
    public:

        Team_I(Character* cap):captain(cap){};
        virtual ~Team_I()= default;
        virtual void print()=0;
        virtual int stillAlive()=0;
        virtual void attack(Team_I* foe)=0;
        virtual void add(Character* )=0;
        virtual  Character* getCap()=0;
        virtual  Character* replaceCap()=0;
        virtual Character* findVictim(Character* c)=0;
//        Team_I operator = (const Team_I) =default;
//        Team_I (const Team_I&) =default;
//        Team_I(Team_I&&)=default;
//        Team_I& operator=(Team_I&&)=default;




    };


}

