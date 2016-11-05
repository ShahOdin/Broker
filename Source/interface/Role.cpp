//
// Created by shahab on 05/11/2016.
//

#include "Role.h"

RoleBase::RoleBase(int maxPerformers) : maxPerformers(maxPerformers){

}

bool RoleBase::performerNeeded() {
    return currentPerformers<maxPerformers;
}

void RoleBase::addPerformer() {
    currentPerformers++;
}

