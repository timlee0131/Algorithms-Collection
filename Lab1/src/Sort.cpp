#include "Sort.h"

void Sort::load(string filename) {
    ifstream input(filename);
    string temp;
    file_vector.clear();
    while(input >> temp) {
        int temp_converted;
        temp_converted = stoi(temp);
        file_vector.push_back(temp_converted);
    }
}

void Sort::execute() {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    (*algorithms[algorithm_selecter])(file_vector);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    double time_span_ms = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    execution_time = time_span_ms;
}

void Sort::select(int n) {
    algorithm_selecter = n;
}

void Sort::save(string filepath) {
    ofstream output(filepath);
    for(int i = 0; i < file_vector.size(); i++) {
        output << file_vector[i] << " ";
        if(i != 0 && i % 10 == 0)   output << endl;
    }
}

void Sort::stat() {
    if(algorithm_selecter == 0) {
        cout << "Bubble Sort" << endl;
        cout << "Execution time: " << execution_time << " microseconds" << endl;
        cout << "Number of records analyzed: " << file_vector.size() << " elements" << endl;
    }
    else if(algorithm_selecter == 1) {
        cout << "Merge Sort" << endl;
        cout << "Execution time: " << execution_time << " microseconds" << endl;
        cout << "Number of records analyzed: " << file_vector.size() << " elements" << endl;
    }
     else {
        cout << "Insertion Sort" << endl;
        cout << "Execution time: " << execution_time << " microseconds" << endl;
        cout << "Number of records analyzed: " << file_vector.size() << " elements" << endl;
     }
}

void Sort::display() {
    for(int i = 0; i < file_vector.size(); i++) {
        cout << file_vector[i] << " ";
        if(i != 0 && i % 10 == 0)   cout << endl;
    }cout << endl;
}