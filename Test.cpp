#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"

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
 YoungNinja n1 = new YoungNinja()


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

