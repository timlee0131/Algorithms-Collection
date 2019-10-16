#ifndef DS_TESTING_H
#define DS_TESTING_H

#include <iostream>
#include <string>
#include "ds_linklist.h"
#include "ds_adjlist.h"
#include "ds_adjmatrix.h"
using namespace std;

class ds_testing {
private:
    ds_linklist<int> link_list;
    ds_adjlist<int> adj_list;
    ds_adjmatrix<int> adj_matrix;
public:
    void construct();
    void display();
};

#endif