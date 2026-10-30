#include <utility>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template <typename T>
void shellSort(T arr[], size_t n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {
            int temp = arr[i];  
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

template <typename T>
void mergeSort(T arr[], int left, int mid, int right) {

    int n1 = mid-left + 1;
    int n2 = right - mid;

    int* Left = new int[n1];
    int* Right = new int[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j]) arr[k++] = Left[i++];
        else arr[k++] = Right[j++];
    }

    while (i < n1) arr[k++] = Left[i++];

    while (j < n2) arr[k++] = Right[j++];

    delete[] Left;
    delete[] Right;
}

template <typename T>
void sort(T arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        mergeSort(arr, left, mid, right);
    }
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif