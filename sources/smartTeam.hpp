#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

namespace ariel {

    class SmartTeam : public Team {
    public:
        SmartTeam(Character* player);
        ~SmartTeam();

        void add(Character* player) override;
        void attack(Team* foe) override;
    };

} // namespace ariel

#endif // SMARTTEAM_HPP
