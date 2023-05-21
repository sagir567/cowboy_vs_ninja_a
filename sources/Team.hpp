#ifndef TEAM_HPP
#define TEAM_HPP

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
    

class Team: public virtual Team_I //Cowboy,OldNinja,TrainedNinja,YoungNinja
{
private:
    Character *captain;
    vector<Cowboy*> cowboys;
    vector<Ninja*> ninjas;


public:

    int capacity=0;
    Team(Character*);
    ~Team();
    void add(Character* c) override;
    void attack(Team_I* foe) override;
    int stillAlive() override;
    void print() override;
    Character* getCap() override;
    Character* replaceCap()override;

};






}

#endif