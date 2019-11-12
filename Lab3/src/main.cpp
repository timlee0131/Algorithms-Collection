#include "tsp_n.h"
#include "tsp_dp.h"
#include "tsp_interface.h"
#include "tsp_node.h"
#include <vector>
#include <iostream>
//#include "tsp.h"

int main () {
    tsp_interface* k = new tsp_dp();
    k -> run_tsp();
    k -> display();

    k = new tsp_n();
    k -> run_tsp();
    k -> display();

    return 0;
}