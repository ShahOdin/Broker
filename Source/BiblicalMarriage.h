//
// Created by shahab on 05/11/2016.
//

#ifndef TEMPLATEEXPERIMENT_BIBLICALMARRIAGE_H
#define TEMPLATEEXPERIMENT_BIBLICALMARRIAGE_H
#include "interface/Relationship.h"



class BiblicalMarriage : public Relationship{
public:
    BiblicalMarriage();

    enum Roles : int
    {
        Man,
        Woman
    };

//In general, the registerPerfomer function will be templatized based on a "task" enum.
//The task enum determines what signal will be matched to what function. To keep things
//simple for the purposes of demonstration, tasks are deferred to later.
    template <BiblicalMarriage::Roles role>
    bool registerPerfomer(void *performer)  {
        return Relationship::addPerfomer_<role>(performer);
    }
};


#endif //TEMPLATEEXPERIMENT_BIBLICALMARRIAGE_H
