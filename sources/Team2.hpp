#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <vector>
#include"Point.hpp"
#include"Character.hpp"
#include"Ninja.hpp"
#include"Cowboy.hpp"

namespace ariel{
    class Team2{
    private:
        Character* leader;
        vector<Character*> members;
        int team_size = 0;
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