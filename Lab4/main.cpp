#include "tsp_ga.h"
#include "tsp_tabu.h"
#include "tsp_interface.h"
#include "tsp_node.h"
#include <vector>
#include <iostream>
#include <string>
//#include "tsp.h"

int main () {
    srand(time(NULL));
    char* input = "datafiles/largePositions.txt";    //When testing against private list of nodes, change this value.
    tsp_interface* k;
    std::string streamer;
    std::cout << "which algorithm are you running> 1) GA. 2) Tabu" << ": ";
    std::cin >> streamer;
    if(streamer[0] == '1') {
        k = new tsp_ga(input);
        k -> run_tsp();
    } else {
        k = new tsp_tabu(input);
        k -> run_tsp();
    }

    return 0;
}