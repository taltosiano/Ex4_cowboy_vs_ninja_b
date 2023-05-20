#include <iostream>
#include <vector>
#include <algorithm>
#include "Character.hpp"
#include "Team.hpp"
#include "Team2.hpp"

namespace ariel{
        Team2::Team2(Character* leader) : Team(leader){}
        Team2::Team2():Team(){}
        //void Team2::add(Character *member){}
        void Team2::attack(Team *enemy){
                 /*throws*/
        if(enemy == nullptr){
            throw std::invalid_argument("cannot attack- enemy is not exist");
        }
        if(enemy->getMembers().size() == 0){
            throw std::invalid_argument("nullptr enemy\n");
        }
        if(this->getMembers().size()==0){
            throw std::invalid_argument("ghost army: empty team!\n");
        }
        Character* leader;
        if((leader = nullptr)){
            throw std::invalid_argument("dead army: everyone died!\n");
        }
        if(enemy->stillAlive()==0){
            throw std::runtime_error("dead army: everyone died!\n");
        }

        /*closest enemy to leader*/
        Character* target;

        /*attack by character order in team-array*/
        for(Character* member : enemy->getMembers()){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if(cowboy){
                if(cowboy->isAlive()){
                    if((target = this->getClosestEnemy(enemy))){
                        if(cowboy->hasboolets()){
                            cowboy->shoot(target);
                        }else{
                            cowboy->reload();
                        }
                    }
                }
            }else{
                Ninja* ninja = dynamic_cast<Ninja*>(member);
                if(ninja->isAlive()){
                    if((target = this->getClosestEnemy(enemy))){
                        if(ninja->distance(target)>1){
                            ninja->move(target);
                        }else{
                            ninja->slash(target);
                        }
                    }
                }
            }
        }

        // if(enemy.stillAlive()==0){
        //     return 1;
        // }
        // return 0;
    }

        
       // int Team2::stillAlive(){return 0;}
        void Team2::print(){
         for(Character* member : getMembers()){
            cout << member->print();
            cout<<endl;
        }
        }
       // Team2::~Team2(){}
}