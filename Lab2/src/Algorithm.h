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
    virtual void load(std::string) = 0;
    virtual void execute() = 0;
    virtual void display() = 0;
    virtual void stat() = 0;
    virtual void select(int) = 0;
    virtual void save(std::string) = 0;
};

#endif