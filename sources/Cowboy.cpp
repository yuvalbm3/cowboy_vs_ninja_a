#include "Cowboy.hpp"
#include "Point.hpp"

namespace ariel{
    Cowboy::Cowboy(string name, Point location): Character(name, location, 110, false), _boolets_amount(6){
    }
    
    void Cowboy::shoot(Character *enmy){
        if(this->getName() == enmy->getName() && this->getLocation() == enmy->getLocation()){
            throw std::runtime_error("You can't hurt yourself!");
        }
        else if(this->isAlive() && this->hasboolets()){
            enmy->hit(10);
        }
        this->_boolets_amount -= 1;

    }

    bool Cowboy::hasboolets(){
        return _boolets_amount > 0;
    }
    int Cowboy::booletNum(){
        return _boolets_amount;
    }

    void Cowboy::reload(){
        this->_boolets_amount = 6;
    }

}
