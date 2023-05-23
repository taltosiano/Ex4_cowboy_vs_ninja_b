#include "SmartTeam.hpp"

namespace ariel{
        SmartTeam::SmartTeam(Character* leader) : Team(leader) {}
        SmartTeam::SmartTeam() :Team() {}
        void SmartTeam::attack(Team *enemy_team){
           if (enemy_team == nullptr) {
                throw std::invalid_argument("cannot attack null!");
            }
            if (enemy_team->stillAlive() == 0) {
                throw std::runtime_error("Cannot attack a dead team!");
            }
            if (this->stillAlive() == 0 ){
                throw std::runtime_error("team is dead");
            }
            if (!this->getLeader()->isAlive()) {
                Character* closetMember = getClosestAliveMember();
                if (closetMember != nullptr) {
                    setLeader(closetMember);
                }
            }
            Character* closetEnemy = getClosestEnemy(enemy_team); 
            int theMembers = this->getMembers().size();
            for (Character* member : this->getMembers()) {
                if (closetEnemy == nullptr) {
                    break;
                }  
                if (member->isAlive()) {
                    Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
                    Ninja* ninja = dynamic_cast<Ninja*>(member);
                    if (cowboy) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(closetEnemy);
                        } else {
                            cowboy->reload();
                        }
                    } else if (ninja) {
                        if (ninja->distance(closetEnemy) < 1) {
                            ninja->slash(closetEnemy);
                        } else {
                            ninja->move(closetEnemy);
                        }
                    }
                    
                    if (!closetEnemy->isAlive()) {
                        closetEnemy = getClosestEnemy(enemy_team);
                    }
                    if (--theMembers == 0) {
                        break;
                    }
                }
            }
        }
        void SmartTeam::print(){
        for(auto& member : getMembers()){
            cout << member->print() << endl;;
            
        }
        }
}