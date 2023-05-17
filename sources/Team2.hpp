#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel{
    

class Team2: public Team  //Cowboy,OldNinja,TrainedNinja,YoungNinja
{
private:
    Character warriors[10];
    Character *leader[2];

public:
    Team2(Character*);
    ~Team2();
    void add(Character*);
    void attack(Team2*);
    int stillAlive();
    void print();
};





}

#endif