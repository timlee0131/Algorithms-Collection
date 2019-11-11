#include "parse_process.h"
#include <fstream>
#include <string>
#include <iostream>

void parse_process::load(char* filename) {
    std::ifstream input(filename);
    std::string temp;
    int anchor;
    double x, y, z;
    while(!input.eof()) {
        anchor = 0;
        x = 0.0;  y = 0.0;  z = 0.0;
        for(int i = 0; i < 4; i++) {
            if(i ==0 || i == 1 || i == 2)
                getline(input, temp, ',');
            else
                getline(input, temp);
            if(input.eof())    break;
            if(i == 0)          anchor = stoi(temp);
            else if(i == 1)     x = stod(temp);
            else if(i == 2)     y = stod(temp);
            else                z = stod(temp);
        }   //end for
        if(anchor != 0) {
            tsp_node node;
            node.set_nodeID(anchor);
            node.set_X(x);
            node.set_Y(y);
            node.set_Z(z);

            process_list.push_back(node);
        }
    }   //end while
}

void parse_process::output(char* filename) {
    //Implement output() with a virtual proxy?
    std::cout << "output function under construction" << std::endl;
}

std::vector<tsp_node> parse_process::return_it() {
    return process_list;
}