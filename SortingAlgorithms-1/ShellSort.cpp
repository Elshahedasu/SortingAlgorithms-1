#include "ShellSort.hpp"

// Shell Sort function
// Sorts a vector in ascending or descending order
template <typename T>
void shellSort(Vector<T>& vec, bool ascending) {
    int n = vec.getSize(); // Get the number of elements in the vector

    // Start with a big gap and reduce it each time
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a modified insertion sort for elements separated by the gap
        for (int i = gap; i < n; i++) {
            T temp = vec[i]; // Store the current element
            int j;

            // Compare and shift elements in the gap sequence
            for (j = i; j >= gap && ((ascending && vec[j - gap] > temp) || (!ascending && vec[j - gap] < temp)); j -= gap) {
                vec[j] = vec[j - gap];
            }

            // Place the current element in its correct position
            vec[j] = temp;
        }
    }
}

// Explicit instantiation for common types
// These lines ensure the function works for int, double, and char types
template void shellSort<int>(Vector<int>&, bool);
template void shellSort<double>(Vector<double>&, bool);
template void shellSort<char>(Vector<char>&, bool);
