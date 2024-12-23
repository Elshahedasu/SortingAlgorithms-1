#include "InsertionSort.hpp"

// Insertion Sort function
// Sorts a vector in ascending or descending order based on `ascending`
template <typename T>
void insertionSort(Vector<T>& vec, bool ascending) {
    int size = vec.getSize(); // Get the number of elements in the vector

    // Iterate through each element in the vector
    for (int i = 1; i < size; ++i) {
        T current = vec[i]; // Store the current element
        int j = i - 1;

        // Move elements that are greater (ascending) or smaller (descending)
        // to make space for the current element
        while (j >= 0 && ((ascending && vec[j] > current) || (!ascending && vec[j] < current))) {
            vec[j + 1] = vec[j];
            --j;
        }

        // Place the current element in its correct position
        vec[j + 1] = current;
    }
}

// Explicit template instantiation for common types
// These lines ensure the function works for int, double, and char types
template void insertionSort<int>(Vector<int>&, bool);
template void insertionSort<double>(Vector<double>&, bool);
template void insertionSort<char>(Vector<char>&, bool);
