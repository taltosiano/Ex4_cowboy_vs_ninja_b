#include <iostream>
#include <vector>
#include <algorithm>
#include "Character.hpp"
#include "Team.hpp"
#include "SmartTeam.hpp"

namespace ariel{
        SmartTeam::SmartTeam(Character* leader) : Team(leader) {}
        SmartTeam::SmartTeam() :Team() {}
        // void SmartTeam::add(Character *member){}
        void SmartTeam::attack(Team *enemy){
                 if(!enemy){
            throw std::invalid_argument("nullptr enemy\n");
        }
        for(auto& member : enemy->getMembers()){
                
                cout<<endl<<"Todo build attack"<<endl;
                member->hit(50);
        }
    }
        
        // int SmartTeam::stillAlive(){return 0;}
        void SmartTeam::print(){
        for(auto& member : getMembers()){
        //for(int i=0;i<getSize();i++){
            cout << member->print() << endl;;
            
        }
        }
}