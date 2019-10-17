#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "parse_process.h"
#include "Algorithm.h"
#include "SearchAlgorithm.h"
using namespace std;

struct report_data {
    int number_node;
    double total_cost;
    double exec_time;
};

class Search: public Algorithm {
public:
    void load();
    void execute(int, int);
    void display();
    void stat();
    void select(int);
    void save(fstream&);

    void format_report_list();
    void format_report_matrix();
private:
    int s, d;
    int num_nodes;
    double t_cost;
    double exe_time;
    SearchAlgorithm search_algo;
    int algorithm_selecter;
    vector<void (SearchAlgorithm::*) (int, int)> algos = {
        &SearchAlgorithm::dfs_i_l, &SearchAlgorithm::bfs_i_l, &SearchAlgorithm::dfs_i_m, &SearchAlgorithm::bfs_i_m, &SearchAlgorithm::dfs_r_l, &SearchAlgorithm::bfs_r_l, &SearchAlgorithm::dfs_r_m, &SearchAlgorithm::bfs_r_m, &SearchAlgorithm::dijkstra_l, &SearchAlgorithm::dijkstra_m,
        &SearchAlgorithm::a_star_l, &SearchAlgorithm::a_star_m
    };

    // void (SearchAlgorithm::*fp[10]) (int, int) = {&SearchAlgorithm::dfs_i_l, &SearchAlgorithm::bfs_i_l, &SearchAlgorithm::dfs_i_m, &SearchAlgorithm::bfs_i_m, &SearchAlgorithm::dfs_r_l, &SearchAlgorithm::bfs_r_l, &SearchAlgorithm::dfs_r_m, &SearchAlgorithm::bfs_r_m, &SearchAlgorithm::dijkstra_l, &SearchAlgorithm::dijkstra_m};

    vector<data_box> path;
    double execution_time;

    vector<report_data> dfs_i_list, dfs_r_list, bfs_i_list, bfs_r_list, dijkstra_list, astar_list, dfs_i_matrix, dfs_r_matrix, bfs_i_matrix, bfs_r_matrix, dijkstra_matrix, astar_matrix;
};

#endif