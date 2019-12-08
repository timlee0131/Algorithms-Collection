#include "tsp_ga.h"
#include "tsp_interface.h"
#include "tsp_node.h"
#include <vector>
#include <iostream>
//#include "tsp.h"

int main () {
    srand(time(NULL));
    char* input = "datafiles/largePositions.txt";    //When testing against private list of nodes, change this value.
    tsp_interface* k = new tsp_ga(input);
    // k -> run_tsp();
    // k -> display();

    return 0;
}