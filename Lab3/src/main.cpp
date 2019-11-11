#include "tsp_n.h"
#include "tsp_dp.h"
#include "tsp_interface.h"
#include "tsp_node.h"
#include <vector>
#include <iostream>
//#include "tsp.h"

int main () {
    tsp_interface* t = new tsp_n();
    t -> run_tsp();
    t -> display();

    return 0;
}