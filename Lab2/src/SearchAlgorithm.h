#ifndef SEARCH_ALGORITHM
#define SEARCH_ALGORITHM

#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "parse_process.h"

using namespace std;

/*
    Create the following search algorithms
        o DFS (both iterative and recursive implementations)
        o BFS (both iterative and recursive implementations)
        o Dijkstra
        o A*
    • Each Algorithm should:
        o Accept two int values as input, representing source and destination nodes
        o Return the path from source to destination, with total cost of path
        o Perform search over both adjacency list and adjacency matrix forms of 
*/

class SearchAlgorithm {
public:
    SearchAlgorithm(int, int, string, string, string);      //Constructor should initialize src and dest,
                                                            //Also initialize command line arguments.
    //Algorithms
    vector<data_box> dfs_i_l();
    vector<data_box> bfs_i_l();
    vector<data_box> dfs_i_m();
    vector<data_box> bfs_i_m();

    void dfs_r_l();
    void dfs_r_l_recursion(data_box, data_box, bool*, vector<data_box>);
    void bfs_r_l();
    void bfs_r_l_recursion(data_box, data_box, bool*, vector<data_box>);

    void dfs_r_m();
    void dfs_r_m_recursion(stack<data_box>&, bool*, vector<data_box>);
    void bfs_r_m();
    void bfs_r_m_recursion(queue<data_box>&, bool*, vector<data_box>);

    vector<data_box> dijkstra_l();
    vector<data_box> a_star_l();

    vector<data_box> dijkstra_m();
    vector<data_box> a_star_m();

    void display();
private:
    int src, dest;
    ds_adjlist<data_box> list;
    ds_adjmatrix<data_box> matrix;
    parse_process pp;
    vector<data_box> dfs_recursive_list, bfs_recursive_list;
    vector<data_box> dfs_recursive_matrix, bfs_recursive_matrix;
};

#endif