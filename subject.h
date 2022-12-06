#ifndef SUBJECT_H
#define SUBJECT_H

#include<vector>
#include <memory>

class Observer;
class Piece;

class Subject {
    std::vector<Observer*> observers;   
 public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers(std::vector<std::vector<Piece*>> &b);
    //virtual char getState(int row, int col) const = 0;
    virtual ~Subject() = default;
};

#endif







