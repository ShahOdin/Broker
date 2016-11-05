//
// Created by shahab on 05/11/2016.
//

#ifndef TEMPLATEEXPERIMENT_RELATIONSHIP_H
#define TEMPLATEEXPERIMENT_RELATIONSHIP_H


#include "Role.h"
#include <map>

class Relationship{
    template<int role>
    bool performerNeeded(){
        auto relationshipRole=getRole<role>();
        return relationshipRole->performerNeeded();
    }

    template<int role>
    Role<role>* getRole() {
        auto it=roleMap.find(int(role));
        if ( it == roleMap.end() ) {
            return nullptr;
        } else {
            RoleBase* roleBase= it->second;
            return static_cast<Role<role>* >(roleBase);
        }
    }

protected:
    template<int role>
    bool addPerfomer_(void *performer) {
        if(!performerNeeded<role>())
            return false;
        else
        {
            auto relationshipRole=getRole<role>();
            relationshipRole->addPerformer();
            performerMap.emplace(int(role),performer);
            return true;
        }
    }
    std::map<int,RoleBase*>    roleMap;
    std::multimap<int,void*>   performerMap;
};


#endif //TEMPLATEEXPERIMENT_RELATIONSHIP_H
