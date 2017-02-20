#include <iostream>
#include "Source/SquashGame.h"
#include "Source/BiblicalMarriage.h"

using namespace std;

class performer{};

int main() {
    bool allowed;
    auto p1 = new performer();
    auto p2 = new performer();
    auto p3 = new performer();
    auto p4 = new performer();
    auto p5 = new performer();

    SquashGame squash;
    allowed= squash.registerPerfomer<SquashGame::Roles::Player>(p1);
    cout<<allowed<<endl;
    //you can't play squash with yourself:
    allowed= squash.registerPerfomer<SquashGame::Roles::Player>(p1);
    cout<<allowed<<endl;
    allowed= squash.registerPerfomer<SquashGame::Roles::Player>(p2);
    cout<<allowed<<endl;
    //You can't join a game when your role is taken:
    allowed= squash.registerPerfomer<SquashGame::Roles::Player>(p3);
    cout<<allowed<<endl;
    allowed= squash.registerPerfomer<SquashGame::Roles::Referee>(p4);
    cout<<allowed<<endl;
    //You can't join a game when your role is taken:
    allowed= squash.registerPerfomer<SquashGame::Roles::Referee>(p5);
    cout<<allowed<<endl;
    cout<<"______"<<endl;

    BiblicalMarriage marriage;
    allowed= marriage.registerPerfomer<BiblicalMarriage::Roles::Man>(p1);
    cout<<allowed<<endl;
    //You can't join a marriage when your role is taken.
    allowed= marriage.registerPerfomer<BiblicalMarriage::Roles::Man>(p2);
    cout<<allowed<<endl;
    allowed= marriage.registerPerfomer<BiblicalMarriage::Roles::Woman>(p3);
    cout<<allowed<<endl;
    //You can't join a marriage when your role is taken.
    allowed= marriage.registerPerfomer<BiblicalMarriage::Roles::Woman>(p4);
    cout<<allowed<<endl;

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