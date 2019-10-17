#ifndef SEARCH_ALGORITHM
#define SEARCH_ALGORITHM

//#include <fstream>
//#include <iostream>
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

struct node {
    data_box box;
    data_box parent;
    double g = 0.0;
    double h = 0.0;
    double f = 0.0;
};

class SearchAlgorithm {
public:
    SearchAlgorithm() {};
    SearchAlgorithm(string, string, string);      //Constructor should initialize src and dest,
                                                            //Also initialize command line arguments.
    //Algorithms
    void dfs_i_l(int, int);
    void bfs_i_l(int, int);
    void dfs_i_m(int, int);
    void bfs_i_m(int, int);

    void dfs_r_l(int, int);
    void dfs_r_l_recursion(data_box, data_box, bool*, vector<data_box>);
    void bfs_r_l(int, int);
    void bfs_r_l_recursion(data_box, data_box, bool*, vector<data_box>);

    void dfs_r_m(int, int);
    void dfs_r_m_recursion(data_box, data_box,stack<data_box>&, bool*, vector<data_box>);
    void bfs_r_m(int, int);
    void bfs_r_m_recursion(data_box, data_box,queue<data_box>&, bool*, vector<data_box>);

    void dijkstra_l(int, int);
    vector<data_box> a_star_l(int, int);

    void dijkstra_m(int, int);
    vector<data_box> a_star_m(int, int);

    double get_heuristic(data_box, data_box);

    void display();
    vector<data_box> dfs_iterative_list, bfs_iterative_list, dfs_iterative_matrix, bfs_iterative_matrix, dijkstra_list, dijkstra_matrix;
    vector<data_box> dfs_recursive_list, bfs_recursive_list;
    vector<data_box> dfs_recursive_matrix, bfs_recursive_matrix;
private:
    ds_adjlist<data_box> list;
    ds_adjmatrix<data_box> matrix;
    parse_process pp;
};

#endif