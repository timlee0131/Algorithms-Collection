#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include "Algorithm.h"
#include "SearchAlgorithm.h"
using namespace std;

class Search: public Algorithm {
public:
private:
    void load(string filename);
    void execute();
    void display();
    void stat();
    void select(int);
    void save(string filepath);

    
};

#endif