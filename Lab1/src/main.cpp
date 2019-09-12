#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand
#include <ctime>        // std::time
#include "Sort.h"
using namespace std;

enum algorithm_type {BUBBLE, MERGE, LAST};

string outputfiles[48] = {
    "bubble_random_10.txt", "bubble_reverse_10.txt", "bubble_unique_10.txt", "bubble_partial_10.txt", "bubble_random_1000.txt", "bubble_reverse_1000.txt", "bubble_unique_1000.txt", "bubble_partial_1000.txt", "bubble_random_10000.txt", "bubble_reverse_10000.txt", "bubble_unique_10000.txt", "bubble_partial_10000.txt", "bubble_random_100000.txt", "bubble_reverse_100000.txt", "bubble_unique_100000.txt", "bubble_partial_100000.txt", 
    "merge_random_10.txt", "merge_reverse_10.txt", "merge_unique_10.txt", "merge_partial_10.txt", "merge_random_1000.txt", "merge_reverse_1000.txt", "merge_unique_1000.txt", "merge_partial_1000.txt", "merge_random_10000.txt", "merge_reverse_10000.txt", "merge_unique_10000.txt", "merge_partial_10000.txt", "merge_random_100000.txt", "merge_reverse_100000.txt", "merge_unique_100000.txt", "merge_partial_100000.txt", 
    "insertion_random_10.txt", "insertion_reverse_10.txt", "insertion_unique_10.txt", "insertion_partial_10.txt", "insertion_random_1000.txt", "insertion_reverse_1000.txt", "insertion_unique_1000.txt", "insertion_partial_1000.txt", "insertion_random_10000.txt", "insertion_reverse_10000.txt", "insertion_unique_10000.txt", "insertion_partial_10000.txt", "insertion_random_100000.txt", "insertion_reverse_100000.txt", "insertion_unique_100000.txt", "insertion_partial_100000.txt"
};

int main() {
    int k = 0;
    for(int i = BUBBLE; i <= LAST; i++) {
        Sort engine;
        for(int j = 0; j < 16; j++) {
            engine.select(i);
            engine.load(engine.data_types[j]);
            engine.execute();
            engine.save(outputfiles[k++]);
            engine.stat();
        }
    }

    return 0;
}

// int main() {
//     vector<int> myvector;
//     myvector.push_back(3);          myvector.push_back(2);
//     myvector.push_back(8);          myvector.push_back(7);
//     myvector.push_back(6);          myvector.push_back(9);
//     myvector.push_back(5);          myvector.push_back(1);
//     myvector.push_back(10);          myvector.push_back(4);

//     for(int i = 0; i < myvector.size(); i++) {
//         cout << myvector[i] << " ";
//     } cout << endl << "Initial myvector printing complete......" << endl << endl;

//     SortAlgorithm sort;
//     sort.merge_sort(myvector);
//     sort.insertion_sort(myvector);
//     sort.bubble_sort(myvector);

//     for(int i = 0; i < myvector.size(); i++) {
//         cout << myvector[i] << " ";
//     } cout << endl << "Bubble sort testing complete......" << endl << endl;

//     for(int i = 0; i < myvector.size(); i++) {
//         cout << myvector[i] << " ";
//     } cout << endl << "Merge sort testing complete......" << endl << endl;

//     for(int i = 0; i < myvector.size(); i++) {
//         cout << myvector[i] << " ";
//     } cout << endl << "Insertion sort testing complete......" << endl;

//     return 0;
// }