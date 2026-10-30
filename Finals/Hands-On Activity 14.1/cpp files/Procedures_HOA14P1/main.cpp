#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include "sortingAlgo.h"

const int maxSize = 100;    // size of the random array
const int caseSize = 128;   // size used for best/worst case (power of 2 so shell sort's worst case is exact)
const int runs = 10000;     // how many times each case is timed

void displayArr(const int arr[], int size);

// ---------- sorting wrappers (same signature so one timer can use both) ----------
void mergeSort(int a[], int n) { sort(a, 0, n - 1); }
void shell(int a[], int n)     { shellSort(a, n); }

// ---------- worst case builders ----------
// merge sort: rearranges a SORTED range so every merge alternates left/right
void mergeWorst(int a[], int tmp[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    int li = l, ri = m + 1;
    for (int i = l; i <= r; i++) {
        if ((i - l) % 2 == 0) tmp[li++] = a[i];
        else                  tmp[ri++] = a[i];
    }
    for (int i = l; i <= r; i++) a[i] = tmp[i];
    mergeWorst(a, tmp, l, m);
    mergeWorst(a, tmp, m + 1, r);
}

// shell sort (n/2 gaps, n a power of 2): small values on even positions, large on odd
void shellWorst(int a[], int n) {
    int lo = 0, hi = n / 2;
    for (int i = 0; i < n; i++) a[i] = (i % 2 == 0) ? lo++ : hi++;
}

// ---------- timing ----------
// prints the average time (ns) of sortFn on a copy of arr
void time_complex(const int arr[], int size, void (*sortFn)(int[], int)) {
    long long total = 0;
    std::vector<int> copy(size);

    for (int r = 0; r < runs; r++) {
        copy.assign(arr, arr + size);               // fresh copy each run (not timed)

        auto begin = std::chrono::steady_clock::now();
        sortFn(copy.data(), size);
        auto end = std::chrono::steady_clock::now();

        total += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }

    std::cout << total / runs << " nanoseconds\n";
}

int main() {
    int unsortedArr[maxSize];

    srand(time(0));
    for (int i = 0; i < maxSize; i++) unsortedArr[i] = rand() % 100;

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr, maxSize);

    // sort copies so both algorithms get the same unsorted data
    int shellArr[maxSize], mergeArr[maxSize];
    for (int i = 0; i < maxSize; i++) shellArr[i] = mergeArr[i] = unsortedArr[i];

    std::cout << "\nShell sort:\n";
    shellSort(shellArr, maxSize);
    displayArr(shellArr, maxSize);

    std::cout << "\nMerge sort:\n";
    sort(mergeArr, 0, maxSize - 1);
    displayArr(mergeArr, maxSize);

    // ---------- best and worst case ----------
    int bestArr[caseSize], mergeWorstArr[caseSize], shellWorstArr[caseSize], tmp[caseSize];

    for (int i = 0; i < caseSize; i++) mergeWorstArr[i] = bestArr[i] = i;   // already sorted
    mergeWorst(mergeWorstArr, tmp, 0, caseSize - 1);
    shellWorst(shellWorstArr, caseSize);

    std::cout << "\nTime complexity for n = " << caseSize
              << " (average of " << runs << " runs):\n";

    std::cout << "\nMerge sort\n";
    std::cout << "  Best case  O(n log n) - already sorted: ";
    time_complex(bestArr, caseSize, mergeSort);
    std::cout << "  Worst case O(n log n) - interleaved:    ";
    time_complex(mergeWorstArr, caseSize, mergeSort);

    std::cout << "\nShell sort\n";
    std::cout << "  Best case  O(n log n) - already sorted: ";
    time_complex(bestArr, caseSize, shell);
    std::cout << "  Worst case O(n^2)     - interleaved:    ";
    time_complex(shellWorstArr, caseSize, shell);
}

void displayArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}