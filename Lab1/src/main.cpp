#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand
#include <ctime>        // std::time
#include "Sort.h"
using namespace std;

enum algorithm_type {BUBBLE, MERGE, LAST};

int main() {
    for(int i = BUBBLE; i <= LAST; i++) {
        Sort engine;
        engine.select(i);
        engine.load("temp.txt");
        engine.execute();
        engine.stat();
        engine.display();
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