//
// Created by shahab on 05/11/2016.
//

#include "SquashGame.h"

SquashGame::SquashGame() {
    RoleBase* playerRole= new Role<SquashGame::Roles::Player>(2);
    RoleBase* refereeRole=new Role<SquashGame::Roles::Referee>(1);
    roleMap.emplace(SquashGame::Roles::Player,playerRole);
    roleMap.emplace(SquashGame::Roles::Referee,refereeRole);
}
