#ifndef DATA_SET_GENERATION_H
#define DATA_SET_GENERATION_H

#include <string>
#include <fstream>
using namespace std;

class data_set_generation {
public:
    void random(string filename, string filename2, string filename3, string filename4);
    void reversed(string filename, string filename2, string filename3, string filename4);
    void semi_unique(string filename, string filename2, string filename3, string filename4);
    void semi_sorted(string filename, string filename2, string filename3, string filename4);
};

#endif