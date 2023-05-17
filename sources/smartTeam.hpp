#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel{
    

class smartTeam: public Team  //Cowboy,OldNinja,TrainedNinja,YoungNinja
{
private:
    Character warriors[10];
    Character *leader[2];

public:
    smartTeam(Character*);
    ~smartTeam();
    void add(Character*);
    void attack(smartTeam*);
    int stillAlive();
    void print();
};






}

#endif