#include "tsp_ga.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>

tsp_ga::tsp_ga(char* input) {
    p = pp_singleton::pp_instance(input);
    tsp_list = p ->return_interface() ->return_it();
    size = tsp_list.size();

    fill_distance();

    //weight distribution matrix
    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         std::cout << distance[i][j] << "\t";
    //     }   std::cout << std::endl;
    // }

    // permutate();
    // std::cout << "permutated list test" << std::endl;
    // for(int i = 0; i < permutated_list.size(); i++) {
    //     for(int j = 0; j < permutated_list[i].size(); j++) {
    //         std::cout << permutated_list[i][j].get_nodeID() << " ";
    //     }   std::cout << std::endl;
    // }
    // std::cout << std::endl;

    //dead code
    // std::vector<int> subset_test = combinations(5, size);
    // std::cout << "size: " << subset_test.size() << std::endl;
    // for(int i = 0; i < subset_test.size(); i++) {
    //     std::cout << subset_test[i] << std::endl;
    // }

    ga_initialize();
    ga_selection();
}

//Pure virtual functions.

void tsp_ga::run_tsp() {

}

void tsp_ga::display() {

}

//GA functions

void tsp_ga::ga_engine() {
    //Repeat all the processes, rank the routes in current gen using rankRoutes(). 
    //Run as many generations as needed to find the best path.
}

void tsp_ga::ga_initialize() {
    //Create population -> all possible routes or optimize by cutting off this process.
    permutate();

    //Determine fitness, rank each individual(chromosome)
    //Output will be an ordered list with the routeID and each associated fitness score
    for(int i = 0; i < permutated_list.size(); i++) {
        double fitness = euclidian_distance(permutated_list[i].first);
        permutated_list[i].second = fitness;
    }

    //Sorting the population by fitness
    std::sort(permutated_list.begin(), permutated_list.end(), [this] (std::pair<std::vector<tsp_node>,double> a, std::pair<std::vector<tsp_node>,double> b) {return compare(a, b);});
}

void tsp_ga::ga_selection() {
    //Roulette wheel selection/ Elitist selection. Maybe use elitism for smaller sets, use roulette wheel for bigger inputset
    //USe output from initialize() to select routes

    int elite_size = permutated_list.size() * 0.10;
    std::cout << "elite size: " << elite_size << std::endl;
    for(int i = 0; i < elite_size; i++) {
        selected_list.push_back(permutated_list[i]);
    }
    //Add roulette wheel?
    

    // //Elitism test
    // std::cout << "elitism test" << std::endl;
    // for(int i = 0; i < selected_list.size(); i++) {
    //     std::cout << selected_list[i].second << std::endl;
    // }
}

void tsp_ga::ga_crossbreed() {
    int start, final;
    double fitness = 0.0;

    //Ordered crossbreed
    solution_list.push_back(selected_list[0]);  //save the best performing chromosome in the solutions list
    for(int i = 0; i < selected_list.size(); i++) {
        srand(time(0));
        do {
            start = rand() % selected_list.size();
            final = rand() % selected_list.size();
        } while (start != final);
        next_gen_list.push_back(breed(selected_list[start], selected_list[final]));
    }
}

void tsp_ga::ga_mutate() {}

//Utility functions

void tsp_ga::fill_distance() {
    //This function populates the weight distribution matrix with 3D euclidean coordinates
    distance = new double*[size];
    for(int i = 0; i < size; i++) {
        distance[i] = new double[size];
    }   //Declaring space for distance[][]

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            distance[i][j] = euclidian_distance(tsp_list[i], tsp_list[j]);  //fill distance matrix with euclidian weights
        }
    }
}

double tsp_ga::euclidian_distance(tsp_node node1, tsp_node node2) {
    return sqrt(pow(node2.get_X() - node1.get_X(), 2)+ pow(node2.get_Y() - node1.get_Y(), 2) + pow(node2.get_Z() - node1.get_Z(), 2));
}

double tsp_ga::euclidian_distance(std::vector<tsp_node>& chromosome) {
    double total_distance = 0.0;
    for(int i = 0; i < size - 1; i++) {
        total_distance += chromosome[i].dist(chromosome[i + 1]);
    }
    total_distance += chromosome[0].dist(chromosome[size - 1]);
    return total_distance;
}

void tsp_ga::permutate() {
    do {
        permutated_list.push_back(make_pair(tsp_list, 0.0));
    }   while(std::next_permutation(tsp_list.begin(), tsp_list.end()));
}

bool tsp_ga::compare(const std::pair<std::vector<tsp_node>,double>& e1,const std::pair<std::vector<tsp_node>,double>& e2) {
    return e1.second < e2.second;
}

std::pair<std::vector<tsp_node>, double>& tsp_ga::breed(std::pair<std::vector<tsp_node>, double>& gene1, std::pair<std::vector<tsp_node>, double>& gene2) {

}

// std::vector<int> tsp_ga::combinations(int r, int n) {
//     std::vector<int> subsets;
//     combinations(0,0,r,n,subsets);

//     std::cout << "size2: " << subsets.size() << std::endl;

//     return subsets;
// }

// void tsp_ga::combinations(int set, int at, int r, int n, std::vector<int>& subsets) {
//     int elements_left = n - at;
//     if(elements_left < r)   return;
//     if(r == 0) {
//         subsets.push_back(set);
//     } else {
//         for(int i = at; i < n; i++) {
//             set ^= (1 << i);

//             combinations(set, i + 1, r - 1, n, subsets);

//             //Backtrack
//             set ^= (1 << i);
//         }
//     }
// }

