#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string.h>
#include "Point.hpp"
// using namespace std;

namespace ariel{
    class Character{
    private:
        ariel::Point _location;
        int _hp;
        string _name;
        bool _inTeam = false;
    public:
        Character(string name, Point loc, int hitPoint, bool inTeam):_location(loc), _name(name), _hp(hitPoint), _inTeam(inTeam){};
        virtual bool isAlive();
        virtual double distance(Character);
        virtual void hit(int);
        virtual string getName();
        virtual int getHp();
        virtual Point getLocation();
        virtual bool getInTeam();
        //friends classes
        friend class Ninja;
        friend class Cowboy;
    };
}
#endif