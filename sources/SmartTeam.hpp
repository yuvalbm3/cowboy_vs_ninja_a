#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <vector>
#include"Point.hpp"
#include"Character.hpp"
#include"Ninja.hpp"
#include"Cowboy.hpp"

namespace ariel{
    class SmartTeam{
    private:
        Character* leader;
        vector<Character> members;
        int team_size = 0;
    public:
        SmartTeam(Character*);
        ~SmartTeam();
        void add(Character*);
        void attack(SmartTeam*);
        int stillAlive();
        void print();
    };
}

#endif