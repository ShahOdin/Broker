//
// Created by shahab on 05/11/2016.
//

#ifndef TEMPLATEEXPERIMENT_SQUASHGAME_H
#define TEMPLATEEXPERIMENT_SQUASHGAME_H


#include "interface/Relationship.h"


class SquashGame: public Relationship{
public:
    SquashGame();

    enum Roles : int
    {
        Player,
        Referee
    };

    template <SquashGame::Roles role>
    bool addPerfomer(void *performer)  {
        return Relationship::addPerfomer_<int(role)>(performer);
    }
};


#endif //TEMPLATEEXPERIMENT_SQUASHGAME_H
