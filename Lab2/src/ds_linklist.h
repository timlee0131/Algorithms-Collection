#ifndef DS_LINKLIST_H
#define DS_LINKLIST_H

#include <iostream>
#include "ds_node.h"
using namespace std;

template <class T> class ds_linklist {
private:
    ds_node<T>* head;
    ds_node<T>* tail;
    int size;
public:
    //constructor/operator overwrite
    ds_linklist();
    ds_linklist(T);
    ds_linklist(const ds_linklist<T>&);
    ds_linklist<T> operator=(const ds_linklist<T>);
    ~ds_linklist();

    //utilities functions
    void insert_back(const T val);
    void pop_back();
    ds_node<T>* find(T val);
    void display();
    T& operator[](int);

    ds_node<T>*& get_head() {return head;};
    ds_node<T>*& get_tail() {return tail;};
    int get_size() {return size;}
};

//Constructors
template <class T> ds_linklist<T>::ds_linklist() {head = tail = nullptr; size = 0;}

template <class T> ds_linklist<T>::ds_linklist(T data) {head = tail = new ds_node<T>(data); size = 1;}

template <class T> ds_linklist<T>::ds_linklist(const ds_linklist<T>& list) {
    head = tail = nullptr;
    size = 0;
    ds_node<T>* curr = list.head;
    while(curr != nullptr) {
        insert_back(curr -> data);
        curr = curr -> data;
    }
}

template <class T> ds_linklist<T> ds_linklist<T>::operator=(ds_linklist<T> list) {
    head = tail = nullptr;
    size = 0;
    ds_node<T>* curr = list.head;
    while(curr != nullptr) {
        insert_back(curr -> data);
        curr = curr -> next;
    }

    return *this;
}

template <class T> T& ds_linklist<T>::operator[](int index) {
    ds_node<T>* curr = this -> head;
    int position = 0;
    while(curr != nullptr) {
        if(position == index)   return curr -> data;
        curr = curr -> next;
        position++;
    }
    return curr -> data;
}

template <class T> ds_linklist<T>::~ds_linklist() {
    ds_node<T>* curr = this -> head;
    while(curr != nullptr) {
        ds_node<T>* temp = curr;
        curr = curr -> next;
        delete temp;
    }
}

//Utilities functions
template <class T> void ds_linklist<T>::insert_back(const T val) {
    ds_node<T>* node = new ds_node<T>(val);
    if(tail != nullptr) {
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    } else {
        head = node;
        tail = node;
    } size++;
}

template <class T> void ds_linklist<T>::pop_back() {
    if(head == nullptr || tail == nullptr)  return;
    else if(head == tail) {
        ds_node<T>* temp = this -> head;
        this -> head = this -> head -> next;
        delete temp;
    } else {
        ds_node<T>* temp = tail;
        temp -> prev -> next = temp -> next;
        tail = temp -> prev;
        delete temp;
    } size--;
}

template <class T> ds_node<T>* ds_linklist<T>::find(T val) {
    ds_node<T>* curr = this -> head;
    int position = 0;
    while(curr != nullptr) {
        if(curr -> data == val)     return curr;
        curr = curr -> next;
        position++;
    }
    return curr;
}

template <class T> void ds_linklist<T>::display() {
    ds_node<T>* curr = this -> head;
    while(curr != nullptr) {
        std::cout << curr -> data << " ";
        curr = curr -> next;
    }std::cout << endl;
}

#endif