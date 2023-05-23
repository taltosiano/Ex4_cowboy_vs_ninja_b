#include "Team.hpp"

namespace ariel{
        Team::Team(Character* leader) : leader(leader){
            if(!(leader->isFreeMember())){
                    throw std::runtime_error("member already in a team");
                }
            if(leader->isLeaderBul()){
                throw std::runtime_error("member already in a leader");
            }
            this->members.push_back(leader);
            leader->addToTeam();
            setLeader(leader);
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
            void Team::setLeader(Character* lead){
                  if(lead->isLeaderBul()){
                     throw std::runtime_error("err");
                     }
                 this->leader=lead;
                 lead->isLeader();
                }
            vector<Character*> Team::getMembers() {
                 return this->members;
            }
Character * Team::getClosestAliveMember(){
     double minimum_distance = std::numeric_limits<double>::max();
        Character* closetMember = nullptr;
        for (Character* member : this->members) {
            if (member->isAlive()) {
                double distance = member->getLocation().distance(this->leader->getLocation());
                if (distance < minimum_distance) {
                    minimum_distance = distance;
                    closetMember = member;
                }
            }
        }
        return closetMember;
    }
void Team::attack(Team* enemy_team) {
    if (enemy_team == nullptr) {
        throw std::invalid_argument("cannot attack null!");
    }
    if (enemy_team->stillAlive() == 0) {
        throw std::runtime_error("Cannot attack a dead team!");
    }
    if (this->stillAlive() == 0 ){
        throw std::runtime_error("team is dead");
    }
    if (!this->leader->isAlive()) {
         Character* closetMember = getClosestAliveMember();
        if (closetMember != nullptr) {
            setLeader(closetMember);
        }
    }
    Character* closetEnemy = getClosestEnemy(enemy_team); 
    int theMembers = this->members.size();
    for (Character* member : this->members) {
        if (closetEnemy == nullptr) {
            break;
        }  
        if (member->isAlive() && dynamic_cast<Cowboy*>(member)) {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if (cowboy->hasboolets()) {
                cowboy->shoot(closetEnemy);
            } else {
                cowboy->reload();
            }
            
            if (!closetEnemy->isAlive()) {
                closetEnemy = getClosestEnemy(enemy_team);
            }
            theMembers--; 
            if (theMembers == 0) {
                break;
            }
        }
    }
    for (Character* member : this->members) {
        if (closetEnemy == nullptr) {
            break;
        }
        if (member->isAlive() && dynamic_cast<Ninja*>(member)) {
            Ninja* ninja = dynamic_cast<Ninja*>(member);
            if (ninja->distance(closetEnemy) < 1) {
                ninja->slash(closetEnemy);
            } else {
                ninja->move(closetEnemy);
            }
            if (!closetEnemy->isAlive()) {
                closetEnemy = getClosestEnemy(enemy_team);
            }
            theMembers--;
            if (theMembers == 0) {
                break;
            }
        }
    }
}

Character* Team::getClosestEnemy(Team* enemyTeam) {
    double closetEnemyDistance = std::numeric_limits<double>::max();
    Character* closetEnemy = nullptr;

    for (Character* enemy : enemyTeam->members) {
        if (enemy->isAlive()) {
            double distance = enemy->getLocation().distance(this->leader->getLocation());
            if (distance < closetEnemyDistance) {
                closetEnemyDistance = distance;
                closetEnemy = enemy;
            }
        }
    }

    return closetEnemy;
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