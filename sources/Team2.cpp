#include "Team2.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
using namespace std;

#define WARRIORS_LIM 10

namespace ariel{
    Team2::Team2(Character* other){
        if(this->team_size != 0){
            throw::runtime_error("This team already exists.");
        }
        else{
            leader = other;
            team_size ++;
            members.push_back(other);
        }
    }

    Team2::~Team2(){

    }

    void Team2::add(Character* other){
        if(team_size < 10){
            members.push_back(other);
            team_size ++;
        }
    }

    void Team2::attack(Team2*){

    }

    int Team2::stillAlive(){
        int alive = 0;
        for (std::size_t i = 0; i < members.size(); ++i){
            if(members[i]->isAlive()){
                alive++;
            }
        }
        return alive;
    }
    
    void Team2::print(){

    }
}