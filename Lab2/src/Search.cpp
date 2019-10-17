#include "Search.h"
#include <chrono>

void Search::load() {
    search_algo = SearchAlgorithm("datafiles/graph.txt", "datafiles/weights.txt", "datafiles/positions.txt");
}

void Search::execute(int s, int d) {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
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
        cout << "DFS iterative (list)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_iterative_list.size(); i++) {
            cout << search_algo.dfs_iterative_list[i].node << " ";
            total_cost += search_algo.dfs_iterative_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        dfs_i_list.push_back(d);
    } else if(algorithm_selecter == 1) {
        cout << "BFS iterative (list)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_iterative_list.size(); i++) {
            cout << search_algo.bfs_iterative_list[i].node << " ";
            total_cost += search_algo.bfs_iterative_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        bfs_i_list.push_back(d);
    } else if(algorithm_selecter == 2) {
        cout << "DFS iterative (matrix)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_iterative_matrix.size(); i++) {
            cout << search_algo.dfs_iterative_matrix[i].node << " ";
            total_cost += search_algo.dfs_iterative_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        dfs_i_matrix.push_back(d);
    } else if(algorithm_selecter == 3) {
        cout << "BFS iterative (matrix)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_iterative_matrix.size(); i++) {
            cout << search_algo.bfs_iterative_matrix[i].node << " ";
            total_cost += search_algo.bfs_iterative_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        bfs_i_matrix.push_back(d);
    } else if(algorithm_selecter == 4) {
        cout << "DFS recursive (list)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_recursive_list.size(); i++) {
            cout << search_algo.dfs_recursive_list[i].node << " ";
            total_cost += search_algo.dfs_recursive_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        dfs_r_list.push_back(d);
    } else if(algorithm_selecter == 5) {
        cout << "BFS recursive (list)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_recursive_list.size(); i++) {
            cout << search_algo.bfs_recursive_list[i].node << " ";
            total_cost += search_algo.bfs_recursive_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        bfs_r_list.push_back(d);
    } else if(algorithm_selecter == 6) {
        cout << "DFS recursive (matrix)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dfs_recursive_matrix.size(); i++) {
            cout << search_algo.dfs_recursive_matrix[i].node << " ";
            total_cost += search_algo.dfs_recursive_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        dfs_r_matrix.push_back(d);
    } else if(algorithm_selecter == 7) {
        cout << "BFS recursive (matrix)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.bfs_recursive_matrix.size(); i++) {
            cout << search_algo.bfs_recursive_matrix[i].node << " ";
            total_cost += search_algo.bfs_recursive_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        bfs_r_matrix.push_back(d);
    } else if(algorithm_selecter == 8) {
        cout << "Dijkstra (list)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dijkstra_list.size(); i++) {
            cout << search_algo.dijkstra_list[i].node << " ";
            total_cost += search_algo.dijkstra_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        dijkstra_list.push_back(d);
    } else if(algorithm_selecter == 9) {
        cout << "Dijkstra (matrix)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.dijkstra_matrix.size(); i++) {
            cout << search_algo.dijkstra_matrix[i].node << " ";
            total_cost += search_algo.dijkstra_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        dijkstra_matrix.push_back(d);
    } else if(algorithm_selecter == 10) {
        cout << "A star (list)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.a_star_list.size(); i++) {
            cout << search_algo.a_star_list[i].node << " ";
            total_cost += search_algo.a_star_list[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        astar_list.push_back(d);
    } else {
        cout << "A star (matrix)" << endl;
        int i;
        double total_cost = 0.0;
        for(i = 0; i < search_algo.a_star_matrix.size(); i++) {
            cout << search_algo.a_star_matrix[i].node << " ";
            total_cost += search_algo.a_star_matrix[i].weight;
        }   cout << endl;
        cout << "Number of nodes: " << i << endl;
        cout << "Total cost of path: " << total_cost << endl;
        cout << "Execution time: " << execution_time << endl;
        exe_time = execution_time;
        t_cost = total_cost;
        num_nodes = i;
        report_data d;
        d.number_node = num_nodes;
        d.total_cost = t_cost;
        d.exec_time = exe_time;
        astar_matrix.push_back(d);
    }
}

void Search::display() {

}

void Search::save(fstream& output) {
    if(algorithm_selecter == 0) {
        output << "DFS iterative (list)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 1) {
        output << "BFS iterative (list)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 2) {
        output << "DFS iterative (matrix)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 3) {
        output << "BFS iterative (matrix)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 4) {
        output << "DFS recursive (list)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 5) {
        output << "BFS recursive (list)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 6) {
        output << "DFS recursive (matrix)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 7) {
        output << "BFS recursive (matrix)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else if(algorithm_selecter == 8) {
        output << "Dijkstra (list)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    } else {
        output << "Dijkstra (matrix)" << endl;
        output << "Number of nodes: " << num_nodes << endl;
        output << "total cost/distance: " << t_cost << endl;
        output << "execution time: " << exe_time << endl;
    }
}

void Search::format_report_list() {
    cout << endl << endl;
    cout << "format report" << endl;
    double nodes = 0.0;
    double cost = 0.0;
    double time = 0.0;
    for(int i = 0; i < dfs_i_list.size(); i++) {
        nodes += dfs_i_list[i].number_node;
        cost += dfs_i_list[i].total_cost;
        time += dfs_i_list[i].exec_time;
    }
    nodes = nodes / dfs_i_list.size();
    cost = cost / dfs_i_list.size();
    time = time / dfs_i_list.size();
    cout << "dfs iterative list" << endl;
    cout << "averaged node explored: " << nodes << endl;
    cout << "averaged total cost: " << cost << endl;
    cout << "averaged total time: " << time << endl;

    double nodes2 = 0.0;
    double cost2 = 0.0;
    double time2 = 0.0;
    for(int i = 0; i < dfs_r_list.size(); i++) {
        nodes2 += dfs_r_list[i].number_node;
        cost2 += dfs_r_list[i].total_cost;
        time2 += dfs_r_list[i].exec_time;
    }
    nodes2 = nodes2 / dfs_i_list.size();
    cost2 = cost2 / dfs_i_list.size();
    time2 = time2 / dfs_i_list.size();
    cout << "dfs iterative list" << endl;
    cout << "averaged node explored: " << nodes2 << endl;
    cout << "averaged total cost: " << cost2 << endl;
    cout << "averaged total time: " << time2 << endl;

    double nodes3 = 0.0;
    double cost3 = 0.0;
    double time3 = 0.0;
    for(int i = 0; i < bfs_i_list.size(); i++) {
        nodes3 += bfs_i_list[i].number_node;
        cost3 += bfs_i_list[i].total_cost;
        time3 += bfs_i_list[i].exec_time;
    }
    nodes3 = nodes3 / bfs_i_list.size();
    cost3 = cost3 / bfs_i_list.size();
    time3 = time3 / bfs_i_list.size();
    cout << "dfs iterative list" << endl;
    cout << "averaged node explored: " << nodes3 << endl;
    cout << "averaged total cost: " << cost3 << endl;
    cout << "averaged total time: " << time3 << endl;

    double nodes4 = 0.0;
    double cost4 = 0.0;
    double time4 = 0.0;
    for(int i = 0; i < bfs_r_list.size(); i++) {
        nodes4 += bfs_r_list[i].number_node;
        cost4 += bfs_r_list[i].total_cost;
        time4 += bfs_r_list[i].exec_time;
    }
    nodes4 = nodes4 / bfs_r_list.size();
    cost4 = cost4 / bfs_r_list.size();
    time4 = time4 / bfs_r_list.size();
    cout << "dfs iterative list" << endl;
    cout << "averaged node explored: " << nodes4 << endl;
    cout << "averaged total cost: " << cost4 << endl;
    cout << "averaged total time: " << time4 << endl;

    double nodes5 = 0.0;
    double cost5 = 0.0;
    double time5 = 0.0;
    for(int i = 0; i < dijkstra_list.size(); i++) {
        nodes5 += dijkstra_list[i].number_node;
        cost5 += dijkstra_list[i].total_cost;
        time5 += dijkstra_list[i].exec_time;
    }
    nodes5 = nodes5 / dijkstra_list.size();
    cost5 = cost5 / dijkstra_list.size();
    time5 = time5 / dijkstra_list.size();
    cout << "dfs iterative list" << endl;
    cout << "averaged node explored: " << nodes5 << endl;
    cout << "averaged total cost: " << cost5 << endl;
    cout << "averaged total time: " << time5 << endl;

    double nodes6 = 0.0;
    double cost6 = 0.0;
    double time6 = 0.0;
    for(int i = 0; i < astar_list.size(); i++) {
        nodes6 += astar_list[i].number_node;
        cost6 += astar_list[i].total_cost;
        time6 += astar_list[i].exec_time;
    }
    nodes6 = nodes6 / astar_list.size();
    cost6 = cost6 / astar_list.size();
    time6 = time6 / astar_list.size();
    cout << "dfs iterative list" << endl;
    cout << "averaged node explored: " << nodes6 << endl;
    cout << "averaged total cost: " << cost6 << endl;
    cout << "averaged total time: " << time6 << endl;
}

void Search::format_report_matrix() {
    cout << endl << endl;
    cout << "format report" << endl;
    double nodes = 0.0;
    double cost = 0.0;
    double time = 0.0;
    for(int i = 0; i < dfs_i_matrix.size(); i++) {
        nodes += dfs_i_matrix[i].number_node;
        cost += dfs_i_matrix[i].total_cost;
        time += dfs_i_matrix[i].exec_time;
    }
    nodes = nodes / dfs_i_matrix.size();
    cost = cost / dfs_i_matrix.size();
    time = time / dfs_i_matrix.size();
    cout << "dfs iterative matrix" << endl;
    cout << "averaged node explored: " << nodes << endl;
    cout << "averaged total cost: " << cost << endl;
    cout << "averaged total time: " << time << endl;

    double nodes2 = 0.0;
    double cost2 = 0.0;
    double time2 = 0.0;
    for(int i = 0; i < dfs_r_matrix.size(); i++) {
        nodes2 += dfs_r_matrix[i].number_node;
        cost2 += dfs_r_matrix[i].total_cost;
        time2 += dfs_r_matrix[i].exec_time;
    }
    nodes2 = nodes2 / dfs_i_matrix.size();
    cost2 = cost2 / dfs_i_matrix.size();
    time2 = time2 / dfs_i_matrix.size();
    cout << "dfs iterative matrix" << endl;
    cout << "averaged node explored: " << nodes2 << endl;
    cout << "averaged total cost: " << cost2 << endl;
    cout << "averaged total time: " << time2 << endl;

    double nodes3 = 0.0;
    double cost3 = 0.0;
    double time3 = 0.0;
    for(int i = 0; i < bfs_i_matrix.size(); i++) {
        nodes3 += bfs_i_matrix[i].number_node;
        cost3 += bfs_i_matrix[i].total_cost;
        time3 += bfs_i_matrix[i].exec_time;
    }
    nodes3 = nodes3 / bfs_i_matrix.size();
    cost3 = cost3 / bfs_i_matrix.size();
    time3 = time3 / bfs_i_matrix.size();
    cout << "dfs iterative matrix" << endl;
    cout << "averaged node explored: " << nodes3 << endl;
    cout << "averaged total cost: " << cost3 << endl;
    cout << "averaged total time: " << time3 << endl;

    double nodes4 = 0.0;
    double cost4 = 0.0;
    double time4 = 0.0;
    for(int i = 0; i < bfs_r_matrix.size(); i++) {
        nodes4 += bfs_r_matrix[i].number_node;
        cost4 += bfs_r_matrix[i].total_cost;
        time4 += bfs_r_matrix[i].exec_time;
    }
    nodes4 = nodes4 / bfs_r_matrix.size();
    cost4 = cost4 / bfs_r_matrix.size();
    time4 = time4 / bfs_r_matrix.size();
    cout << "dfs iterative matrix" << endl;
    cout << "averaged node explored: " << nodes4 << endl;
    cout << "averaged total cost: " << cost4 << endl;
    cout << "averaged total time: " << time4 << endl;

    double nodes5 = 0.0;
    double cost5 = 0.0;
    double time5 = 0.0;
    for(int i = 0; i < dijkstra_matrix.size(); i++) {
        nodes5 += dijkstra_matrix[i].number_node;
        cost5 += dijkstra_matrix[i].total_cost;
        time5 += dijkstra_matrix[i].exec_time;
    }
    nodes5 = nodes5 / dijkstra_matrix.size();
    cost5 = cost5 / dijkstra_matrix.size();
    time5 = time5 / dijkstra_matrix.size();
    cout << "dfs iterative matrix" << endl;
    cout << "averaged node explored: " << nodes5 << endl;
    cout << "averaged total cost: " << cost5 << endl;
    cout << "averaged total time: " << time5 << endl;

    double nodes6 = 0.0;
    double cost6 = 0.0;
    double time6 = 0.0;
    for(int i = 0; i < astar_matrix.size(); i++) {
        nodes6 += astar_matrix[i].number_node;
        cost6 += astar_matrix[i].total_cost;
        time6 += astar_matrix[i].exec_time;
    }
    nodes6 = nodes6 / astar_matrix.size();
    cost6 = cost6 / astar_matrix.size();
    time6 = time6 / astar_matrix.size();
    cout << "dfs iterative matrix" << endl;
    cout << "averaged node explored: " << nodes6 << endl;
    cout << "averaged total cost: " << cost6 << endl;
    cout << "averaged total time: " << time6 << endl;
}