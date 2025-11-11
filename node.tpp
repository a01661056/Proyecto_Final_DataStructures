#pragma once

#include"node.h"

template <typename T>
Node<T>::Node(const T& valor){
    data = valor;
    next = nullptr;
}