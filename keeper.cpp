#include "keeper.h"
#include "animals.h"
using namespace std;
Good* Good ::_moodins=nullptr;
Good* Good ::moodins(){
    if(_moodins==nullptr){
        _moodins = new Good();
    }
    return _moodins;
}
Keeper* Good :: takeCare(Fish* f){
    f->modExh(1);
    return this;
}
Keeper* Good :: takeCare(Bird* b){
    b->modExh(2);
    return this;
}
Keeper* Good :: takeCare(Dog* d){
    d->modExh(3);
    return this;
}
void Good ::clearptr(){
    if(_moodins != nullptr){
        delete _moodins;
    }
}

Ordinary* Ordinary::_moodins=nullptr;
Ordinary* Ordinary ::moodins(){
    if(_moodins == nullptr){
        _moodins=new Ordinary();
    }
    return _moodins;
}
Keeper* Ordinary :: takeCare(Fish* f){
    f->modExh(-3);
    return this;
}
Keeper* Ordinary :: takeCare(Dog* d){
    d->modExh(0);
    return this;
}
Keeper* Ordinary :: takeCare(Bird* b){
    b->modExh(-1);
    return this;
}
void Ordinary ::clearptr() {
    if(_moodins != nullptr){
        delete _moodins;
    }
}
Bad* Bad :: _moodins = nullptr;
Bad* Bad ::moodins() {
    if(_moodins==nullptr){
        _moodins = new Bad();
    }
    return _moodins;

}
Keeper* Bad:: takeCare(Fish* f){
    f->modExh(-5);
    return this;
}
Keeper* Bad:: takeCare(Dog* d){
    d->modExh(-10);
    return this;
}
Keeper* Bad:: takeCare(Bird* b){
    b->modExh(-3);
    return this;
}
void Bad ::clearptr(){
    if(_moodins!=nullptr){
        delete _moodins;
    }
}

