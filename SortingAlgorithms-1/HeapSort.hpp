#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "Vector.hpp"

// Heapify function
template <typename T>
void heapify(Vector<T>& vec, int n, int i, bool ascending);

// Heap sort function
template <typename T>
void heapSort(Vector<T>& vec, bool ascending = true);

#endif
