#include "Search.h"
#include <chrono>

void Search::load() {
    search_algo = SearchAlgorithm("large50/largeGraph.txt", "large50/largeWeights.txt", "large50/largePositions.txt");
}

void Search::execute(int s, int d) {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    cout << s << d << endl;
    (search_algo.*algos[algorithm_selecter])(s, d);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    double time_span_ms = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    execution_time = time_span_ms;
}

void Search::select(int n) {
    algorithm_selecter = n;
}

void Search::stat() {
    if(algorithm_selecter == 0) {
        cout << "DFS iterative (list)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_iterative_list.size(); i++) {
            cout << search_algo.dfs_iterative_list[i].node << " ";
            total_cost += search_algo.dfs_iterative_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 1) {
        cout << "BFS iterative (list)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_iterative_list.size(); i++) {
            cout << search_algo.bfs_iterative_list[i].node << " ";
            total_cost += search_algo.bfs_iterative_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 2) {
        cout << "DFS iterative (matrix)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_iterative_matrix.size(); i++) {
            cout << search_algo.dfs_iterative_matrix[i].node << " ";
            total_cost += search_algo.dfs_iterative_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 3) {
        cout << "BFS iterative (matrix)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_iterative_matrix.size(); i++) {
            cout << search_algo.bfs_iterative_matrix[i].node << " ";
            total_cost += search_algo.bfs_iterative_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 4) {
        cout << "DFS recursive (list)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_recursive_list.size(); i++) {
            cout << search_algo.dfs_recursive_list[i].node << " ";
            total_cost += search_algo.dfs_recursive_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 5) {
        cout << "BFS recursive (list)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_recursive_list.size(); i++) {
            cout << search_algo.bfs_recursive_list[i].node << " ";
            total_cost += search_algo.bfs_recursive_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 6) {
        cout << "DFS recursive (matrix)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_recursive_matrix.size(); i++) {
            cout << search_algo.dfs_recursive_matrix[i].node << " ";
            total_cost += search_algo.dfs_recursive_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 7) {
        cout << "BFS recursive (matrix)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_recursive_matrix.size(); i++) {
            cout << search_algo.bfs_recursive_matrix[i].node << " ";
            total_cost += search_algo.bfs_recursive_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else if(algorithm_selecter == 8) {
        cout << "Dijkstra (list)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dijkstra_list.size(); i++) {
            cout << search_algo.dijkstra_list[i].node << " ";
            total_cost += search_algo.dijkstra_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    } else {
        cout << "Dijkstra (matrix)" << " ";
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dijkstra_matrix.size(); i++) {
            cout << search_algo.dijkstra_matrix[i].node << " ";
            total_cost += search_algo.dijkstra_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time;
    }
}

void Search::display() {

}

void Search::save(string filename) {

}