#include "Team.hpp"
#include <iostream>
#include "Character.hpp"

using namespace std;
using namespace ariel;


Team::Team(Character* player) {
    add(player);
}

Team::~Team() {
}

void Team::add(Character* player) {
    // Add the player to the team
    // Implementation goes here
}

void Team::attack(Team* team) {
    // Perform the attack on the specified team
    // Implementation goes here
}

int Team::stillAlive() {
    // Check if the team is still alive
    // Implementation goes here
    return 0;
}

void Team::print() {
    // Print the team's information
    // Implementation goes here
}
