#include <iostream>
#include "doubly_ll.h"

int main() {

    //Create a list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second; //points head to second (<-head->second->)
    second->prev = head;  //points second to head

    second->next = third;
    third->prev = second;

    //traversal
    std::cout << "\nTesting the DLL Traversal: \n";
    dllTraverse(head);
    std::cout << std::endl;

    //testing the insert at the head
    std::cout << "Testing the insertion at the head node: \n";
    dllInsertHead('X', &head);
    dllTraverse(head);
    std::cout << std::endl;

    //testing the insert at the end
    std::cout << "Testing the insertion at the end node: \n";
    dllInsertEnd('O', head);
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "Testing the DLL General Insertion: \n";
    dllGeneralInsert('G', head->next->next);
    dllTraverse(head);

    std::cout << "Testing the DLL Delete Node: \n";
    dllDeleteNode('G', &head);
    dllTraverse(head);

}   
