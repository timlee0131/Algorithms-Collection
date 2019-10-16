#ifndef DS_ADJLIST_H
#define DS_ADJLIST_H

#include "ds_linklist.h"
#include "ds_node.h"
#include <string>
#include <iostream>
using namespace std;

//templated struct adjacency list instead of having an adjacency list class
template <class U> struct adj_node {
template <class T> friend class ds_adjlist;
private:
    U data;
    ds_linklist<U> edges;
    adj_node<U>* next;
    adj_node<U>* prev;
public:
    //Constructors
    adj_node() {next = prev = nullptr;}
    adj_node(U val) {data = val; next = prev = nullptr;}
    adj_node<U>& operator=(const adj_node<U>& temp_node) {
        next = prev = nullptr;

        this -> data = temp_node -> data;
        this -> edges = temp_node -> edges;
        this -> next = temp_node -> next;
        this -> prev = temp_node -> prev;

        return *this;
    }

    //Utility functions
    void insert_node(const U val) {edges.insert_back(val);}
    ds_linklist<U>& get_edges() {return edges;}
    adj_node<U>*& get_next() {return next;}
    adj_node<U>*& get_prev() {return prev;}
    U& get_data() {return data;}
};  //END OF STRUCT DS_ADJLIST

template <class T> class ds_adjlist {
private:
    adj_node<T>* head;
    adj_node<T>* tail;
    int size;
public:
    //Constructors
    ds_adjlist();
    ~ds_adjlist();
    ds_adjlist<T>& operator=(const ds_adjlist<T>&);

    //Utility functions
    adj_node<T>*& get_head();
    adj_node<T>*& get_tail();
    int get_size();
    adj_node<T>* find(T val);
    void insert_back(const T);
    void insert_back(const T, const T);
    adj_node<T>* operator[](int);
    void display();
};

//Constructor functions
template <class T> ds_adjlist<T>::ds_adjlist() {head = tail = nullptr; size = 0;}

template <class T> ds_adjlist<T>::~ds_adjlist() {
    adj_node<T>* curr = this -> head;
    while(curr != nullptr) {
        adj_node<T>* temp = curr;
        curr = curr -> next;
        delete temp;
    }
}

template <class T> ds_adjlist<T>& ds_adjlist<T>::operator=(const ds_adjlist<T>& temp_list) {
    head = tail = nullptr;
    size = temp_list.size;
    adj_node<T>* curr = temp_list.head;
    while(curr !=  nullptr) {
        for(int i = 0; i < curr -> edges.get_size(); i++) {
            insert_back(curr -> data, curr -> edges[i]);
        }

        curr = curr -> next;
    }
    return *this;
}

//Utility functions
template <class T> adj_node<T>*& ds_adjlist<T>::get_head() {return head;}
template <class T> adj_node<T>*& ds_adjlist<T>::get_tail() {return tail;}
template <class T> int ds_adjlist<T>::get_size() {return size;}

template <class T> adj_node<T>* ds_adjlist<T>::find(T val) {
    adj_node<T>* curr = this -> head;
    int position = 0;
    while(curr != nullptr) {
        if(curr -> data == val)     return curr;
        curr = curr -> next;
        position++;
    }
    return curr; 
}

template <class T> void ds_adjlist<T>::insert_back(const T val) {
    adj_node<T>* node = new adj_node<T>(val);
    if(tail != nullptr) {
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    } else {
        head = node;
        tail = node;
    }   size++;
}

template <class T> void ds_adjlist<T>::insert_back(const T val1, const T val2) {
    if(this -> head == nullptr) {
        insert_back(val1);
        this -> head -> get_edges().insert_back(val2);
    } else {
        if(find(val1)  == nullptr) {
            insert_back(val1);
            find(val1) -> get_edges().insert_back(val2);
        } else {
            find(val1) -> get_edges().insert_back(val2);
        }
    }
}

template <class T> adj_node<T>* ds_adjlist<T>::operator[](int index) {
    adj_node<T>* curr = this -> head;
    int position = 0;
    while(curr != nullptr) {
        if(position == index)   return curr;
        curr = curr -> next;
        position++;
    }
    return nullptr;
}

#endif