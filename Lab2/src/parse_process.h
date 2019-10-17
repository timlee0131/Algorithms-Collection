#ifndef PARSE_PROCESS_H
#define PARSE_PROCESS_H

#include <string>
#include "ds_adjlist.h"
#include "ds_adjmatrix.h"
using namespace std;

struct data_box {
    int node;
    double weight = 0.0;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    friend bool operator==(data_box& d1, data_box& d2) {
        if(d1.node == d2.node)      return true;
        else                        return false;
    }

    friend bool operator<(data_box& d1, data_box& d2) {
        if(d1.node < d2.node)   return true;
        else                    return false;
    }

    friend bool operator<(const data_box& d1, const data_box& d2) {
        if(d1.node < d2.node)   return true;
        else                    return false;
    }
};

class parse_process {
private:
    ds_adjlist<data_box> list;
    ds_adjmatrix<data_box> matrix;
public:
    void parse_graph(string, string, string);               //Parse first file. Directed list no weights.
    void list_display();
    void matrix_display();

    void list_display_weight();
    void matrix_display_weight();

    void list_display_position();
    void matrix_display_position();

    ds_adjlist<data_box>& get_list() {return list;};
    ds_adjmatrix<data_box>& get_matrix() {return matrix;};
};

#endif