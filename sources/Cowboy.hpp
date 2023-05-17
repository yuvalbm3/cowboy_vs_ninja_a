#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <sstream>

namespace ariel{
    class Cowboy : public Character{
    private:
        int _boolets_amount;
    public:
        Cowboy(string name, Point location);
        void shoot(Character *enmy);
        bool hasboolets();
        int booletNum();
        void reload();
        string print(){
            ostringstream os;
            if(_hp>0){

                os << "C - " << _name << ", " << _hp << ", " << _location << endl;
            }
            else{
                os << "C - (" << _name << "), " << _location << endl;
            }
            return os.str();
        }    
    };
    
}

#endif
