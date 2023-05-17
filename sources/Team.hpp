#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

using namespace std;
namespace ariel{
    

class Team: public Character  //Cowboy,OldNinja,TrainedNinja,YoungNinja
{
private:
    Character warriors[10];
    Character *leader[2];

public:
    Team(Character*);
    ~Team();
    void add(Character*);
    void attack(Team*);
    int stillAlive();
    void print();
};






}

#endif