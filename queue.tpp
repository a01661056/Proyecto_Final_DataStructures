#pragma once

#include"queue.h"
#include<iostream>

template<typename T>
Queue<T>::Queue(){
    topNode = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
Queue<T>::~Queue(){
    while(topNode){
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        temp = nullptr;
    }
    size = 0;    
}       

template<typename T>
void Queue<T>::enqueue(const T& valor){
    Node<T>* newNode = new Node<T>(valor);
    if(isEmpty()){
        topNode = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }   
    ++size;   
}

template<typename T>
T Queue<T>::dequeue(){
    if(isEmpty()){
        std::cout<<"Empty queue\n";
        return T{};
    }else{
        Node<T>* tempTopNode = topNode;
        T tempData = topNode->data;
        topNode = topNode->next;
        
        if(topNode == nullptr){
            tail = nullptr;
        }
    
        delete tempTopNode;
        tempTopNode = nullptr;
        --size;
        return tempData;
    }
}       

template<typename T>
T Queue<T>::getFirst(){
    if(isEmpty()){
        std::cout<<"Empty queue\n";
        return T{};
    }
    return topNode->data;
}       

template<typename T>
bool Queue<T>::isEmpty(){
    return topNode == nullptr;
} 

template<typename T>
void Queue<T>::print(){
    if(isEmpty()){
        std::cout<<"Empty queue\n";
    }else{
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
}