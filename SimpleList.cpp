#include "SimpleList.h"
#include <stdexcept>
#include <type_traits>
#include <string> // Ensure this is included for std::string

// Constructor
template <class T>
SimpleList<T>::SimpleList() : numElements(0) {
    elements = new T[CAPACITY];
}

// Destructor
template <class T>
SimpleList<T>::~SimpleList() {
    if constexpr (std::is_pointer<T>::value) {
        for (int i = 0; i < numElements; ++i) {
            delete elements[i];
        }
    }
    delete[] elements;
}

// at(int index)
template <class T>
T SimpleList<T>::at(int index) const {
    if (index < 0 || index >= numElements) {
        throw InvalidIndexException();
    }
    return elements[index];
}

// empty()
template <class T>
bool SimpleList<T>::empty() const {
    return numElements == 0;
}

// first()
template <class T>
T SimpleList<T>::first() const {
    if (empty()) {
        throw EmptyListException();
    }
    return elements[0];
}

// last()
template <class T>
T SimpleList<T>::last() const {
    if (empty()) {
        throw EmptyListException();
    }
    return elements[numElements - 1];
}

// getNumElements()
template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

// insert(T item)
template <class T>
void SimpleList<T>::insert(T item) {
    if (numElements >= CAPACITY) {
        throw FullListException();
    }
    elements[numElements++] = item;
}

// remove(int index)
template <class T>
void SimpleList<T>::remove(int index) {
    if (empty()) {
        throw EmptyListException();
    }
    if (index < 0 || index >= numElements) {
        throw InvalidIndexException();
    }
    for (int i = index; i < numElements - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    --numElements;
}