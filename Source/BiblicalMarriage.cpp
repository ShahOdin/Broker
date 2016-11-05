//
// Created by shahab on 05/11/2016.
//

#include "BiblicalMarriage.h"

BiblicalMarriage::BiblicalMarriage() {
    RoleBase* manRole= new Role<BiblicalMarriage::Roles::Man>(1);
    RoleBase* womanRole=new Role<BiblicalMarriage::Roles::Woman>(1);
    roleMap.emplace(BiblicalMarriage::Roles::Man,manRole);
    roleMap.emplace(BiblicalMarriage::Roles::Woman,womanRole);
}
