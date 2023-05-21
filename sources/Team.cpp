#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"

namespace ariel{
        Team::Team(Character* leader) : leader(leader){
            if(!(leader->isFreeMember())){
                    throw std::runtime_error("member already in a team");
                }
            this->members.push_back(leader);
            leader->addToTeam();
            //this->add(leader);
        }
        Team::Team(): leader(nullptr){ }
        void Team::add(Character *member){
                if(!member){
                    throw std::runtime_error("nullptr member");
                }
                if(!(member->isFreeMember())){
                    throw std::runtime_error("member already in a team");
                }
               if (members.empty()) {
                   throw invalid_argument("must be leader before add members");
                }
                if(this->members.size() == 10) {
                     throw runtime_error("in group can take a part 10 members only");
                  }
                this->members.push_back(member); 
                member->addToTeam();
        }
            Character* Team::getLeader() const{
                return this->leader;
                }
            vector<Character*> Team::getMembers() {
                 return this->members;
            }

 void Team::attack(Team *enemy){
    if(enemy == nullptr){
        throw std::invalid_argument("cannot attack- enemy is not exist");
    }
    if (stillAlive() == 0) {
        throw runtime_error("Team is dead");
    }
    if (enemy->stillAlive() == 0) {
       throw std::runtime_error("the attacked team is dead!");
    }
     if(leader == nullptr) return;
     Character *target = getClosestEnemy(enemy);

    for (const auto &member: members) { // Cowboys
        Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy != nullptr) {
            if(!cowboy->isAlive()) {
            if (target->isAlive()) {
                if (cowboy->hasboolets()) cowboy->shoot(target);
                else cowboy->reload();
            } else {
                target = getClosestEnemy(enemy);
                if (target == nullptr) return;
                else if (cowboy->hasboolets()) cowboy->shoot(target);
                else cowboy->reload();
            }
        }
        
        if(enemy->stillAlive()==0){
            
            break;
        }
      
  
        
    }

  for (const auto &member: members) { // Ninjas
        Ninja *ninja = dynamic_cast<Ninja *>(member);
        if (ninja != nullptr) {
            if(!ninja->isAlive()){
            if (target->isAlive()){
                if(ninja->distance(target) <= 1.0) ninja->slash(target);
                else ninja->move(target);
            } else {
                target = getClosestEnemy(enemy);
                if (target == nullptr) return;
                else if (ninja->distance(target) <= 1.0) ninja->slash(target);
                else {
                    ninja->move(target);
                }
            }
            if(enemy->stillAlive()==0){
            
            break;
        }
         }
        }
    }
}

 
//     Character* closestEnemy = getClosestEnemy(&*enemy);
//     std::vector<Character*> attackers;
//     for (auto& member : members) {
//         if (member->isAlive()) {
//             attackers.push_back(member);
//         }
//     }
//     for (auto attacker : attackers) {
//     if (attacker->isAlive()) {
//         Character* closestEnemy = getClosestEnemy(enemy);
//         if (attacker->distance(closestEnemy) <= 1) {
//             attacker->hit(3);
//             std::cout << attacker->getName() << " attacks " << closestEnemy->getName() << std::endl;
//         } else {
//             std::cout << attacker->getName() << " cannot attack " << closestEnemy->getName() << std::endl;
//         }
//     }

//     if (enemy->stillAlive() == 0) {
//         break; // exit the function early
// }
// }
// }


// Character* Team::getClosestEnemy(Team& enemy) {
// Character* closestEnemy = nullptr;
//     int min_distance = std::numeric_limits<double>::max();
//     for (auto& member : enemy.members) {
//         int distance = member->distance(leader);
//         if (distance < min_distance) {
//             min_distance = distance;
//             closestEnemy = member;
//         }
//     }
//     if (closestEnemy == nullptr) {
//         throw runtime_error("No enemies found");
//     }
//     return closestEnemy;
// }


Character* Team::getClosestEnemy(Team* enemy) {
    if(enemy == nullptr || enemy->getMembers().size() == 0){
        throw std::invalid_argument("cannot find closet- enemy is not exist or the group is empty");
    }
    Character* closestEnemy = nullptr;
    int min_distance = std::numeric_limits<double>::max();
    bool foundEnemy = false; 
    for (auto& member : enemy->members) {
        if (member->isAlive()) { 
            foundEnemy = true;
            int distance = member->distance(leader);
            if (distance < min_distance) {
                min_distance = distance;
                closestEnemy = member;
            }
        }
    }
    if (!foundEnemy) { 
        throw std::runtime_error("No enemies found");
    }
    return closestEnemy;
}

        int Team::stillAlive(){
            int sum = 0;
            for (auto& member : members) {
                if (member->isAlive()) {
                sum++;
             }
            } 
            return sum;
          }
        void Team::print(){
        //      for(const Character& member : members){
        //     Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
        //     if(cowboy){
        //         cout<<cowboy->print();
        //         cout<<endl;
        //     }
            
        // }

        // for(const Character& member : members){
        //     Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
        //     if(!cowboy){
        //         cout << member.print();
        //         cout<<endl;
        //     }
        // }

        for (auto& member : members) {
        Cowboy* cowboy = dynamic_cast<Cowboy *>(member);
        if (cowboy != nullptr) {
            cout << member->print() << endl;
        }
    }
    for (auto& member : members) {
        Ninja* ninja = dynamic_cast<Ninja*>(member);
        if (ninja != nullptr) {
            cout << member->print() << endl;
        }
    }
            }
        Team::~Team(){
            for (auto member : getMembers()) {
                delete member;
            }
             //   size = 0;
            leader = nullptr;
        }
}