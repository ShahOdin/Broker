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
//In general, the registerPerfomer function will be templatized based on a "task" enum.
//The task enum determines what signal will be matched to what function. To keep things
//simple for the purposes of demonstration, tasks are deferred to later.
    template <SquashGame::Roles role>
    void registerPerfomer(void *performer)  {
        Relationship::addPerformer<role>(performer);
    }
};


#endif //TEMPLATEEXPERIMENT_SQUASHGAME_H
