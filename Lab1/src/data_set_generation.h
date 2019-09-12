#ifndef DATA_SET_GENERATION_H
#define DATA_SET_GENERATION_H

#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
using namespace std;

class data_set_generation {
public:
    void random(string filename, string filename2, string filename3, string filename4);
    void reversed(string filename, string filename2, string filename3, string filename4);
    void semi_unique(string filename, string filename2, string filename3, string filename4);
    void semi_sorted(string filename, string filename2, string filename3, string filename4);
    void generate();
};

#endif