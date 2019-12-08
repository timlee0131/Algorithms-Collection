#include "tsp_ga.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <chrono>

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
    ga_engine();
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
    std::chrono::high_resolution_clock::time_point s1 = std::chrono::high_resolution_clock::now();
    ga_initialize();
    std::chrono::high_resolution_clock::time_point e1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(e1-s1).count();
    std::cout << "initialization complete: " << duration1 << " ms" << std::endl;

    for(int i = 0; i < 250000; i++) {
        std::chrono::high_resolution_clock::time_point s2 = std::chrono::high_resolution_clock::now();
        ga_selection();
        std::chrono::high_resolution_clock::time_point e2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(e2-s2).count();
        std::cout << "selection complete: " << duration2 << " ms" << std::endl;
        std::chrono::high_resolution_clock::time_point s3 = std::chrono::high_resolution_clock::now();
        ga_crossbreed();
        std::chrono::high_resolution_clock::time_point e3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(e3-s3).count();
        std::cout << "crossbreed complete: " << duration3 << " ms" << std::endl;
        std::chrono::high_resolution_clock::time_point s4 = std::chrono::high_resolution_clock::now();
        ga_mutate();
        std::chrono::high_resolution_clock::time_point e4 = std::chrono::high_resolution_clock::now();
        auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(e4-s4).count();
        std::cout << "mutation complete: " << duration4 << " ms" << std::endl;

        for(int j = 0; j < next_gen_list.size(); j++) {
            double fitness = euclidian_distance(next_gen_list[j].first);
            next_gen_list[j].second = fitness;
        }
        permutated_list = next_gen_list;
        next_gen_list.clear();
        selected_list.clear();

        // for(int i = 0; i < permutated_list.size(); i++) {
        //     for(int j = 0; j < permutated_list[i].first.size(); j++) {
        //         std::cout << next_gen_list[i].first[j].get_nodeID() << " ";
        //     }
        //     std::cout << "\t" << next_gen_list[i].second;
        //     std::cout << std::endl;
        // }
    }

    std::cout << "solution list" << std::endl;
    for(int i = 0; i < solution_list.size(); i++) {
        for(int j = 0; j < solution_list[i].first.size(); j++) {
            std::cout << solution_list[i].first[j].get_nodeID() << " ";
        }
    }
}

void tsp_ga::ga_initialize() {
    //Create population -> all possible routes or optimize by cutting off this process.
    std::cout << "before permutate" << std::endl;
    permutate();
    std::cout << "after permutate" << std::endl;

    //Determine fitness, rank each individual(chromosome)
    //Output will be an ordered list with the routeID and each associated fitness score
    for(int i = 0; i < permutated_list.size(); i++) {
        double fitness = euclidian_distance(permutated_list[i].first);
        permutated_list[i].second = fitness;
    }

    std::cout << "after calculating fitness" << std::endl; 

    //Sorting the population by fitness
    std::sort(permutated_list.begin(), permutated_list.end(), [this] (std::pair<std::vector<tsp_node>,double> a, std::pair<std::vector<tsp_node>,double> b) {return compare(a, b);});

    std::cout << "after the sort" << std::endl;
}

void tsp_ga::ga_selection() {
    //Roulette wheel selection/ Elitist selection. Maybe use elitism for smaller sets, use roulette wheel for bigger inputset
    //USe output from initialize() to select routes

    int elite_size = permutated_list.size() * 0.3;
    for(int i = 0; i < elite_size; i++) {
        selected_list.push_back(permutated_list[i]);
    }
    //Add roulette wheel?
}

void tsp_ga::ga_crossbreed() {
    int start, final;
    double fitness = 0.0;

    //Ordered crossbreed
    solution_list.push_back(selected_list[0]);  //save the best performing chromosome in the solutions list
    for(int i = 0; i < selected_list.size()/2; i++) {
        do {
            start = rand() % selected_list.size();
            final = rand() % selected_list.size();
        } while (start == final);
        next_gen_list.push_back(breed(selected_list[start], selected_list[final]));
    }
    
    // for(int i = 0; i < next_gen_list.size(); i++) {
    //     std::cout << "generation " << i << ": ";
    //     for(int j = 0; j < next_gen_list[i].first.size(); j++) {
    //         std::cout << next_gen_list[i].first[j].get_nodeID() << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

void tsp_ga::ga_mutate() {
    for(int i = 0; i < next_gen_list.size(); i++) {
        mutate(next_gen_list[i]);
    }
}

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
    int count = 0;
    do {
        permutated_list.push_back(make_pair(tsp_list, 0.0));
        count++;
    }   while(std::next_permutation(tsp_list.begin(), tsp_list.end()) && count < 500);
}

bool tsp_ga::compare(const std::pair<std::vector<tsp_node>,double>& e1,const std::pair<std::vector<tsp_node>,double>& e2) {
    return e1.second < e2.second;
}

std::pair<std::vector<tsp_node>, double> tsp_ga::breed(std::pair<std::vector<tsp_node>, double>& gene1, std::pair<std::vector<tsp_node>, double>& gene2) {
    std::pair<std::vector<tsp_node>,double> child;
    int size = gene1.first.size();

    int r_start = rand() % (size/2);
    int r_end = r_start + (size/2);

    std::vector<tsp_node>::iterator it = gene1.first.begin();
    std::vector<tsp_node>::iterator it2 = gene1.first.begin();
    std::vector<tsp_node>::iterator it3 = gene1.first.begin();

    for(int i = r_start; i <= r_end; i++) {
        child.first.push_back(gene1.first[i]);
    }
    for(int i = 0; i < gene2.first.size(); i++) {
        if(std::find(child.first.begin(), child.first.end(), gene2.first[i]) == child.first.end()) {
            child.first.push_back(gene2.first[i]);
        }
    }
    return child;
}

void tsp_ga::mutate(std::pair<std::vector<tsp_node>, double>& chrom) {
    int mutation_rate = 10;
    for(int i = 0; i < chrom.first.size(); i++) {
        int indic = random() % 100 + 1;
        int swapWith;
        do {
            swapWith = random() % chrom.first.size();
        }   while(swapWith == i);
        if(indic <= mutation_rate) {
            std::swap(chrom.first[i], chrom.first[swapWith]);
        }
    }
}