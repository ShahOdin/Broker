//
// Created by shahab on 05/11/2016.
//

#ifndef TEMPLATEEXPERIMENT_RELATIONSHIP_H
#define TEMPLATEEXPERIMENT_RELATIONSHIP_H


#include "RelationshipRole.h"
#include <map>
#include <iostream>

#include <typeinfo>

class MultipleRolesInRelationship: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Playing multiple roles in this relationship is not allowed.\n"
                "ie. you can't be both the teacher and the student in the class.";
    }
};

class DuplicateRolesInRelationship: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Playing the same role in a relationship twice is not allowed. ie.\n"
                "1. You can't play squash against yourself.\n"
                "2. You can't be your own partner in double tennis";
    }
};

class RoleTaken: public std::exception
{
    virtual const char* what() const throw()
    {
        return "role(s) are already filled.";
    }
};

class RoleNotDefined: public std::exception
{
    virtual const char* what() const throw()
    {
        return "The provided role is not defined in this relationship.";
    }
};

//This class is the contact point for the "performers" in a relationship which acts as a contract or
//between the parties in a "relationship". It defines the set of interactions between the performers.
//In general, each performer can be a "server" for certain "roles" and a "client" for certain others.
//concrete relationships, define the signature of the functions to be shared by clients and servers.
//The servers pass on their function pointers when registering in a relationship and the clients bind
// their "signals" to them.
class Relationship{

//This function will be called internally by a concrete relationship to register a new "performer"
protected:
    template<int role>
    bool addPerformer(void *performer){
        bool success=true;
        try {
            registerPerformer<role>(performer);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << '\n';
            success=false;
        }
        return success;
    }
    //The container with the information about
    // the roles in a relationship
    std::map<int,RoleBase*>    roleMap;
private:
    template<int role>
    void registerPerformer(void *performer) {
        if(isPerformerNeeded<role>()){
            CheckPerformerQualified<role>(performer);
            auto relationshipRole=getRole<role>();
            relationshipRole->addPerformer();
            performerMap.emplace(role,performer);
        }
        else
            throw RoleTaken();
    }
    template<int role>
    bool isPerformerNeeded(){
        auto relationshipRole=getRole<role>();
        if(relationshipRole== nullptr)
        {
            throw RoleNotDefined();
        }
        else
            return relationshipRole->isPerformerNeeded();
    }

    //Templatizing this function allows easy interaction with a hetrogenous map.
    template<int role>
    RelationshipRole<role>* getRole() {
        auto it=roleMap.find(role);
        if ( it == roleMap.end() ) {
            return nullptr;
        } else {
            RoleBase* roleBase= it->second;
            return static_cast<RelationshipRole<role>* >(roleBase);
        }
    }

    //Checks if the performer faces any restrictions which might limit
    //its participation in the relationship.
    template<int role>
    void CheckPerformerQualified(void *performer) {
        for (auto& kv : performerMap) {
            if(kv.second==performer){
                if(kv.first==role)
                    throw DuplicateRolesInRelationship();
                else
                    throw MultipleRolesInRelationship();
            }
        }
    }
    std::multimap<int,void*>   performerMap;
};


#endif //TEMPLATEEXPERIMENT_RELATIONSHIP_H
