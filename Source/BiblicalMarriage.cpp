//
// Created by shahab on 05/11/2016.
//

#include "BiblicalMarriage.h"

BiblicalMarriage::BiblicalMarriage() {
    //here we are specifying that in a biblical marriage, there is one man and one woman.
    RoleBase* manRole= new Role<BiblicalMarriage::Roles::Man>(1);
    RoleBase* womanRole=new Role<BiblicalMarriage::Roles::Woman>(1);
    roleMap.emplace(BiblicalMarriage::Roles::Man,manRole);
    roleMap.emplace(BiblicalMarriage::Roles::Woman,womanRole);
}
