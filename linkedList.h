#pragma once
#include"node.h"

template<typename T>
class LinkedList{
    private:
        Node<T>* head;
        unsigned int size;

    public:
        LinkedList();
        ~LinkedList();
        unsigned int getSize() const;
        bool isEmpty() const;
        void pushFront(const T& value);
        void pushBack(const T& value);
        bool insert(unsigned int index, const T& value);
        bool remove(const T& value);
        Node<T>* elementAt(unsigned int index);
        int getIndex(const T& value);
        void clear();
        void print();
    };

    #include"linkedList.tpp"