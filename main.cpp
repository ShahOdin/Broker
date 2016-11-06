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
    allowed=squash.addPerfomer<SquashGame::Roles::Player>(p1);
    cout<<allowed<<endl;
    allowed=squash.addPerfomer<SquashGame::Roles::Player>(p1);
    cout<<allowed<<endl;
    allowed=squash.addPerfomer<SquashGame::Roles::Player>(p2);
    cout<<allowed<<endl;
    allowed=squash.addPerfomer<SquashGame::Roles::Player>(p3);
    cout<<allowed<<endl;
    allowed=squash.addPerfomer<SquashGame::Roles::Referee>(p4);
    cout<<allowed<<endl;
    allowed=squash.addPerfomer<SquashGame::Roles::Referee>(p5);
    cout<<allowed<<endl;
    cout<<"______"<<endl;

    BiblicalMarriage marriage;
    allowed=marriage.addPerfomer<BiblicalMarriage::Roles::Man>(p1);
    cout<<allowed<<endl;
    allowed=marriage.addPerfomer<BiblicalMarriage::Roles::Man>(p2);
    cout<<allowed<<endl;
    allowed=marriage.addPerfomer<BiblicalMarriage::Roles::Woman>(p3);
    cout<<allowed<<endl;
    allowed=marriage.addPerfomer<BiblicalMarriage::Roles::Woman>(p4);
    cout<<allowed<<endl;

    return 0;
}