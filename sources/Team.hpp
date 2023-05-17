#ifndef TEAM_HPP
#define TEAM_HPP


#include"Point.hpp"
#include"Character.hpp"
#include"Ninja.hpp"
#include"Cowboy.hpp"

namespace ariel{
    class Team{
    private:
        Character* leader;
        Character** team;
        int team_size = 0;
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