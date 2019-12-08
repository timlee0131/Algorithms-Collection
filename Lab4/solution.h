#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "tsp_node.h"

class solution {
private:
    double fitness_score;
    std::vector<tsp_node> map_list;
    int* v;
public:
    solution(std::vector<tsp_node>);
    void fitness();
    void swap_solve(int i, int j);
    void initialize();
    int getV(int);
    double get_fitness();
};

#endif