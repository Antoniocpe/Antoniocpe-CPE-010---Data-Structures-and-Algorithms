#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <iomanip>

#include "node.h"
#include "searchingAlgo.h"

const int DATA_SIZE = 1000000;


int main() {
    srand(static_cast<unsigned int>(time(0)));

    int* dataset = new int[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        dataset[i] = rand() % 1000000;
    }

    std::sort(dataset, dataset + DATA_SIZE);

    int target = -1;

    std::cout << "Searching Algorithm Comparison (" << DATA_SIZE << " Elements)\n";
    std::cout << "Target: " << target << "\n";

    int linearOps = 0;
    int binaryOps = 0;

    auto startLinear = std::chrono::high_resolution_clock::now();
    linearSearch(DATA_SIZE, target, dataset, linearOps);
    auto endLinear = std::chrono::high_resolution_clock::now();
    auto timeLinear = std::chrono::duration_cast<std::chrono::nanoseconds>(endLinear - startLinear).count();


    auto startBinary = std::chrono::high_resolution_clock::now();
    binarySearchArr(dataset, DATA_SIZE, target, binaryOps); 
    auto endBinary = std::chrono::high_resolution_clock::now();
    auto timeBinary = std::chrono::duration_cast<std::chrono::nanoseconds>(endBinary - startBinary).count();

    // --- RESULTS TABLE ---
    std::cout << std::left << std::setw(18) << "Algorithm" 
              << std::setw(18) << "Comparisons" 
              << "Execution Time\n";
    std::cout << std::left << std::setw(18) << "Linear Search" 
              << std::setw(18) << linearOps 
              << timeLinear << " ns\n";
    std::cout << std::left << std::setw(18) << "Binary Search" 
              << std::setw(18) << binaryOps 
              << timeBinary << " ns\n";

    delete[] dataset;
    return 0;
}