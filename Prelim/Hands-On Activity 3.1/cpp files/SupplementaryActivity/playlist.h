#ifndef Playlist_H
#define Playlist_H

#include <iostream>

//creating the node structure
template <typename T>
class Playlist{

    public: 
        T data; //holds value of node
        Playlist<T>* next = nullptr; //pointer to the next node
        Playlist<T>* prev = nullptr; //pointer to the previous mode

};

//function for creating a new node
template <typename T>
Playlist<T>* CreateNewNode(T newData){

    Playlist<T>* newNode = new Playlist<T>;

    newNode->data = newData; //assigns value of newNode to newData

    newNode->next = nullptr; //points the node next to new node to nullptr
    newNode->prev = nullptr; //points the node previous to new node to nullptr

    return newNode;
}

//Traverses throughout and prints the list
template <typename T>
void PlaylistTraverse(Playlist<T>* currentHead) {

    //creates a variable of T and assign it as currentHead;
    Playlist<T>* currentNode = currentHead;

    //checks if the current node has nullptr 
    //to determine if the playlist is empty
    if(currentNode == nullptr) {
        std::cout <<"Playlist is empty.";
        return;
    }

    //initializing index
    int i = 0;

    std::cout << "Playlist:\n";

    //prints the songs in the playlist
    do{
        i++;
        std::cout << i << ". " << currentNode->data << std::endl;
        //moves the current node to its next node
        currentNode = currentNode->next;

      //runs until the current node is equal to the current head,
      //which is equivalent to the 'tail' of the list because it is circular.
    } while(currentNode != currentHead);

    //prints the current song playing
    std::cout << "\nNow Playing: " << currentHead->data << std::endl;

    std::cout << std::endl;
}

//function to add songs
//accepts the song name and the head
template <typename T>
void AddSong(T newData, Playlist<T>** currentHead){

    //creates an object of CreateNewNode
    Playlist<T>* newNode = CreateNewNode(newData);

    //prints the value of new node
    std::cout << "Added " << newNode->data << " to playlist.\n";
    
    //checks if the playlist is empty
    if(*currentHead == nullptr){

        //sets the next and previous nodes of newNode to itself
        //this lets the song circle back to the playlist
        newNode->next = newNode;
        newNode->prev = newNode;

        //initially sets the head to the new node
        *currentHead = newNode;
        
        //prints the current song playing
        std::cout << "\nNow Playing: " << (*currentHead)->data << std::endl;

        return;
    }

    // Sets the tail to the head's previous pointer.
    Playlist<T>* tail = (*currentHead)->prev;
    
    //sets the node next to the new node as current head
    newNode->next = *currentHead;
    //sets the node previous to the new node as the previous node to head
    newNode->prev = tail;

    //updates the next node of the tail as the new node
    tail->next = newNode;

    //updates the previous node of the head as the new node
    (*currentHead)->prev = newNode;

    std::cout << "\nNow Playing: " << (*currentHead)->data << std::endl;
}


//function for removing song off the playlist
//accepts the song name and head
template <typename T>
void RemoveSong(T findData, Playlist<T>** currentHead) {

    //checks if the playlist is empty
    if(*currentHead == nullptr){
        std::cout << "Playlist is empty.";
        return;
    }
    //creates a variable of T with the value of the head
    Playlist<T>* currentNode = *currentHead;

    //searches the list the song to be removed
    do{
        //if the node doesn't match the song, it moves to the next node
         currentNode = currentNode->next;
    } while (currentNode->data != findData && currentNode != *currentHead);

    //checks whether the song exists in the playlist
    if(currentNode->data != findData) {
        std::cout << "Invalid input.";
        return;
    }
    //checks if the playlist only has 1 song
    if (currentNode->next == currentNode) {
        *currentHead = nullptr;
        
    // if there is more than 1 song in the playlist   
    } else {
        //Link the previous node directly to the next node
        currentNode->prev->next = currentNode->next;
        //Link the next node directly back to the previous node,
        currentNode->next->prev = currentNode->prev;

        //checks if the song is the head
        if (currentNode == *currentHead) {
            //moves the head to the node next to it
            *currentHead = currentNode->next;
        }
    }
    std::cout << "Removing " << currentNode->data << " from playlist." << std::endl;
    std::cout << "\nNow Playing: " << (*currentHead)->data << std::endl;
    //deallocates the heap memory for currentNode
    delete currentNode;
}

//the function for playing the next song in the playlist
template <typename T>
void Next(Playlist<T>** currentHead){

    //checks if the playlist is empty
    if(*currentHead == nullptr){
        std::cout << "Playlist is empty.";
        return;
    }

    //checks if the playlist contains only 1 song
    if((*currentHead)->next == *currentHead) {
        std::cout << "No song ahead.";
    }

    //the next node of the head becomes the head
    //the previous head becomes the tail
    *currentHead = (*currentHead)->next;

    std::cout << "\nNow Playing: " << (*currentHead)->data << std::endl;

}


//the function for playing the previous song
template <typename T>
void Prev(Playlist<T>** currentHead){

    //checks if the playlist is empty
    if(*currentHead == nullptr){
        std::cout << "Playlist is empty.";
        return;
    }

    //checks if there is only 1 song in the playlist
    if((*currentHead)->prev == *currentHead) {
        std::cout << "No previous song.";
    }

    //assigns the value of the previous head to the current head
    //this puts the previous head before the current head
    *currentHead = (*currentHead)->prev;

    std::cout << "\nNow Playing: " << (*currentHead)->data << std::endl;

}


#endif
