#ifndef TSP_TABU_H
#define TSP_TABU_H

#include "tsp_interface.h"
#include "tsp_node.h"
#include "pp_singleton.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>

class tsp_tabu: public tsp_interface {
private:
    std::vector<tsp_node> tsp_list;

    std::vector<std::pair<std::vector<tsp_node>, double>> permutated_list;
    std::vector<std::pair<std::vector<tsp_node>, double>> tabu_list;
    int* neighborhood_id;

    pp_singleton* p;
public:
    //Constructor
    tsp_tabu(char*);

    //interface code
    void run_tsp();
    void display();

    //TABU engine code
    void tabu_engine();
    std::vector<std::pair<std::vector<tsp_node>, double>> select_neighbor(std::pair<std::vector<tsp_node>,double>&);

    //Utility functions
    void permutate();

    double euclidian_distance(std::vector<tsp_node>&);
    bool contains(std::pair<std::vector<tsp_node>, double>&);
};

#endif