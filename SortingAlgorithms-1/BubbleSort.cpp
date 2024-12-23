#include "BubbleSort.hpp"

// Bubble Sort function
// Sorts a vector in ascending or descending order based on `ascending`
template <typename T>
void bubbleSort(Vector<T>& vec, bool ascending) {
    int n = vec.getSize(); // Get the number of elements in the vector

    // Repeat for all elements
    for (int i = 0; i < n - 1; i++) {
        // Compare each pair of elements
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the elements are in the wrong order
            if ((ascending && vec[j] > vec[j + 1]) || (!ascending && vec[j] < vec[j + 1])) {
                T temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

// Make the function work for int, double, and char
template void bubbleSort<int>(Vector<int>&, bool);
template void bubbleSort<double>(Vector<double>&, bool);
template void bubbleSort<char>(Vector<char>&, bool);
