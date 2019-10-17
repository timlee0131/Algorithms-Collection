#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>
#include <iomanip>

#include "parse_process.h"
#include "Algorithm.h"
#include "SearchAlgorithm.h"
using namespace std;

class Search: public Algorithm {
public:
    void load();
    void execute(int, int);
    void display();
    void stat();
    void select(int);
    void save(string filepath);
private:
    int s, d;
    SearchAlgorithm search_algo;
    int algorithm_selecter;
    vector<void (SearchAlgorithm::*) (int, int)> algos = {
        &SearchAlgorithm::dfs_i_l, &SearchAlgorithm::bfs_i_l, &SearchAlgorithm::dfs_i_m, &SearchAlgorithm::bfs_i_m, &SearchAlgorithm::dfs_r_l, &SearchAlgorithm::bfs_r_l, &SearchAlgorithm::dfs_r_m, &SearchAlgorithm::bfs_r_m, &SearchAlgorithm::dijkstra_l, &SearchAlgorithm::dijkstra_m
    };

    // void (SearchAlgorithm::*fp[10]) (int, int) = {&SearchAlgorithm::dfs_i_l, &SearchAlgorithm::bfs_i_l, &SearchAlgorithm::dfs_i_m, &SearchAlgorithm::bfs_i_m, &SearchAlgorithm::dfs_r_l, &SearchAlgorithm::bfs_r_l, &SearchAlgorithm::dfs_r_m, &SearchAlgorithm::bfs_r_m, &SearchAlgorithm::dijkstra_l, &SearchAlgorithm::dijkstra_m};

    vector<data_box> path;
    double execution_time;
};

#endif