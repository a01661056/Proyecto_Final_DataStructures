#include"linkedList.h"
#include"node.h"
#include<iostream>

template<typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}


template<typename T>
LinkedList<T>::~LinkedList(){
    clear();
}


template<typename T>
unsigned int LinkedList<T>::getSize() const{
    return size;
}


template<typename T>
bool LinkedList<T>::isEmpty() const{
    return size == 0;
}
   

template<typename T>
void LinkedList<T>::pushFront(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if(!head){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    ++size;
}


template<typename T>
void LinkedList<T>::pushBack(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if(!head){
        head = newNode;
    }else{
        Node<T>* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}


template<typename T>
bool LinkedList<T>::insert(unsigned int index, const T& value){
    if(index > size) return false;

    if(index == 0){
        pushFront(value);
        return true;
    }

    Node<T>* current = head;
    for(int i = 0;i<index-1;i++){
        current = current->next;
    }
    Node<T>* newNode = new Node<T>(value);
    newNode->next = current->next;
    current->next = newNode;
    ++size;
    return true;
}


template<typename T>
bool LinkedList<T>::remove(const T& value){
    if(head->data == value){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        --size;
        return true;
    }

    Node<T>* current = head;
    Node<T>* temp = nullptr;
    for(int i = 0; i<size-1; i++){
        if(current->next->data == value){
            temp = current->next;
            current->next = current->next->next;
            delete temp;
            temp = nullptr;
            --size;
            return true;
        }else{
            current = current->next;
        }
    }
    return false;
}


template<typename T>
Node<T>* LinkedList<T>::elementAt(unsigned int index){
    Node<T>* current = head;
    for(int i = 0; i<index; i++){
        current = current->next;
    }

    return current;
}


template<typename T>
int LinkedList<T>::getIndex(const T& value){
    int index = 0;
    Node<T>* current = head;
    for(int i = 0; i<size; i++){
        if(current->data == value){
            return index;
        }else{
            current = current->next;
            index++;
        }
    }
    return -1;
}


template<typename T>
void LinkedList<T>::clear(){
    if(isEmpty()){
        return;
    }
    Node<T>* temp = head;
    for(int i = 0; i<size; i++){
        temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
    size = 0;
}


template<typename T>
void LinkedList<T>::print(){
    if(isEmpty()){
        std::cout<<"Lista vacia"<<std::endl;
    }else{
        const Node<T>* current = head;
        std::cout<<"[";
        while(current){
            std::cout<<" "<<current->data;
            if(current->next){
                std::cout<<" ->";
            }
            current = current->next;
        }
        std::cout<<" ]";
    }
}