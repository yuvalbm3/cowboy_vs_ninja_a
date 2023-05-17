#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include <sstream>

namespace ariel{
    class Ninja : public Character{
    private:
        int _speed;
    public:
        Ninja(string name, Point loc, int hp, bool inTeam, int speed);
        
        void move(Character *enmy);
        
        void slash(Character *enmy);
        
        int getSpeed();

        string print();
    };

    class YoungNinja : public Ninja{
        public:
            YoungNinja(string name, Point loc);
    };

    class TrainedNinja : public Ninja{
        public:
            TrainedNinja(string name, Point loc);
    };
    
    class OldNinja : public Ninja{
        public:
            OldNinja(string name, Point loc);
    };
}

#endif
