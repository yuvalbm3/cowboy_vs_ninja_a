#include "Team.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
using namespace std;

#define WARRIORS_LIM 10

namespace ariel{
    Team::Team(Character* other){
        team_size ++;
    }

    Team::~Team(){

    }

    void Team::add(Character*){
        team_size ++;
    }

    void Team::attack(Team*){
        team_size --;
    }

    int Team::stillAlive(){
        
        return team_size;
    }
    
    void Team::print(){

    }
}