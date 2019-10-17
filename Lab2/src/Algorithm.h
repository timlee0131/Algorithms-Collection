#ifndef ALGORITHM_H
#define ALGORITHM_H

/*
    Load
    Execute
    Display
    Stats
    Select
    Save
*/

class Algorithm {
public:
    virtual void load() = 0;
    virtual void execute(int, int) = 0;
    virtual void display() = 0;
    virtual void stat() = 0;
    virtual void select(int) = 0;
    virtual void save(std::fstream&) = 0;
};

#endif