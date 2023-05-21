
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


namespace ariel {


    Ninja::Ninja( int speed, string name,int hp, Point pos) :speed(speed), Character(hp, name, pos){};

    void Ninja::slash(Character *foe) {
        if((Character::distance(foe))<=speed){
            foe->hit(40);
        }
        else {cout<<"foe is to far!!!\n";}

        // ninja cannot move farter then his speed each turn;
        // if foe is less than one meter then dealt 40 damage, else no damage dealt
    };

    void Ninja::move(Character *foe) {
        // should use Point move
        pos = this->moveTowards(pos, foe->getLocation(),speed);
        cout<< "new pos";
        pos.print();
    };


    // printing
    int Ninja::getSpeed() {
        return this->speed;
    };

    string Ninja::print() { return ""; };
}