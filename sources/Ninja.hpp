#include "Character.hpp"
#pragma once
namespace ariel {
    class Ninja : public Character {


    private:
        int speed;


    public:

        Ninja(int speed, string name, int HP, Point pos);

        void move(Character* c);

        // return dealt damage or -1 in case of failure
        void slash(Character* c);

        int getSpeed();
        string print();

    };


}