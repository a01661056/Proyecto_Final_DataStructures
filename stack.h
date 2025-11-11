#pragma once

#include"node.h"

template<typename T>
class Stack{
    private:
        Node<T>* topNode;
        unsigned int count;
    public:
        Stack();
        ~Stack();
        void push(const T& valor);
        T pop();
        T top();
        bool isEmpty();
        void print();
};

#include "stack.tpp"