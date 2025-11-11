#pragma once
#include"node.h"

template<typename T>
class Queue{
    private:
        Node<T>* topNode;
        Node<T>* tail;
        unsigned int size;
    public:
        Queue();
        ~Queue();
        void enqueue(const T& valor);
        T dequeue();
        T getFirst();
        bool isEmpty();
        void print();
};

#include"queue.tpp"