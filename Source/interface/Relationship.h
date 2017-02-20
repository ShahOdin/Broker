//
// Created by shahab on 05/11/2016.
//

#ifndef TEMPLATEEXPERIMENT_RELATIONSHIP_H
#define TEMPLATEEXPERIMENT_RELATIONSHIP_H


#include "Role.h"
#include <map>
#include <iostream>

#include <typeinfo>

//This class is the contact point for the "performers" in a relationship which acts as a contract or
//between the parties in a "relationship". It defines the set of interactions between the performers.
//In general, each performer can be a "server" for certain "roles" and a "client" for certain others.
//concrete relationships, define the signature of the functions to be shared by clients and servers.
//The servers pass on their function pointers when registering in a relationship and the clients bind
// their "signals" to them.

class Relationship{
    template<int role>
    bool isPerformerNeeded(){
        auto relationshipRole=getRole<role>();
        if(relationshipRole== nullptr)
        {
            std::cout<<"The relationship "<<typeid(this).name()<<"does not need the provided role."<<std::endl;
            return false;
        }
        else
            return relationshipRole->isPerformerNeeded();
    }

    //Templatizing this function allows easy interaction with a hetrogenous map.
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
    //Checks if the performer is already present in a relationship.
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

//This function will be called internally by a concrete relationship to register a new "performer"

protected:
    template<int role>
    bool addPerfomer_(void *performer) {
        if(!isPerformerNeeded<role>())
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
