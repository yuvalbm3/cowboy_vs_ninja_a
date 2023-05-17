#include "Character.hpp"
#include <string.h>
using namespace std;

namespace ariel{
    bool Character::isAlive(){
        if((this->_hp) > 0)
            return true;
        return false;
    }
    double Character::distance(Character other){
        double ans = this->_location.distance(other.getLocation());
        return ans;
    }
    void Character::hit(int num){
        _hp = _hp - num;
    }
    string Character::getName(){
        return _name;
    }
    Point Character::getLocation(){
        return _location;
    }
    int Character::getHp(){
        return _hp;
    }
    bool Character::getInTeam(){
        return _inTeam;
    }

}