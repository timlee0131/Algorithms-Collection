#ifndef DS_NODE_H
#define DS_NODE_H

template <class T> class ds_node {
template <class U> friend class ds_linklist;
private:
    T data;
    ds_node<T>* next;
    ds_node<T>* prev;
public:
    ds_node();
    ds_node(T);
    ds_node(ds_node<T>*);

    ds_node<T>*& get_prev();
    ds_node<T>*& get_next();
    T& get_data();
};

template <class T> ds_node<T>::ds_node() {next = prev = nullptr;}

template <class T> ds_node<T>::ds_node(T d) {next = prev = nullptr; data = d;}

template <class T> ds_node<T>::ds_node(ds_node<T>* node) {next = prev = nullptr; data = node -> data;}

template <class T> ds_node<T>*& ds_node<T>::get_next() {return next;}

template <class T> ds_node<T>*& ds_node<T>::get_prev() {return prev;}

template <class T> T& ds_node<T>::get_data() {return data;}

#endif