#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList() {
    arrayListSize = 2;
    count = 0;
    data = new T[arrayListSize];
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete []data;
}

template <class T>
T ArrayList<T>::get(int index) {
    if (!isValidIndex(index))
        return 0;
    return data[index];
}

template <class T>
int ArrayList<T>::indexOf(T &e) {
    for (int i = 0; i < size(); i++) {
        if (data[i] == *e)
            return i;
    }
    return -1;
}

template <class T>
void ArrayList<T>::push_back(T &e) {
    if (needsExpansion())
        expand();
    data[count++] = e;
}

template <class T>
void ArrayList<T>::insert(int index, T &e) {
    if (needsExpansion())
        expand();
    if (!(index >= 0 && index <= size()))
        return;
    for (int i = size() - 1; i >= 0; i--) {
        if (i >= index)
            data[i + 1] = data[i];
    }
    data[index] = e;
    count++;
}

template <class T>
void ArrayList<T>::remove(int index) {
    if (!isValidIndex(index))
        return;
    for (int i = index + 1; i < size(); i++)
        data[i - 1] = data[i];
    
    data[count--] = nullptr;
}

template <class T>
bool ArrayList<T>::contains(T &e) {
    return indexOf(e) >= 0;
}

template <class T>
void ArrayList<T>::clear() {
    count = 0;
    arrayListSize = 2;
    delete []data;
    *data = new T[arrayListSize];
}

template<class T>
bool ArrayList<T>::isEmpty() {
    return size() == 0;
}

template<class T>
bool ArrayList<T>::needsExpansion() {
    return size() >= arrayListSize;
}

template<class T>
void ArrayList<T>::expand() {
    arrayListSize *= 2;
    T *newData = new T[arrayListSize];
    for (int i = 0; i < size(); i++) {
        newData[i] = data[i];
    }
    delete []data;
    data = newData;
}

template<class T>
bool ArrayList<T>::isValidIndex(int index) {
    return (index >= 0 && index < size());
}
