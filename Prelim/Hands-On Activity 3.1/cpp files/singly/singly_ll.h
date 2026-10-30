#ifndef SINGLY_LL_H

template <typename T>
class SingleList{
    public:
    T data;
    SingleList<T>* next = nullptr;
};


//traverses through the single linked list
template <typename T>
void ListTraversal(SingleList<T>* head) {

    //checks if the list is empty
    if(head == nullptr) {
        std::cout << "The list is empty.";
        return;
    }

    //prints the list by looping until the head is nullptr
    while(head != nullptr){
        //prints the value of the head
        std::cout << head->data;
        //prints "->" if the next node is not nullptr
        if(head->next != nullptr){
            std::cout << "->";
        }

        //assigns the next node of head as the head
        //this lets the head travel to the end of the list
        head = head->next;
        
    }
    std::cout << std::endl;
}

//General Insert
//takes the value of the node and the previous node,
//where the new node will be inserted after it
template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* prevNode){
    
    //checks if the previous node is pointing to nullptr
    if(prevNode == nullptr) {
        std::cout << "Previous value cannot be null\n";
        return;
    }

    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData; //assigns the input as the newNode value
    newNode->next = prevNode->next; //copies the value next node of the new node as itself
    prevNode->next = newNode; //replaces the current node as the new node

}

//insert head
template <typename T>
void sllInsertHead(T newData, SingleList<T>** currentHead){
    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;

    //copies the currentHead to the next of NewNode
    newNode->next = *currentHead;

    //sets the currentHead to newNode
    *currentHead = newNode;

}

//inserts node at the end of the list
template <typename T>
void sllInsertEnd(T newData, SingleList<T>** currentHead){
    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    //if the list is empty, the inserted node will be the head
    if (*currentHead == nullptr) {
        *currentHead = newNode;
    }

    //temporary storage that copes the current head
    SingleList<T>* temp = *currentHead;
    //checks if the current head is at the end of the list,
    while (temp->next != nullptr) {
        //if not, the next node will be set as the node
        temp = temp->next;
    }

    //if the node is at the end of the list,
    //adds the new node at the end of the list
    temp->next = newNode;
        
}

//deletes a node from the list
template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head){

    //checks if the list is empty
    if (*head == nullptr) return;

    //sets the current node as the head
    SingleList<T>* currNode = *head;
    //makes the previous node point to nullptr
    SingleList<T>* prevNode = nullptr;

    //searches the list by checking
    //if the node is not pointing to nullptr and
    //if the node matches the value
    while(currNode != nullptr && currNode->data != findData) {
        //while false,
        //sets the current node as the previous node
        prevNode = currNode;
        //moves the current node to its next node
        currNode = currNode->next;

    }

    if (prevNode == nullptr) {
        //moves the head to the front
        *head = currNode->next;
    } else {
        
        prevNode->next = currNode->next;
    }
    delete currNode;
}


//deletes the contents of the list
template <typename T>
void DeleteList(SingleList<T>** head) {
    
    //loops until the list is empty
    while (*head != nullptr){

        SingleList<T>* prev = nullptr;

        //prev contains a copy of head
        prev = *head;
        //the next node of head becomes the head iself
        *head = (*head)->next;

        //deallocates the prev from the heap
        delete prev;
    }
}


#endif