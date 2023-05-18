
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


namespace ariel {


    Ninja::Ninja( int speed, string name,int hp, Point pos) :speed(speed), Character(hp, name, pos){};

    void Ninja::slash(Character *enemy) {};

    void Ninja::move(Character *enemy) {};


    // printing
    int Ninja::getSpeed() {
        return this->speed;
    };

    string Ninja::print() { return ""; };
}