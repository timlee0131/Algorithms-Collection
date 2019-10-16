#include "SearchAlgorithm.h"
#include <iostream>
using namespace std;

int main() {
    SearchAlgorithm sa = SearchAlgorithm(1, 2500, "large50/largeGraph.txt", "large50/largeWeights.txt", "large50/largePositions.txt");
    sa.dfs_i_l();
    cout << endl;
    sa.bfs_i_l();
    cout << endl;

    sa.dfs_i_m();
    cout << endl;
    sa.bfs_i_m();
    cout << endl;
    
    sa.dfs_r_l();
    cout << endl;
    sa.bfs_r_l();
    cout << endl;

    sa.dfs_r_m();
    cout << endl;
    sa.bfs_r_m();
    cout << endl;
    return 0;
}