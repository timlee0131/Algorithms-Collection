#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <iostream>
using namespace std;

class SortAlgorithm {
public:
    static void bubble_sort(vector<int>& vec);
    static void merge_sort1(vector<int>& vec);
    static void merge_sort(vector<int>& vec, int left, int right);
    static void merge(vector<int>& vec, int left, int middle, int right);
    static void insertion_sort(vector<int>& vec);
};

#endif