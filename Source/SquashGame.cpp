//
// Created by shahab on 05/11/2016.
//

#include "SquashGame.h"

SquashGame::SquashGame() {
    //in a squash game, there are two players and a referee.
    RoleBase* playerRole= new RelationshipRole<SquashGame::Roles::Player>(2);
    RoleBase* refereeRole=new RelationshipRole<SquashGame::Roles::Referee>(1);
    roleMap.emplace(SquashGame::Roles::Player,playerRole);
    roleMap.emplace(SquashGame::Roles::Referee,refereeRole);
}
