
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


namespace ariel {


    Ninja::Ninja( int speed, string name,int hp, Point pos) :speed(speed), Character(hp, name, pos){};

    void Ninja::slash(Character *foe) {
        // ninja cannot move farter then his speed each turn;
        // if foe is less then one meter then dealt 40 damage, else no demage dealt
    };

    void Ninja::move(Character *foe) {
        // should use Point move
        pos = this->moveTowards(this->getLocation(), foe->getLocation(),speed);
    };


    // printing
    int Ninja::getSpeed() {
        return this->speed;
    };

    string Ninja::print() { return ""; };
}