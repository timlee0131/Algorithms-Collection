#include "solution.h"
#include <time.h>

solution::solution(std::vector<tsp_node> vec) {
    this -> map_list = vec;
    v = new int[map_list.size()];
    fitness_score  = 0.0;
    initialize();
}

void solution::initialize() {
    for(int i = 0; i < map_list.size(); i++) {
        v[i] = i;
    }
    for(int i = (map_list.size() - 1); i >= 0; i--) {
        int j = rand() % map_list.size();
        std::swap(v[i], v[j]);
    }
    fitness();
}

void solution::fitness() {
    score = 0.0;
}