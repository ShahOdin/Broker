#include <iostream>
#include "Source/SquashGame.h"
#include "Source/BiblicalMarriage.h"

using namespace std;

class performer{};

int main() {
    auto p1 = new performer();
    auto p2 = new performer();
    auto p3 = new performer();
    auto p4 = new performer();
    auto p5 = new performer();

    SquashGame squash;
    squash.registerPerfomer<SquashGame::Roles::Player>(p1);

    //you can't play squash with yourself:
    squash.registerPerfomer<SquashGame::Roles::Player>(p1);

    squash.registerPerfomer<SquashGame::Roles::Player>(p2);
    //You can't join a game when your role is taken:
    squash.registerPerfomer<SquashGame::Roles::Player>(p3);

    squash.registerPerfomer<SquashGame::Roles::Referee>(p4);

    //You can't join a game when your role is taken:
    squash.registerPerfomer<SquashGame::Roles::Referee>(p5);

    BiblicalMarriage marriage;
    marriage.registerPerfomer<BiblicalMarriage::Roles::Man>(p1);

    //You can't join a marriage when your role is taken.
    marriage.registerPerfomer<BiblicalMarriage::Roles::Man>(p2);

    marriage.registerPerfomer<BiblicalMarriage::Roles::Woman>(p3);

    //You can't join a marriage when your role is taken.
    marriage.registerPerfomer<BiblicalMarriage::Roles::Woman>(p4);

    
    //todo:
    //add a broker layer that would act as a match-maker. this way, the performers would only
    //register themselves with a broker which will be in charge of creating relationship
    //instances and assigning "rejected" performers to new relationships.
    //This would be in the form:
    // broker.getRelationship<ConcreteRelationship>().registerPerformer()
    //This way, we don't need to worry about merging of the role enums in the global scope.
    //The downside is verbosity.

    //todo:
    //The demonstration above only demonstrates registering performers in a relationship and does
    //not actually show any interaction between them. add specialized registerPerformer functions
    //that accept task enums and the associated task request and task handling by the clients and
    //servers respectively. The goal is to achieve full static type-checking with Enums so that
    // performers would only be able to pass on signals/slots of the right signature.
    //This will most likely have to be done in the form of a Task class that is templatized by
    //a Task enum and a function signature. This way, the registeration of the performer can only
    //be called with the right inputs.

    return 0;
}
