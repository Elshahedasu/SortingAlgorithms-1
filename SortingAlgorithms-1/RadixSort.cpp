#include "RadixSort.hpp"
#include <cmath> // For mathematical operations like division and modulus

// Get the maximum value in the vector
// Finds the largest number in the vector
template <typename T>
T getMaxValue(const Vector<T>& vector) {
    T maxValue = vector[0]; // Start with the first element
    for (int i = 1; i < vector.getSize(); i++) {
        if (vector[i] > maxValue) {
            maxValue = vector[i]; // Update maxValue if a larger number is found
        }
    }
    return maxValue;
}

// Perform counting sort based on a specific digit
// Sorts the vector based on the digit at `digitPlace` (e.g., 1's, 10's, etc.)
template <typename T>
void countingSortByDigit(Vector<T>& vector, int digitPlace, bool ascending) {
    int size = vector.getSize();
    Vector<T> sortedVector(size); // Temporary vector to hold sorted values
    int countArray[10] = {0};     // Array to count occurrences of each digit (0-9)

    // Count occurrences of each digit
    for (int i = 0; i < size; i++) {
        int digit = (vector[i] / digitPlace) % 10;
        countArray[digit]++;
    }

    // Update countArray for proper positions (ascending or descending)
    if (ascending) {
        for (int i = 1; i < 10; i++) {
            countArray[i] += countArray[i - 1];
        }
    } else {
        for (int i = 8; i >= 0; i--) {
            countArray[i] += countArray[i + 1];
        }
    }

    // Build the sorted vector
    for (int i = size - 1; i >= 0; i--) {
        int digit = (vector[i] / digitPlace) % 10;
        sortedVector[--countArray[digit]] = vector[i];
    }

    // Copy the sorted vector back to the original vector
    for (int i = 0; i < size; i++) {
        vector[i] = sortedVector[i];
    }
}

// Radix Sort function
// Sorts the vector in ascending or descending order using Radix Sort
template <typename T>
void radixSort(Vector<T>& vector, bool ascending) {
    if (vector.getSize() == 0) return; // Do nothing if the vector is empty

    T maxValue = getMaxValue(vector); // Find the largest number in the vector

    // Perform counting sort for each digit (1's, 10's, 100's, etc.)
    for (int digitPlace = 1; maxValue / digitPlace > 0; digitPlace *= 10) {
        countingSortByDigit(vector, digitPlace, ascending);
    }
}

// Explicit template instantiation for integer types
template void radixSort<int>(Vector<int>&, bool);
