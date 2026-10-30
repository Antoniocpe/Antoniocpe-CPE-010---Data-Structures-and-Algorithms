#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{

    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

//creating a node
template <typename T>
DoubleList<T> *CreateNewNode(T newData){

    //dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;

    //store the data in the node
    newNode->data = newData;

    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    //return the address of the newly created node;
    return newNode;

}

//Traversal
template <typename T>
void dllTraverse(DoubleList<T>* currentNode) {

    DoubleList<T> *tail;
    
    //check if list is empty
    if (currentNode == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    //move forward
    std::cout << "Forward: \n";
    while (currentNode != nullptr) { 
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    //add next line
    std::cout << std::endl;

    //move backward
    std::cout << "Backward: \n";
    while (tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;

}

//insertion
template <typename T>
void dllInsertHead (T newData, DoubleList<T>** currentHead) {
    //creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //new node should point to the current head
    newNode->next = *currentHead;

    //current Head should point back to the newNode
    (*currentHead)->prev = newNode;

    //update the pointer head
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead) {
    //create new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //traverse until last node reached
    while (currentHead->next != nullptr) {
        currentHead = currentHead->next;
    }

    //connect the last node to the new node
    currentHead->next = newNode;

    //connect the new node back to the last node
    newNode->prev = currentHead;

}

//general insert
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* previousNode){

    DoubleList<T>* newNode = CreateNewNode(newData);

    if (previousNode == nullptr) {
        std::cout << "Previous value cannot be null" << std::endl;
        return;
    }

    //store data in new node
    newNode->data = newData;

    newNode->next = previousNode->next;
    newNode ->prev = previousNode;

    //previous node to new node
    previousNode->next = newNode;

}


//delete node
template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    
    if (*head == nullptr) return;

    DoubleList<T>* currNode = *head;

    while(currNode != nullptr && currNode->data != findData) {
        currNode = currNode->next;
    }


    if (currNode->prev == nullptr){
        *head = currNode->next;
        
        if(*head != nullptr){
            (*head)->prev = nullptr;
        }
    } else {
        currNode->prev->next = currNode->next;

        if(currNode->next != nullptr) {
            currNode->next->prev = currNode->prev;
        }
    }

    delete currNode;
}



#endif