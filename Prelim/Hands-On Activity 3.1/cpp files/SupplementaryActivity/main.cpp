#include <iostream>
#include <string>

#include "playlist.h"

int main() {

    //initial ptr of head is set to nullptr
    Playlist<std::string>* head = nullptr;
    std::string song; //the name of the song
    int choice; //for choosing which command to execute

    //loops until the input is 'x'
    do {
        //the 'control panel'
        std::cout << "===========================" << std::endl;
        std::cout << "Select Command:\n(1)Add Song\n(2)Remove Song\n(3)Next\n(4)Previous\n(5)Display All Songs" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cin >> choice;

        switch(choice){
            //adds a song to the playlist
            case 1:
                std::cout << "Add song: " << std::endl;
                std::cin >> song;

                AddSong<std::string>(song, &head);
            break;

            //removes the chosen song from the playlist
            case 2:
                std::cout << "Remove song: " << std::endl;
                std::cin >> song;
                RemoveSong<std::string>(song, &head);
            break;

            //moves the current song forward and becomes the tail
            //movese the previous song forward and becomes the head
            case 3:
                Next(&head);
            break;

            //moves the previous song to the front and becomes the head
            case 4:
                Prev(&head);
            break;

            case 5:
            //prints all the songs in order
                PlaylistTraverse(head);
            break;
        }

    } while (choice != 'x');
}

