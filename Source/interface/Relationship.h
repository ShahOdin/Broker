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
        auto it=roleMap.find(role);
        if ( it == roleMap.end() ) {
            return nullptr;
        } else {
            RoleBase* roleBase= it->second;
            return static_cast<Role<role>* >(roleBase);
        }
    }

    template<int role>
    bool isPerformerPresent(void *performer) {
        auto iteratorPair = performerMap.equal_range(role);
        bool bpresent=false;
        for (auto& i = iteratorPair.first; i != iteratorPair.second; ++i)
        {
            auto p=i->second;
            if(p==performer){
                bpresent=true;
                break;
            }
        }
        return bpresent;
    }

protected:
    template<int role>
    bool addPerfomer_(void *performer) {
        if(!performerNeeded<role>())
            return false;
        else if(!isPerformerPresent<role>(performer))
        {
            auto relationshipRole=getRole<role>();
            relationshipRole->addPerformer();
            performerMap.emplace(role,performer);
            return true;
        }
        else
            return false;
    }
    std::map<int,RoleBase*>    roleMap;
    std::multimap<int,void*>   performerMap;
};


#endif //TEMPLATEEXPERIMENT_RELATIONSHIP_H
