#include <iostream>
#include "Vector.hpp"
#include "BubbleSort.cpp"
#include "CountingSort.cpp"
#include "HeapSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "RadixSort.cpp"
#include "SelectionSort.cpp"
#include "ShellSort.cpp"

void displayVector(Vector<int>& vector) {
  for (int i = 0; i < vector.getSize(); ++i) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int userChoice;
  bool isAscending;

  int vectorSize;
  std::cout << "Enter the size of the vector: ";
  std::cin >> vectorSize;

  // User-input vector
  Vector<int> vector(vectorSize);
  std::cout << "Enter " << vectorSize << " elements:\n";
  for (int i = 0; i < vectorSize; ++i) {
    std::cin >> vector[i];
  }

  while (true) {
    std::cout << "\nChoose Sorting Algorithm:\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Counting Sort\n";
    std::cout << "3. Heap Sort\n";
    std::cout << "4. Insertion Sort\n";
    std::cout << "5. Merge Sort\n";
    std::cout << "6. Quick Sort\n";
    std::cout << "7. Radix Sort\n";
    std::cout << "8. Selection Sort\n";
    std::cout << "9. Shell Sort\n";
    std::cin >> userChoice;

    if (userChoice == 0) {
      std::cout << "Exiting program.\n";
      break;
    }

    std::cout << "Sort in ascending order? (1 for Yes, 0 for No): ";
    std::cin >> isAscending;

    switch (userChoice) {
    case 1: // Bubble Sort
      bubbleSort(vector, isAscending);
      std::cout << "After Bubble Sort: ";
      displayVector(vector);
      break;

    case 2: // Counting Sort
      countingSort(vector, isAscending);
      std::cout << "After Counting Sort: ";
      displayVector(vector);
      break;

    case 3: // Heap Sort
      heapSort(vector, isAscending);
      std::cout << "After Heap Sort: ";
      displayVector(vector);
      break;

    case 4: // Insertion Sort
      insertionSort(vector, isAscending);
      std::cout << "After Insertion Sort: ";
      displayVector(vector);
      break;

    case 5: // Merge Sort
      mergeSort(vector, 0, vector.getSize() - 1, isAscending);
      std::cout << "After Merge Sort: ";
      displayVector(vector);
      break;

    case 6: // Quick Sort
      quickSort(vector, 0, vector.getSize() - 1, isAscending, false);
      std::cout << "After Quick Sort: ";
      displayVector(vector);
      break;

    case 7: // Radix Sort
      radixSort(vector, isAscending);
      std::cout << "After Radix Sort: ";
      displayVector(vector);
      break;

    case 8: // Selection Sort
      SelectionSort(vector, isAscending);
      std::cout << "After Selection Sort: ";
      displayVector(vector);
      break;

    case 9: // Shell Sort
      shellSort(vector, isAscending);
      std::cout << "After Shell Sort: ";
      displayVector(vector);
      break;

    default:
      std::cout << "Invalid choice. Please choose between 0 and 9.\n";
    }

    system("pause"); // Pause the program before continuing
    system("cls");   // Clear the screen for the next operation
  }

  return 0;
}