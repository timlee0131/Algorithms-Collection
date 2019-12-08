#include "tsp_tabu.h"

#include <cstdlib>
#include <iostream>

tsp_tabu::tsp_tabu(char* input) {
    p = pp_singleton::pp_instance(input);
    tsp_list = p ->return_interface() ->return_it();
}

//Interface code

void tsp_tabu::run_tsp() {
    tabu_engine();
}

void tsp_tabu::display() {}

void tsp_tabu::tabu_engine() {
    permutate();

    std::pair<std::vector<tsp_node>,double> sBest = permutated_list[0];
    std::pair<std::vector<tsp_node>,double> best_candidate = permutated_list[0];
    tabu_list.push_back(permutated_list[0]);
    int i = 0;
    while(i++ < 1000) {
        std::vector<std::pair<std::vector<tsp_node>, double>> sNeighbhorhood = select_neighbor(best_candidate);
        for(int i = 0; i < sNeighbhorhood.size(); i++) {    
            std::pair<std::vector<tsp_node>, double> sCandidate = sNeighbhorhood[0];
            if(!contains(sCandidate) && sCandidate.second > best_candidate.second) {
                best_candidate = sCandidate;
            }
        }
        if(best_candidate.second > sBest.second)
            sBest = best_candidate;
        tabu_list.push_back(best_candidate);

        std::cout << "generation " << i << ": ";
        for(int i = 0; i < sBest.first.size(); i++) {
            std::cout << sBest.first[i].get_nodeID() << " ";
        }   std::cout << std::endl;
    }

    std::cout << "solution list: ";
        for(int i = 0; i < sBest.first.size(); i++) {
            std::cout << sBest.first[i].get_nodeID() << " ";
        }   std::cout << std::endl;
}

std::vector<std::pair<std::vector<tsp_node>, double>> tsp_tabu::select_neighbor(std::pair<std::vector<tsp_node>,double>& best_candidate) {
    std::vector<std::pair<std::vector<tsp_node>, double>> neighbor_list;
    int node_count = 0;
    for(int i = 0; i < permutated_list.size(); i++) {
        if(best_candidate.second - permutated_list[i].second <= 10 || best_candidate.second - permutated_list[i].second >= -10) {
            neighbor_list.push_back(permutated_list[i]);
        }
    }
    return neighbor_list;
}

double tsp_tabu::euclidian_distance(std::vector<tsp_node>& chromosome) {
    double total_distance = 0.0;
    int size = chromosome.size();
    for(int i = 0; i < size - 1; i++) { 
        total_distance += chromosome[i].dist(chromosome[i + 1]);
    }
    total_distance += chromosome[0].dist(chromosome[size - 1]);
    return total_distance;
}

void tsp_tabu::permutate() {
    int count = 0;
    do {
        permutated_list.push_back(make_pair(tsp_list, 0.0));
        count++;
    }   while(std::next_permutation(tsp_list.begin(), tsp_list.end()) && count < 500);

    for(int i = 0; i < permutated_list.size(); i++) {
        double fitness = euclidian_distance(permutated_list[i].first);
        permutated_list[i].second = fitness;
    }
}

bool tsp_tabu::contains(std::pair<std::vector<tsp_node>, double>& candidate) {
    for(int i = 0; i < tabu_list.size(); i++) {
        for(int j = 0; j < tabu_list[i].first.size(); j++) {
            if(candidate.first[j].get_nodeID() != tabu_list[i].first[j].get_nodeID())
                return false;
        }
    }
    return true;
}