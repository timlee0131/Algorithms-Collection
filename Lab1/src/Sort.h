#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <chrono>
#include "Algorithm.h"
#include "SortAlgorithm.h"
using namespace std;

class Sort: public Algorithm {
private:
    SortAlgorithm sort_algo;
    vector<int> file_vector;
    int algorithm_selecter;
    std::vector<void (*) (vector<int>&)> algorithms = {&SortAlgorithm::bubble_sort, &SortAlgorithm::merge_sort1, &SortAlgorithm::insertion_sort};
    // void (SortAlgorithm::*fp) (vector<int>&);
    // fp algorithms[3] = {&SortAlgorithm::bubble_sort, &SortAlgorithm::merge_sort1, &SortAlgorithm::insertion_sort};
    double execution_time;
public:
    void load(string filename);
    void execute();
    void display();
    void stat();
    void select(int);
    void save(string filepath);

    string data_types[16] = {
        "data_files/random_10.txt", "data_files/reversed_sorted_10.txt", "data_files/20_unique_10.txt", "data_files/30_random_10.txt",
        "data_files/random_1000.txt", "data_files/reversed_sorted_1000.txt", "data_files/20_unique_1000.txt", "data_files/30_random_1000.txt",
        "data_files/random_10000.txt", "data_files/reversed_sorted_10000.txt", "data_files/20_unique_10000.txt", "data_files/30_random_10000.txt",
        "data_files/random_100000.txt", "data_files/reversed_sorted_100000.txt", "data_files/20_unique_100000.txt", "data_files/30_random_100000.txt"
    };
};

#endif