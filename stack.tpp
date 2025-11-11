#pragma once

#include "stack.h"
#include<iostream>

template<typename T>
Stack<T>::Stack(){
    topNode = nullptr;
    count = 0;
}

template<typename T>
Stack<T>::~Stack(){
    while(topNode){
        Node<T>* temp = nullptr;
        temp = topNode;
        topNode = topNode->next;
        delete temp;
        temp = nullptr;
    }
    count = 0;
}

template<typename T>
void Stack<T>::push(const T& valor){
    Node<T>* newNode = new Node(valor);
    if(!topNode){
        topNode = newNode;
    }else{
        newNode->next = topNode;
        topNode = newNode;
        ++count;
    }
}

template<typename T>
T Stack<T>::pop(){
    if(isEmpty()){
        std::cout<<"Empty stack";
        return T{};
    }else{
        Node<T>* tempTopNode = topNode;
        T tempData = topNode->data;
        topNode = topNode->next;
        delete tempTopNode;
        tempTopNode = nullptr;
        --count;
        return tempData;
    }

}

template<typename T>
T Stack<T>::top(){
    if(isEmpty()){
        std::cout<<"Empty stack";
        return T{};
    }else{
        return topNode->data;
    }

}


template<typename T>
bool Stack<T>::isEmpty(){
    return topNode == nullptr;
}


template<typename T>
void Stack<T>::print(){
    if(isEmpty()){
        std::cout<<"Empty stack";
        return;
    }
    Node<T>* current = topNode;
    std::cout<<"[";
    while(current){
        std::cout<<" "<<current->data;
        if(current->next){
            std::cout<<" ->";
        }
        current = current->next;
    }
    std::cout<<" ]\n";
}
