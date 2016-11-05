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

    template <BiblicalMarriage::Roles role>
    bool addPerfomer(void *performer)  {
        return Relationship::addPerfomer_<int(role)>(performer);
    }
};


#endif //TEMPLATEEXPERIMENT_BIBLICALMARRIAGE_H
