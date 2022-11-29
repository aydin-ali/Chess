#include "subject.h"
#include "observer.h"
using namespace std;

void Subject::attach(Observer *o){
    observers.emplace_back(o);
}

void Subject::detach(Observer *o){
    for(auto it = observers.begin(); it != observers.end(); ++it){
        if(*it == o){
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(vector<vector<Piece*>> &b){
    for(auto &o : observers){
        o->notify(b);
    }
}

