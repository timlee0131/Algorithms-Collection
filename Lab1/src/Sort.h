#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Algorithm.h"
#include "SortAlgorithm.h"
using namespace std;

class Sort: public Algorithm {
private:
    string data_types[16] = {
        "random_10.txt", "reversed_sorted_10.txt", "20_unique_10.txt", "30_random_10.txt",
        "random_1000.txt", "reversed_sorted_1000.txt", "20_unique_1000.txt", "30_random_1000.txt",
        "random_10000.txt", "reversed_sorted_10000.txt", "20_unique_10000.txt", "30_random_10000.txt",
        "random_100000.txt", "reversed_sorted_100000.txt", "20_unique_100000.txt", "30_random_100000.txt"
    };
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
};

#endif