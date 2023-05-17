#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Point")
{
  Point p1, p2(4, 1), p3(-6, -4), p4(-3, 5.5), p5(0,0);
  CHECK_EQ(p1, p5);
  CHECK(p2.getX() == 4);
  p2.setX(2);
  CHECK(p2.getX() == 2);
  CHECK(p2.getY() == 1);
  CHECK(p4.getX() == -3);
  CHECK(p4.getY() == 5.5);
  CHECK_EQ(((int(p1.distance(p3) * 100)) / 100.0), 7.21);
}

TEST_CASE("Cowboy")
{
  Cowboy cb1("Lucky", Point(10, 2)), cb2("Luke", Point(1.5, 3.0));
  CHECK(cb1.isAlive());
  CHECK(cb2.isAlive());
  CHECK_EQ(cb1.getHp(), 110);
  CHECK_EQ(cb2.getHp(), 110);
  CHECK_NOTHROW(cb1.shoot(&cb2));
  CHECK_EQ(cb2.getHp(), 100);
  CHECK_THROWS(cb1.shoot(&cb1));
  CHECK_EQ(cb1.booletNum(), 5);
  CHECK_EQ(cb2.booletNum(), 6);
  while(cb2.hasboolets())
  {
    cb2.shoot(&cb1);
  }
  CHECK_EQ(cb1.getHp(), 50);
  CHECK_FALSE(cb2.hasboolets());
  cb2.reload();
  CHECK(cb2.hasboolets());
}

TEST_CASE("Ninja")
{
  Point p0, p1(1, 1), p2(2, 2), p3(3, 2);
  
  YoungNinja yn("Bibi", p0);
  CHECK(yn.isAlive());
  CHECK(yn.getSpeed() == 14);
  CHECK(yn.getHp() == 100);

  TrainedNinja tn("Yair", p1);
  CHECK(tn.isAlive());
  CHECK(tn.getSpeed() == 12);
  CHECK(tn.getHp() == 120);

  OldNinja on1("Zibi", p3), on2("Benni", p2);
  CHECK(on1.isAlive());
  CHECK(on2.isAlive());
  CHECK(on1.getSpeed() == 8);
  CHECK(on1.getHp() == 150);
  CHECK(on2.getHp() == 150);
  CHECK_NOTHROW(on1.move(&on2));
  on1.move(&on2);
  CHECK(on2.getHp() == 150);
  on1.slash(&on2);
  CHECK(on2.getHp() == 110);

  CHECK_NOTHROW(tn.print());
  CHECK_NOTHROW(yn.print());
  CHECK_NOTHROW(on1.print());
}

TEST_CASE("Team2")
{
  Point p1(1, 1),p2(1.0, 2.0), p3(2,2);
  Cowboy cowboy1("Para", p2), cowboy2("Shor", p3);
  TrainedNinja tn1("Jini", p1);
  Team2 teamA(&cowboy1);
  Team2 teamB(&cowboy2);
  CHECK_NOTHROW(teamA.add(&tn1));
  CHECK(teamA.stillAlive() == 2);
  CHECK(teamB.stillAlive() == 1);
  CHECK_NOTHROW(teamA.attack(&teamB));
}

TEST_CASE("Active Game & Team")
{
  Point p1(1, 1), p2(2, 2), p3(3, 3);
  TrainedNinja tn1("Jacky", p1), tn2("Chan", p2);
  YoungNinja yn("Dre", Point(1, 2));
  OldNinja on("Miagi", Point(8.0, 3.5));
  Cowboy cb1("Tibi", Point(1.0, 2.0)), cb2("Melo", Point(2, 3));
  CHECK_THROWS(cb1.shoot(&cb1));
  CHECK_THROWS(tn1.slash(&tn1));
  cb1.reload();
  CHECK_EQ(cb1.hasboolets(), true);
  Team teamA(&cb1);
  teamA.add(&cb2);
  teamA.add(&on);
  Team teamB(&tn1);
  teamB.add(&tn2);
  teamB.add(&yn);
  CHECK(teamA.stillAlive() == 3);
  CHECK(teamB.stillAlive() == 3);
  CHECK_NOTHROW(teamA.attack(&teamB));
  if (teamB.stillAlive() == 0){
    CHECK_FALSE(tn1.isAlive());
    CHECK_FALSE(tn2.isAlive());
    CHECK_FALSE(yn.isAlive());
    CHECK_THROWS(teamA.attack(&teamB));
  }
  else{
    CHECK_NE(teamB.stillAlive(), 0);
  }
}