#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main(){

     //create an array with unsorted list
    int unsortedArr[maxSize];

    //use time(0) as seed for random values
    srand(time(0));

    //populate the array with random values
    for (int i = 0; i < maxSize; i++){
     unsortedArr[i] = rand()%100;
    }

    std::cout << "Unsorted Array: \n";
    displayArr(unsortedArr);
    std::cout << std::endl;

/*
    std::cout << "Shell sort: " << std::endl;
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    std::cout << std::endl;
*/

/*
    std::cout << "Merge sort: " << std::endl;
    sort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);
    std::cout << std::endl;
*/

    std::cout << "Quick sort: " << std::endl;
    sort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);
    std::cout << std::endl;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
}
