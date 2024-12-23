#include "CountingSort.hpp"
#include <stdexcept>

// Counting Sort function
// Only works for integer vectors
template <>
void countingSort(Vector<int>& vec, bool ascending) {
    if (vec.getSize() == 0) return; // Do nothing if the vector is empty

    // Find the smallest and largest numbers in the vector
    int min = vec[0], max = vec[0];
    for (int i = 1; i < vec.getSize(); ++i) {
        if (vec[i] > max) max = vec[i];
        if (vec[i] < min) min = vec[i];
    }

    // Create an array to count the occurrences of each number
    int range = max - min + 1;
    int* countArr = new int[range](); // Initialize all counts to 0

    // Count how many times each number appears
    for (int i = 0; i < vec.getSize(); ++i) {
        countArr[vec[i] - min]++; // Adjust index by subtracting min
    }

    // Rebuild the vector in sorted order
    int index = 0;
    if (ascending) {
        // Fill in numbers in ascending order
        for (int i = 0; i < range; ++i) {
            while (countArr[i]-- > 0) {
                vec[index++] = i + min;
            }
        }
    } else {
        // Fill in numbers in descending order
        for (int i = range - 1; i >= 0; --i) {
            while (countArr[i]-- > 0) {
                vec[index++] = i + min;
            }
        }
    }

    delete[] countArr; // Free the memory used by countArr
}

// Template for unsupported types
// Throws an error if counting sort is used for non-integer types
template <typename T>
void countingSort(Vector<T>& vec, bool ascending) {
    throw std::invalid_argument("Counting sort is only supported for integer types.");
}
