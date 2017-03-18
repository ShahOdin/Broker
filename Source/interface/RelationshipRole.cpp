//
// Created by shahab on 05/11/2016.
//

#include "RelationshipRole.h"

RoleBase::RoleBase(int maxPerformers) : maxPerformers(maxPerformers){

}

bool RoleBase::isPerformerNeeded() {
    return currentPerformers<maxPerformers;
}

void RoleBase::addPerformer() {
    currentPerformers++;
}

