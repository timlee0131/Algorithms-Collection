#ifndef DS_ADJMATRIX_H
#define DS_ADJMATRIX_H

#include <string>
#include <iostream>
using namespace std;

template <class U> struct matrix_node {
template <class T> friend class ds_adjmatrix;
    bool existence;
    int src = 0;
    int dest = 0;
    U data;

    U get_data() {
        return data;
    }
    U& operator=(const U& d2) {
        cout << "gets to here" << endl;
        data.node = d2.node;
        data.weight = d2.weight;
        data.x = d2.x;
        data.y = d2.y;
        data.z = d2.z;

        existence = d2.existence;
        src = d2.src;
        dest = d2.dest;
        return *this;
    }
    void set_copy(bool e, int s, int d) {
        existence = e;
        src = s;
        dest = d;
    }
    bool get_existence() {return existence;}
    int get_src() {return src;}
    int get_dest() {return dest;}
};

template <class T> class ds_adjmatrix {
private:
    matrix_node<T>** matrix;
    int vertices;
public:
    //Constructors
    ds_adjmatrix();
    ds_adjmatrix(int);
    ds_adjmatrix(const ds_adjmatrix<T>&);
    ~ds_adjmatrix();

    //Utility functions
    void add_edge(int, int, T);
    void remove_edge(int, int);
    bool edge_exists(int, int);
    int get_existence(int, int);
    T get_data(int, int);
    matrix_node<T> find(T val);
    matrix_node<T>**& get_matrix() {return matrix;};
    int get_vertices() {return vertices;}

    ds_adjmatrix<T> operator=(const ds_adjmatrix<T>);
};

//Constructor functions
template <class T> ds_adjmatrix<T>::ds_adjmatrix() {vertices = 0;}

template <class T> ds_adjmatrix<T>::ds_adjmatrix(int v) {
    this -> vertices = v;
    matrix = new matrix_node<T>*[vertices];
    for(int i = 0; i < vertices; i++) {
        matrix[i] = new matrix_node<T>[vertices];
    }
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) { 
            matrix[i][j].existence = false;
            matrix[i][j].src = i;
            matrix[i][j].dest = j;
        }
    }
}

template<class T> ds_adjmatrix<T>::ds_adjmatrix(const ds_adjmatrix<T>& matrix_temp) {
    vertices = matrix_temp.vertices;
    matrix = new matrix_node<T>*[vertices];
    for(int i = 0; i < vertices; i++) {
        matrix[i] = new matrix_node<T>[vertices];
    }
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) { 
            matrix[i][j].existence = false;
            matrix[i][j].src = i;
            matrix[i][j].dest = j;
        }
    }
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            matrix[i][j] = matrix_temp.matrix[i][j];
        }
    }
}

template <class T> ds_adjmatrix<T>::~ds_adjmatrix() {
    for(int i = 0; i < vertices; i++) {
        delete [] matrix[i];
    }   delete [] matrix;
}

template <class T> ds_adjmatrix<T> ds_adjmatrix<T>::operator=(const ds_adjmatrix<T> matrix_temp) {
    vertices = matrix_temp.vertices;
    matrix = new matrix_node<T>*[vertices];
    for(int i = 0; i < vertices; i++) {
        matrix[i] = new matrix_node<T>[vertices];
    }
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) { 
            matrix[i][j].existence = false;
            matrix[i][j].src = i;
            matrix[i][j].dest = j;
        }
    }
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            matrix[i][j] = matrix_temp.matrix[i][j];
            // matrix[i][j].existence = matrix_temp.matrix[i][j].existence;
            // matrix[i][j].src = matrix_temp.matrix[i][j].src;
            // matrix[i][j].dest = matrix_temp.matrix[i][j].dest;
            // matrix[i][j].data = matrix_temp.matrix[i][j].data;
        }
    }

    return *this;
}

//Utility functions
template <class T> void ds_adjmatrix<T>::add_edge(int e1, int e2, T val) {
    if(e1 >= 0 && e1 < vertices && e2 >= 0 && e2 < vertices) {
        matrix[e1][e2].existence = true;
        matrix[e1][e2].data = val;
    }
}

template <class T> matrix_node<T> ds_adjmatrix<T>::find(T val) {
    int i = 0;
    int j = 0;
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            if(matrix[i][j].data == val)
                return matrix[i][j];
        }
    }
    return matrix[i-1][j-1];
}

template <class T> void ds_adjmatrix<T>::remove_edge(int e1, int e2) {if(e1 >= 0 && e1 < vertices && e2 >= 0 && e2 < vertices) matrix[e1][e2].existence = false;}

template <class T> bool ds_adjmatrix<T>::edge_exists(int e1, int e2) {return matrix[e1][e2].existence;}

template <class T> int ds_adjmatrix<T>::get_existence(int e1, int e2) {if(edge_exists(e1, e2))  return 1; else  return 0;}

template <class T> T ds_adjmatrix<T>::get_data(int e1, int e2) {return matrix[e1][e2].get_data();}

#endif