#ifndef TSP_GA_H
#define TSP_GA_H

#include "tsp_interface.h"
#include "tsp_node.h"
#include "pp_singleton.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>

class tsp_ga: public tsp_interface {
private:
    std::vector<tsp_node> tsp_list;

    std::vector<std::pair<std::vector<tsp_node>, double>> permutated_list;
    std::vector<std::pair<std::vector<tsp_node>, double>> selected_list;
    std::vector<std::pair<std::vector<tsp_node>, double>> next_gen_list;

    std::vector<std::pair<std::vector<tsp_node>, double>> solution_list;        //solutions across generations.

    pp_singleton* p;

    double** distance;
    int size;
public:
    //Constructor
    tsp_ga(char*);

    //virtual functions
    void run_tsp();
    void display();

    //GA functions
    void ga_engine();

    void ga_initialize();
    void ga_selection();
    void ga_crossbreed();
    void ga_mutate();

    //Utility functions.
    void fill_distance();

    double euclidian_distance(tsp_node, tsp_node);
    double euclidian_distance(std::vector<tsp_node>&);

    void permutate();

    std::pair<std::vector<tsp_node>, double> breed(std::pair<std::vector<tsp_node>, double>&, std::pair<std::vector<tsp_node>, double>&);
    void mutate(std::pair<std::vector<tsp_node>, double>&);

    bool compare(const std::pair<std::vector<tsp_node>,double>&, const std::pair<std::vector<tsp_node>,double>&);

    // std::vector<int> combinations(int, int);
    // void combinations(int, int, int, int, std::vector<int>&);
};

#endif