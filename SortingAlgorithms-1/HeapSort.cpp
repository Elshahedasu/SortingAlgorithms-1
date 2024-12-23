#include "HeapSort.hpp"

// Swap function
// Swaps the values of two elements
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Heapify function
// Ensures the heap property is maintained at a specific node
template <typename T>
void heapify(Vector<T>& vec, int n, int i, bool ascending) {
    int largestOrSmallest = i; // Root of the subtree
    int left = 2 * i + 1;      // Left child
    int right = 2 * i + 2;     // Right child

    // Check if the left child is larger (ascending) or smaller (descending)
    if (left < n) {
        if (ascending) {
            if (vec[left] > vec[largestOrSmallest]) {
                largestOrSmallest = left;
            }
        } else {
            if (vec[left] < vec[largestOrSmallest]) {
                largestOrSmallest = left;
            }
        }
    }

    // Check if the right child is larger (ascending) or smaller (descending)
    if (right < n) {
        if (ascending) {
            if (vec[right] > vec[largestOrSmallest]) {
                largestOrSmallest = right;
            }
        } else {
            if (vec[right] < vec[largestOrSmallest]) {
                largestOrSmallest = right;
            }
        }
    }

    // If the root is not the largest or smallest, swap and heapify again
    if (largestOrSmallest != i) {
        swap(vec[i], vec[largestOrSmallest]);
        heapify(vec, n, largestOrSmallest, ascending);
    }
}

// Heap Sort function
// Sorts a vector in ascending or descending order using heap sort
template <typename T>
void heapSort(Vector<T>& vec, bool ascending) {
    int n = vec.getSize();

    // Build the heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(vec, n, i, ascending);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(vec[0], vec[i]);     // Move the root (largest or smallest) to the end
        heapify(vec, i, 0, ascending); // Rebuild the heap for the remaining elements
    }
}

// Explicit template instantiation for common types
// These lines ensure the function works for int and double types
template void heapSort<int>(Vector<int>&, bool);
template void heapSort<double>(Vector<double>&, bool);
