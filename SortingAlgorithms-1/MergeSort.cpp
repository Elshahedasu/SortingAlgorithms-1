#include "MergeSort.hpp"

// Merge two sorted subarrays
// Combines two sorted parts of the vector into one sorted part
template <typename T>
void merge(Vector<T>& vector, int start, int mid, int end, bool isAscending) {
    int leftSize = mid - start + 1;  // Size of the left subarray
    int rightSize = end - mid;      // Size of the right subarray

    // Temporary vectors for left and right subarrays
    Vector<T> leftSubarray(leftSize);
    Vector<T> rightSubarray(rightSize);

    // Copy elements into the temporary vectors
    for (int i = 0; i < leftSize; ++i)
        leftSubarray[i] = vector[start + i];
    for (int i = 0; i < rightSize; ++i)
        rightSubarray[i] = vector[mid + 1 + i];

    int leftIndex = 0, rightIndex = 0, mergedIndex = start;

    // Merge the two subarrays back into the main vector
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if ((isAscending && leftSubarray[leftIndex] <= rightSubarray[rightIndex]) ||
            (!isAscending && leftSubarray[leftIndex] >= rightSubarray[rightIndex])) {
            vector[mergedIndex++] = leftSubarray[leftIndex++];
        } else {
            vector[mergedIndex++] = rightSubarray[rightIndex++];
        }
    }

    // Add any remaining elements from the left subarray
    while (leftIndex < leftSize) {
        vector[mergedIndex++] = leftSubarray[leftIndex++];
    }

    // Add any remaining elements from the right subarray
    while (rightIndex < rightSize) {
        vector[mergedIndex++] = rightSubarray[rightIndex++];
    }
}

// Perform merge sort on a vector
// Recursively divides the vector into halves, sorts them, and merges them
template <typename T>
void mergeSort(Vector<T>& vector, int start, int end, bool isAscending) {
    if (start < end) {
        int mid = start + (end - start) / 2; // Find the midpoint

        // Sort the left half
        mergeSort(vector, start, mid, isAscending);

        // Sort the right half
        mergeSort(vector, mid + 1, end, isAscending);

        // Merge the two halves
        merge(vector, start, mid, end, isAscending);
    }
}

// Explicit template instantiation for common types
// Ensures the function works for int, double, and char types
template void mergeSort<int>(Vector<int>&, int, int, bool);
template void mergeSort<double>(Vector<double>&, int, int, bool);
template void mergeSort<char>(Vector<char>&, int, int, bool);
