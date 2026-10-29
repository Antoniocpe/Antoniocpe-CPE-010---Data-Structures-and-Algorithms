#include <iostream>
#include "singly_ll.h"

int main() {

    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    head->data = 'T';
    second->data = 'I';
    third->data = 'N';
    fourth->data = 'E';

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << "Testing of Traversal: \n";
    ListTraversal(head);

    std::cout << "Testing of sllGeneralInsert: \n";
    sllGeneralInsert('X', second);
    ListTraversal(head);

    std::cout <<"Testing of sllInsertHead: \n"; 
    sllInsertHead('S', &head);
    ListTraversal(head);

    std::cout <<"Testing of sllInsertEnd: \n"; 
    sllInsertEnd('E', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting the node: \n";
    sllDeleteNode('T', &head);
    ListTraversal(head);


    std::cout << "deleting ALL nodes: \n";
    DeleteList(&head);
    ListTraversal(head);

    return 0;
}