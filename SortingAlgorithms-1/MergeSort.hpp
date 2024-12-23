#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "Vector.hpp"

// Merge two sorted subarrays
template <typename T>
void merge(Vector<T>& vector, int start, int mid, int end, bool isAscending);

// Perform merge sort on a vector
template <typename T>
void mergeSort(Vector<T>& vector, int start, int end, bool isAscending);

#endif // MERGESORT_HPP
