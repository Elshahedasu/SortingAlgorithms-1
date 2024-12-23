#include "QuickSort.hpp"
#include <iostream>

// Partition function
// Divides the array into two parts based on the pivot
template <typename T>
int partition(Vector<T>& arr, int low, int high, bool ascending) {
    T pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;     // Pointer for the smaller element

    // Reorder elements based on the pivot
    for (int j = low; j <= high - 1; j++) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            i++;
            std::swap(arr[i], arr[j]); // Swap elements
        }
    }
    // Place the pivot in its correct position
    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Return the pivot index
}

// Quick Sort function
// Sorts a vector in ascending or descending order using Quick Sort
// If `stepByStep` is true, displays the array after each partition
template <typename T>
void quickSort(Vector<T>& arr, int low, int high, bool ascending, bool stepByStep) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, ascending); // Partition the array

        if (stepByStep) {
            // Print the array after partitioning
            std::cout << "Array after partitioning: ";
            for (int i = 0; i < arr.getSize(); i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        // Recursively sort the left and right parts
        quickSort(arr, low, pivotIndex - 1, ascending, stepByStep);
        quickSort(arr, pivotIndex + 1, high, ascending, stepByStep);
    }
}

// Explicit template instantiation
// Ensures the function works for int, double, and string types
template void quickSort<int>(Vector<int>&, int, int, bool, bool);
template void quickSort<double>(Vector<double>&, int, int, bool, bool);
template void quickSort<std::string>(Vector<std::string>&, int, int, bool, bool);

template int partition<int>(Vector<int>&, int, int, bool);
template int partition<double>(Vector<double>&, int, int, bool);
template int partition<std::string>(Vector<std::string>&, int, int, bool);
