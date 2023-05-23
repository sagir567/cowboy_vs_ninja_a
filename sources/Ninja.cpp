
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


namespace ariel {


    Ninja::Ninja( int speed, string name,int hp, Point pos) :speed(speed), Character(hp, name, pos){};

    void Ninja::slash(Character *foe) {
        if(foe == this) throw runtime_error ("ERROR: self harm will not be tolerated!!!!");
        if(!isAlive())throw runtime_error ("ERROR: dead characters cannot attack");
        if(!foe)throw runtime_error("ERROR : foe is null");
        if(!(foe->isAlive()))throw runtime_error("ERROR : foe is dead");
        if((Character::distance(foe))<=1){
            foe->hit(40);
        }
//        else {  cout<< name << " couldn't attack " << foe->getName() << " enemy is too far "<< "\n\n";}

        // ninja cannot move farter then his speed each turn;
        // if foe is less than one meter then dealt 40 damage, else no damage dealt
    };

    void Ninja::move(Character *foe) {
        // should use Point move
        pos = this->moveTowards(pos, foe->getLocation(),speed);
//        cout<< name << " moved to --> " << pos.toString()<< "\n\n";

    };


    // printing
    int Ninja::getSpeed() {
        return this->speed;
    };

    string Ninja::print() { return ""; };
}