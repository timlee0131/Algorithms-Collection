#include "parse_process.h"
#include <fstream>
#include <sstream>
#include <iostream>

void parse_process::parse_graph(string filename, string filename2, string filename3) {

    ifstream input(filename);
    string temp;
    while(getline(input, temp)) {
        stringstream stemp;
        string token_temp;
        stemp << temp;
        getline(stemp, token_temp, ',');
        int anchor = stoi(token_temp);
        while(getline(stemp, token_temp, ',')) {
            int edge = stoi(token_temp);
            data_box box_a, box_e;
            box_a.node = anchor;
            box_e.node = edge;
            list.insert_back(box_a, box_e);
        }
        stemp.clear();
    }
    //list_display();

    input.clear();      //reset EOF
    input.seekg(0, ios::beg);
    matrix = ds_adjmatrix<data_box>(list.get_size() + 1);
    while(getline(input, temp)) {
        stringstream stemp;
        string token_temp;
        stemp << temp;
        getline(stemp, token_temp, ',');
        int anchor = stoi(token_temp);
        while(getline(stemp, token_temp, ',')) {
            int edge = stoi(token_temp);
            data_box box;
            matrix.add_edge(anchor, edge, box);
        }
        stemp.clear();
    }
    //matrix_display();

    //second file
    ifstream input2(filename2);
    string temp2;
    int anchor2, edge2;
    double weight2 = 0.0;
    while(!input2.eof()) {
        for(int i = 0; i < 3; i++) {
            if(i == 0 || i == 1) 
                getline(input2, temp2, ',');
            else
                getline(input2, temp2);
            if(input2.eof())    break;
            if(i == 0)          anchor2 = stoi(temp2);
            else if(i == 1)     edge2 = stoi(temp2);
            else                weight2 = stod(temp2);
        }
        data_box box_a2, box_e2;
        box_a2.node = anchor2;
        box_e2.node = edge2;

        list.find(box_a2) -> get_edges().find(box_e2) -> get_data().weight = weight2;
    }
    //list_display_weight();

    input2.clear();      //reset EOF
    input2.seekg(0, ios::beg);

    while(!input2.eof()) {
        for(int i = 0; i < 3; i++) {
            if(i == 0 || i == 1) 
                getline(input2, temp2, ',');
            else
                getline(input2, temp2);
            if(input2.eof())    break;
            if(i == 0)          anchor2 = stoi(temp2);
            else if(i == 1)     edge2 = stoi(temp2);
            else                weight2 = stod(temp2);
        }
        data_box box2;
        box2.weight = weight2;
        matrix.add_edge(anchor2, edge2, box2);
    }
    //matrix_display_weight();


    //third file
    ifstream input3(filename3);
    string temp3;
    int anchor3;
    double x, y, z;
    while(!input3.eof()) {
        for(int i = 0; i < 4; i++) {
            if(i ==0 || i == 1 || i == 2)
                getline(input3, temp3, ',');
            else
                getline(input3, temp3);
            if(input3.eof())    break;
            if(i == 0)          anchor3 = stoi(temp3);
            else if(i == 1)     x = stod(temp3);
            else if(i == 2)     y = stod(temp3);
            else                z = stod(temp3);
        }
        data_box box3;
        box3.node = anchor3;
        box3.x = x;
        box3.y = y;
        box3.z = z;
        list.find(box3) -> get_data().x = x;
        list.find(box3) -> get_data().y = y;
        list.find(box3) -> get_data().z = z;
    }
    //list_display_position();

    input3.clear();      //reset EOF
    input3.seekg(0, ios::beg);

    while(!input3.eof()) {
        for(int i = 0; i < 4; i++) {
                if(i == 0 || i == 1 || i == 2) 
                    getline(input3, temp3, ',');
                else
                    getline(input3, temp3);
                if(input3.eof())    break;
                if(i == 0)          anchor3 = stoi(temp3);
                else if(i == 1)     x = stod(temp3);
                else if(i == 2)     y = stod(temp3);
                else                z = stod(temp3);
            }
            data_box box3;
            box3.node = anchor3;
            box3.x = x;
            box3.y = y;
            box3.z = z;
            matrix.add_edge(anchor3, anchor3, box3);
    }
    //matrix_display_position();
}

void parse_process::list_display() {
    adj_node<data_box>* curr = list.get_head();
    while(curr != nullptr) {
        cout << curr -> get_data().node << ": ";
        ds_node<data_box>* edge = curr -> get_edges().get_head();
        while(edge != nullptr) {
            cout << edge ->get_data().node << " ";
            edge = edge -> get_next();
        }   cout << endl;
        curr = curr -> get_next();
    }
}

void parse_process::matrix_display() {
    for(int i = 0; i < list.get_size(); i++) {
        for(int j = 0; j < list.get_size(); j++) {
            cout << matrix.get_existence(i, j) << " ";
        }   cout << endl;
    }
    cout << endl;
}

void parse_process::list_display_weight() {
    adj_node<data_box>* curr = list.get_head();
    while(curr != nullptr) {
        cout << curr -> get_data().node << ": ";
        ds_node<data_box>* edge = curr -> get_edges().get_head();
        while(edge != nullptr) {
            cout << edge ->get_data().node << "<" << edge -> get_data().weight << ">" << " ";
            edge = edge -> get_next();
        }   cout << endl;
        curr = curr -> get_next();
    }
}

void parse_process::matrix_display_weight() {
    for(int i = 0; i < list.get_size(); i++) {
        for(int j = 0; j < list.get_size(); j++) {
            cout << matrix.get_data(i, j).weight << " ";
        }   cout << endl;
    }
    cout << endl;
}

void parse_process::list_display_position() {
    adj_node<data_box>* curr = list.get_head();
    while(curr != nullptr) {
        cout << curr -> get_data().node << " ";
        cout << curr -> get_data().x << "," << curr -> get_data().y << "," << curr -> get_data().z << ": ";
        ds_node<data_box>* edge = curr -> get_edges().get_head();
        while(edge != nullptr) {
            cout << edge ->get_data().node << "<" << edge -> get_data().weight << ">" << " ";
            edge = edge -> get_next();
        }   cout << endl;
        curr = curr -> get_next();
    }
}

void parse_process::matrix_display_position() {
    for(int i = 0; i < list.get_size(); i++) {
        for(int j = 0; j < list.get_size(); j++) {
            cout << "<"<< matrix.get_data(i, j).x << "," << matrix.get_data(i, j).y << "," << matrix.get_data(i, j).z << ">" <<  " ";
        }   cout << endl;
    }
    cout << endl;
}