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
TEST_SUITE("Test 5: Point moveTowards function") {
    Point source(0,0);
    Point dest(10,10);

    TEST_CASE("Moving towards a reachable point"){
        Point result = Point::moveTowards(source, dest, 20);
        CHECK_EQ(result.getX(), 10);
        CHECK_EQ(result.getY(), 10);
    }

TEST_CASE("Moving towards an unreachable point"){
        Point result = Point::moveTowards(source, dest, 5);
        // The result coordinates depend on how moveTowards function computes dx and dy.
        // Assuming dx and dy are meant to be proportional to maxDist, we can compute
        // expected coordinates based on triangle similarity:
        double expectedX = 0 + (10-0) * 5 / std::sqrt((10-0)*(10-0) + (10-0)*(10-0));
        double expectedY = 0 + (10-0) * 5 / std::sqrt((10-0)*(10-0) + (10-0)*(10-0));
        CHECK_EQ(result.getX(), expectedX);
        CHECK_EQ(result.getY(), expectedY);
    }

TEST_CASE("Moving towards a point at zero distance") {
        Point result = Point::moveTowards(source, source, 5);
        CHECK_EQ(result.getX(), 0);
        CHECK_EQ(result.getY(), 0);
    }
}
TEST_CASE("TEST: teams members checking")
{
    Team t_1(al);
    t_1.add(new Cowboy("Hikari", Point(12,16)));
    t_1.add(new Cowboy("hi", Point(31,12)));
    Team t_2(noy);
    t_2.add(new Cowboy ("y", Point(13, 17)));
    while(t_1.stillAlive() > 0 && t_2.stillAlive() > 0)
    {
        t_1.attack(&t_2);
        t_1.attack(&t_2);
    }
    CHECK_EQ(t_2.stillAlive(), 0);
    CHECK_GT(t_1.stillAlive(), 0);

}


TEST_CASE("TEST: teams members checking")
{
    Cowboy *noy = new Cowboy("noy", Point(12, 11));
    Cowboy *al = new Cowboy("al", Point(12, 11));
    Team t_1(al);
    t_1.add(new Cowboy("Hikari", Point(12,16)));
    t_1.add(new Cowboy("hi", Point(31,12)));
    Team t_2(noy);
    t_2.add(new Cowboy ("y", Point(13, 17)));
    while(t_1.stillAlive() > 0 && t_2.stillAlive() > 0)
    {
        t_1.attack(&t_2);
        t_1.attack(&t_2);
    }
    CHECK_EQ(t_2.stillAlive(), 0);
    CHECK_GT(t_1.stillAlive(), 0);

}







//TEST_CASE("Test 2: Character Hit Method") {
//    Character character;
//    character.hit(5);
//    CHECK_EQ(character.isAlive(), false);
//}
//
//TEST_CASE("Test 3: Character Distance Method") {
//    Character character1;
//    Character character2;
//    character2.setX(3);
//    character2.setY(4);
//    CHECK_EQ(character1.distance(&character2), 5.0);
//}
//TEST_CASE("Test 4: Cowboy Default Constructor") {
//    Cowboy ben("Ben", Point(1, 1));
//    CHECK_EQ(ben.getName(), "Ben");
//    CHECK_EQ(ben.hasBullets(), true);
//}
//
//TEST_CASE("Test 5: Cowboy Shoot Method") {
//    Cowboy tom("Tom", Point(1, 1));
//    Character c2;
//    tom.shoot(&c2);
//    CHECK_EQ(c2.isAlive(), false);
//}
//
//TEST_CASE("Test 6: OldNinja Slash Method") {
//    OldNinja n("Ninja", Point(2, 2));
//    Character c;
//    n.slash(&c);
//    CHECK_EQ(c.isAlive(), false);
//}
//
//TEST_CASE("Test 7: Team Add Method") {
//    Character c;
//    Team team(&c);
//
//    CHECK_EQ(team.stillAlive(), 1);
//}
//
//TEST_CASE("Test 8: Team Attack Method") {
//    Character c1;
//    Character c2;
//    Team team1(&c1);
//    Team team2(&c2);
//    Character c3;
//    Character c4;
//    team1.add(&c3);
//    team2.add(&c4);
//    team1.attack(&team2);
//    CHECK_EQ(team2.stillAlive(), 0);
//}
//
//TEST_CASE("Test 9: Point Setters and Getters") {
//    Point p;
//    p.setX(5.0);
//    p.setY(10.0);
//    CHECK_EQ(p.getX(), 5.0);
//    CHECK_EQ(p.getY(), 10.0);
//}
//
//TEST_CASE("Test 10: Point Distance Method") {
//    Point p1(5.0, 10.0);
//    Point p2(10.0, 10.0);
//    CHECK_EQ(p1.distance(p2), 5.0);
//}
//TEST_CASE("Test 11: Character Hit Method with Damage") {
//    Point location(0, 0);
//    int life = 100;
//    string name = "Bond";
//    Character test;
//    int damage = 50;
//    test.hit(damage);
//    CHECK(test.isAlive() == true);
//}
//
//TEST_CASE("Test 12: Cowboy Shoot, Has Bullets, Reload") {
//    Point point1(2, 8);
//    Point point2(5, 8);
//    Cowboy player1("Rick", point1);
//    Cowboy player2("Morty", point2);
//    CHECK(player1.hasBullets());
//    while (player1.hasBullets()) {
//        player1.shoot(&player2);
//    }
//    CHECK_FALSE(player1.hasBullets());
//    player1.reload();
//    CHECK(player1.hasBullets());
//}
//
//TEST_CASE("Test 13: TrainedNinja Slash Method") {
//    TrainedNinja n("Ninja", Point(2, 2));
//    Character c;
//    n.slash(&c);
//    CHECK_EQ(c.isAlive(), false);
//}
//
//TEST_CASE("Test 14: YoungNinja Shoot Method") {
//    YoungNinja n("Ninja", Point(2, 2));
//    Character c;
//    n.shoot(&c);
//    CHECK_EQ(c.isAlive(), false);
//}
//
//TEST_CASE("Test 15: Character Name") {
//    Character c;
//    c.setName("John");
//    CHECK_EQ(c.getName(), "John");
//}
//
//TEST_CASE("Test 16: Point X and Y Coordinates") {
//    Point p;
//    p.setX(5.0);
//    p.setY(10.0);
//    CHECK_EQ(p.getX(), 5.0);
//    CHECK_EQ(p.getY(), 10.0);
//}
//
//TEST_CASE("Test 17: Cowboy Reload") {
//    Cowboy c("John", Point(1, 1));
//    c.reload();
//    CHECK_EQ(c.hasBullets(), true);
//}
//
//TEST_CASE("Test 18: Team Still Alive") {
//    Character c1;
//    Team team(&c1);
//    CHECK_EQ(team.stillAlive(), 1);
//    Character c2;
//    team.add(&c2);
//    CHECK_EQ(team.stillAlive(), 2);
//}
//
//TEST_CASE("Test 19: smartTeam Attack Method") {
//    Character c1;
//    Character c2;
//    smartTeam team1(&c1);
//    smartTeam team2(&c2);
//    Character c3;
//    Character c4;
//    team1.add(&c3);
//    team2.add(&c4);
//    team1.attack(&team2);
//    CHECK_EQ(team2.stillAlive(), 0);
//}
//
//TEST_CASE("Test 20: Character Distance Method") {
//    Character c1;
//    Character c2;
//    c1.setX(2);
//    c1.setY(2);
//    c2.setX(5);
//    c2.setY(6);
//    CHECK_EQ(c1.distance(&c2), 5.0);
//}

