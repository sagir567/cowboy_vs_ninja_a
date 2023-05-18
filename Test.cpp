#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include <cmath>
#include "sources/Team2.hpp"
#include "sources/Team_I.hpp"
#include "sources/Team.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"

using namespace ariel;
//constructors
TEST_CASE("Test 1: Cowboy Default Constructor") {
    Cowboy *c12 = new Cowboy("gandalf", Point(10,10));
    CHECK_NOTHROW(Cowboy *c1 = new Cowboy("gandalf", Point(10,10)));
    CHECK_NOTHROW(Cowboy *c2 = new Cowboy("gandalf", Point(10,10)));
    CHECK_EQ(c12->getName(),"gandalf");
    CHECK_EQ(c12->getLocation().getX(),10);
    CHECK_EQ(c12->getLocation().getY(),10);


}
TEST_CASE("Test 2: YoungNinja Default Constructor") {
 YoungNinja *n1 = new YoungNinja("sam", Point(5,5));
    CHECK_NOTHROW( YoungNinja *temp = new YoungNinja("sam", Point(5,5)));
    CHECK_EQ(n1->getLocation().getY(),5);
    CHECK_EQ(n1->getLocation().getX(),5);
    CHECK_EQ(n1->getName(),"sam");
    CHECK_EQ(n1->getSpeed(),14);
}

TEST_CASE("Test 3: OldNinja Default Constructor") {
    OldNinja *o1 = new OldNinja("bob", Point(7,7));
    CHECK_NOTHROW( OldNinja *temp = new OldNinja("bob", Point(7,7)));
    CHECK_EQ(o1->getLocation().getY(),7);
    CHECK_EQ(o1->getLocation().getX(),7);
    CHECK_EQ(o1->getName(),"bob");
    CHECK_EQ(o1->getSpeed(),8);
    CHECK(o1->isAlive());
}

TEST_CASE("Test 4: TrainedNinja Default Constructor") {
    TrainedNinja *t1 = new TrainedNinja("mike", Point(10,10));
    CHECK_NOTHROW( TrainedNinja *temp = new TrainedNinja("mike", Point(10,10)));
    CHECK_EQ(t1->getLocation().getY(),10);
    CHECK_EQ(t1->getLocation().getX(),10);
    CHECK_EQ(t1->getName(),"mike");
    CHECK_EQ(t1->getSpeed(),12);
    CHECK(t1->isAlive());
}
TEST_SUITE(" Point moveTowards function") {
    Point source(0, 0);
    Point dest(10, 10);

    TEST_CASE("Test 5: Moving towards a reachable point") {
        Point result = Point::moveTowards(source, dest, 20);
        CHECK_EQ(result.getX(), 10);
        CHECK_EQ(result.getY(), 10);
    }

    TEST_CASE("Test 6: Moving towards an unreachable point") {
        Point result = Point::moveTowards(source, dest, 5);
        // The result coordinates depend on how moveTowards function computes dx and dy.
        // Assuming dx and dy are meant to be proportional to maxDist, we can compute
        // expected coordinates based on triangle similarity:
        double expectedX = 0 + (10 - 0) * 5 / std::sqrt((10 - 0) * (10 - 0) + (10 - 0) * (10 - 0));
        double expectedY = 0 + (10 - 0) * 5 / std::sqrt((10 - 0) * (10 - 0) + (10 - 0) * (10 - 0));
        CHECK_EQ(result.getX(), expectedX);
        CHECK_EQ(result.getY(), expectedY);
    }

    TEST_CASE("Test 7: Moving towards a point at zero distance") {
        Point result = Point::moveTowards(source, source, 5);
        CHECK_EQ(result.getX(), 0);
        CHECK_EQ(result.getY(), 0);
    }

    TEST_CASE("TEST 8: teams members checking")
    {
        YoungNinja *n1 = new YoungNinja("ang", Point(5, 5));
        YoungNinja *n2 = new YoungNinja("kora", Point(5, 5));
        Team t_1(n1);
        t_1.add(new Cowboy("Hikari", Point(12, 16)));
        t_1.add(new Cowboy("hi", Point(31, 12)));
        Team t_2(n2);
        t_2.add(new Cowboy("y", Point(13, 17)));
        while (t_1.stillAlive() > 0 && t_2.stillAlive() > 0) {
            t_1.attack(&t_2);
            t_1.attack(&t_2);
        }
        CHECK_EQ(t_2.stillAlive(), 0);
        CHECK_GT(t_1.stillAlive(), 0);

    }

    TEST_CASE("Test 9: Character Default Constructor") {
        Character *c1 = new Character(100, "John", Point(2,2));
        CHECK_NOTHROW( Character *temp = new Character(100, "John", Point(2,2)));
        CHECK_EQ(c1->getLocation().getY(), 2);
        CHECK_EQ(c1->getLocation().getX(), 2);
        CHECK_EQ(c1->getName(), "John");
        CHECK(c1->isAlive());
    }

}
TEST_CASE("Test 10: Cowboy Default Constructor") {
    Cowboy *c1 = new Cowboy("Jake", Point(3,3));
    CHECK_NOTHROW( Cowboy *temp = new Cowboy("Jake", Point(3,3)));
    CHECK_EQ(c1->getLocation().getY(), 3);
    CHECK_EQ(c1->getLocation().getX(), 3);
    CHECK_EQ(c1->getName(), "Jake");
    CHECK(c1->isAlive());
    CHECK(c1->hasboolets());
}

TEST_SUITE(" Ninja slash function") {
    YoungNinja  *n1 = new YoungNinja("Ken", Point(1,1));
    Character *c1 = new Character(100, "John", Point(2,2));

    TEST_CASE("Test 11:Foe within reach") {
        n1->slash(c1);
        CHECK_EQ(c1->getHP(), 60);  // expect 40 damage
    }

    TEST_CASE("Test 12:Foe out of reach") {
        Character *c2 = new Character(100, "Jane", Point(20,20));
        n1->slash(c2);
        CHECK_EQ(c2->getHP(), 100);  // expect no damage
    }
    TEST_CASE("Test 13: Cowboy Shoot Method") {
        Cowboy *c1 = new Cowboy("Jake", Point(3,3));
        Character *target = new Character(100, "John", Point(4,4));
        c1->shoot(target);
        CHECK_EQ(target->getHP(), 90);
    }
    TEST_CASE("Test 14: Cowboy Reload Method") {
        Cowboy *c1 = new Cowboy("Jake", Point(3,3));
        for (int i = 0; i < 7; i++) {
            c1->shoot(new Character(100, "John", Point(4,4)));
        }
        CHECK(!c1->hasboolets());
        c1->reload();
        CHECK(c1->hasboolets());
    }

    TEST_CASE("Test 15: Cowboy Print Method") {
        Cowboy *c1 = new Cowboy("Jake", Point(3,3));
        CHECK_EQ(c1->print(), "Cowboy");
    }

    TEST_CASE("Test 16: Ninja Default Constructor") {
        Ninja *n1 = new Ninja(10, "Shinobi", 120, Point(1,1));
        CHECK_NOTHROW( Ninja *temp = new Ninja(10, "Shinobi", 120, Point(1,1)));
        CHECK_EQ(n1->getLocation().getY(), 1);
        CHECK_EQ(n1->getLocation().getX(), 1);
        CHECK_EQ(n1->getName(), "Shinobi");
        CHECK(n1->isAlive());
        CHECK_EQ(n1->getSpeed(), 10);
    }

TEST_SUITE("Ninja move and slash function") {
    Ninja  *n1 = new Ninja(10, "Shinobi", 120, Point(1,1));
    Character *c1 = new Character(100, "John", Point(10,10));
    Character *c2 = new Character(100, "Jane", Point(20,20));

    TEST_CASE("Test 17: Ninja move towards a character") {
        n1->move(c1);
        CHECK_EQ(n1->getLocation().getX(), 2);
        CHECK_EQ(n1->getLocation().getY(), 2);
    }

    TEST_CASE("Test 18: Foe within slash reach") {
        n1->slash(c1);
        CHECK_EQ(c1->getHP(), 60);  // expect 40 damage
    }

    TEST_CASE("Test 19: Foe out of slash reach") {
        n1->slash(c2);
        CHECK_EQ(c2->getHP(), 100);  // expect no damage
    }
}


TEST_CASE("Test 20: Team Constructor and add method") {
    Character *cap = new Character(100, "John", Point(10,10));
    Team *team = new Team(cap);
    CHECK_NOTHROW(Team *temp = new Team(cap));
    Character *player = new Character(90, "Jane", Point(5,5));
    team->add(player);
    // Assuming you have a size or count method for the team
    // CHECK_EQ(team->size(), 2);
}

TEST_CASE("Test 21: Team stillAlive method") {
    YoungNinja *cap = new YoungNinja("John", Point(10,10));
    Team *team = new Team(cap);
    CHECK_EQ(team->stillAlive(), 1);
    // Add another member
    team->add(new Cowboy("Jane", Point(5,5)));
    CHECK_EQ(team->stillAlive(), 2);
    // Assuming a mechanism for killing a team member
    // cap->receiveDamage(120);  // Assuming this would kill the character
    // CHECK_EQ(team->stillAlive(), 1);
}

}






