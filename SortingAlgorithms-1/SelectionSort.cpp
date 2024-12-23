#include "SelectionSort.hpp"
#include <iostream>

// Selection Sort function
// Sorts a vector in ascending or descending order
// If `stepbystep` is true, shows each step of the sorting process
template <typename T>
void SelectionSort(Vector<T>& vec, bool ascending, bool stepbystep) {
    int n = vec.getSize(); // Get the number of elements in the vector

    // Outer loop to iterate through each position in the vector
    for (int i = 0; i < n - 1; i++) {
        int selectedIndex = i; // Start with the current index as selected

        // Find the smallest (ascending) or largest (descending) element
        for (int j = i + 1; j < n; j++) {
            if (ascending ? vec[j] < vec[selectedIndex] : vec[j] > vec[selectedIndex]) {
                selectedIndex = j; // Update the selected index
            }
        }

        // Swap the selected element with the current element
        if (selectedIndex != i) {
            T temp = vec[i];
            vec[i] = vec[selectedIndex];
            vec[selectedIndex] = temp;
        }

        // Show each step of sorting if `stepbystep` is enabled
        if (stepbystep) {
            std::cout << "Step " << i + 1 << ": ";
            for (int k = 0; k < vec.getSize(); k++) {
                std::cout << vec[k] << " ";
            }
            std::cout << std::endl;
            std::cout << "Press Enter to continue to the next step...\n";
            std::cin.get(); // Wait for user input
        } else {
            std::cout << "Step " << i + 1 << ": ";
            for (int k = 0; k < vec.getSize(); k++) {
                std::cout << vec[k] << " ";
            }
            std::cout << std::endl;
        }
    }
}

// Explicit template instantiation for common types
// These lines ensure the function works for int, double, and char types
template void SelectionSort<int>(Vector<int>&, bool, bool);
template void SelectionSort<double>(Vector<double>&, bool, bool);
template void SelectionSort<char>(Vector<char>&, bool, bool);
