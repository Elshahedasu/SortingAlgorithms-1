#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "Vector.hpp"
#include <iostream>
#include <string>

template <typename T>
void quickSort(Vector<T>& arr, int low, int high, bool ascending = true, bool stepByStep = false);

template <typename T>
int partition(Vector<T>& arr, int low, int high, bool ascending);

#endif
