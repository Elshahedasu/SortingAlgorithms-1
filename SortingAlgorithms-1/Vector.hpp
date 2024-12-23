#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

// A dynamic array class template
template <typename T>
class Vector {
public:
    Vector();                        // Default constructor
    Vector(int initialSize);         // Constructor with initial size
    Vector(int initialSize, T value); // Constructor with initial size and value
    ~Vector();                       // Destructor

    void push_back(const T& value);  // Add an element to the vector
    void resize(int newSize);        // Resize the vector
    int getSize() const;             // Get the current number of elements
    T& operator[](int index);        // Access an element (modifiable)
    const T& operator[](int index) const; // Access an element (read-only)

private:
    T* myArray;    // Pointer to the dynamic array
    int size;      // Current number of elements
    int capacity;  // Total allocated capacity
};

// Implementation of member functions

// Default constructor: initializes an empty vector with a default capacity of 10
template <typename T>
Vector<T>::Vector() : size(0), capacity(10) {
    myArray = new T[capacity];
}

// Constructor with initial size: creates a vector of given size
template <typename T>
Vector<T>::Vector(int initialSize) : size(initialSize), capacity(initialSize) {
    myArray = new T[capacity];
}

// Constructor with initial size and value: creates a vector and fills it with the value
template <typename T>
Vector<T>::Vector(int initialSize, T value) : size(initialSize), capacity(initialSize) {
    myArray = new T[capacity];
    for (int i = 0; i < size; i++) {
        myArray[i] = value;
    }
}

// Destructor: frees the dynamically allocated memory
template <typename T>
Vector<T>::~Vector() {
    delete[] myArray;
}

// Add an element to the end of the vector
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size >= capacity) { // Resize if necessary
        resize(size + 1);
    }
    myArray[size++] = value;
}

// Resize the vector to a new size
template <typename T>
void Vector<T>::resize(int newSize) {
    if (newSize > capacity) { // Increase capacity if needed
        capacity = newSize * 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = myArray[i];
        }
        delete[] myArray; // Free old memory
        myArray = newArray;
    }
    size = newSize;
}

// Get the current number of elements in the vector
template <typename T>
int Vector<T>::getSize() const {
    return size;
}

// Access an element by index (modifiable version)
template <typename T>
T& Vector<T>::operator[](int index) {
    return myArray[index];
}

// Access an element by index (read-only version)
template <typename T>
const T& Vector<T>::operator[](int index) const {
    return myArray[index];
}

#endif // VECTOR_HPP
