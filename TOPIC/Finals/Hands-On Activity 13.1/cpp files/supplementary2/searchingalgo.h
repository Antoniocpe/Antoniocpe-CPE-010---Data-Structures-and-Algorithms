#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include "node.h"
#include <iostream>

template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end, int& comparisons) {
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != end && fast->next != end) {
        comparisons += 2; 
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


template<typename T>
int RecBinarySearchArr(T data[], int low, int high, T dataFind, int iteration, int& comparisons) { 
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2; 
    
    comparisons++; 
    if (dataFind == data[mid]) {
        return mid;
    }
    
    comparisons++; 
    if (dataFind < data[mid]) {
        return RecBinarySearchArr(data, low, mid - 1, dataFind, iteration + 1, comparisons);
    }
    else {
        return RecBinarySearchArr(data, mid + 1, high, dataFind, iteration + 1, comparisons);
    }
}

template<typename T>
int binarySearchArr(T data[], int arrSize, T dataFind, int& comparisons) {
    comparisons = 0;
    return RecBinarySearchArr(data, 0, arrSize - 1, dataFind, 1, comparisons);
}

template <typename T>
bool binarySearchLL(Node<T>* start, T dataFind, int& comparisons) {
    comparisons = 0;
    Node<T>* last = nullptr;
    
    while (start != last) {
        Node<T>* middle = getMiddle(start, last, comparisons);

        comparisons++;
        if (middle->data == dataFind) {
            return true;
        }
        
        comparisons++;
        if (middle->data > dataFind) {
            last = middle;
        }
        else {
            start = middle->next; 
        }
    }

    return false; 
}

template<typename T>
int linearSearch(int size, T item, T array[], int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (array[i] == item) {
            return i; 
        }
    }
    return -1; 
}

template<typename T>
bool linearSearchLL(Node<T>* headNode, T dataToBeFound, int& comparisons) {
    comparisons = 0;
    Node<T>* current = headNode;
    
    while (current != nullptr) {
        comparisons++;
        if (current->data == dataToBeFound) {
            return true;
        }
        current = current->next;
    }
    return false;
}

#endif // SEARCHINGALGO_H