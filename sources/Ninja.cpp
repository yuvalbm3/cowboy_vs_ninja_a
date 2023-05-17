#include "Ninja.hpp"

namespace ariel{
    Ninja::Ninja(string name, Point loc, int hp, bool inTeam, int speed):Character(name, loc, hp, inTeam), _speed(speed){};
        
    void Ninja::move(Character *enmy){
        Point enmy_location = enmy->getLocation();
        enmy_location.Point::moveTowards(this->getLocation(), enmy_location, this->getSpeed());
    }
    void Ninja::slash(Character *enmy){
        if(this->getName() == enmy->getName() && this->getLocation() == enmy->getLocation()){
            throw std::runtime_error("You can't hurt yourself!");
        }
        else if(this->getLocation().distance(enmy->getLocation()) <= 1){
            enmy->hit(40);
        }
    }
    int Ninja::getSpeed(){
        return _speed;
    }
    string Ninja::print(){
        ostringstream os;
        if(_hp>0){
            os << "N - " << _name << ", " << _hp << ", " << _location << endl;
        }
        else{
            os << "N - (" << _name << "), " << _location << endl;
        }
        return os.str();
    }
    YoungNinja::YoungNinja(string name, Point loc):Ninja(name, loc, 100, false, 14){
        
    }

    TrainedNinja::TrainedNinja(string name, Point loc):Ninja(name, loc, 120, false, 12){
        
    }

    OldNinja::OldNinja(string name, Point loc):Ninja(name, loc, 150, false, 8){
        
    }

}