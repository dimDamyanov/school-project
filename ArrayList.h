#pragma once

template <class T>
class ArrayList {
public:
    // Constructor to initialize the arraylist.
    ArrayList();

    // Destructor to clean up the memory.
    ~ArrayList();

    // Returns an element on a given index, null if index invalid.
    T get(int index);

    // Returns index of a given element, null if element not in arraylist.
    int indexOf(T &e);

    // Pushes an element at the end of the arraylist.
    void push_back(T &e);

    // Inserts an element at a given index.
    void insert(int index, T &e);

    // Deletes an element at a given index.
    void remove(int index);

    // Clears the arraylist.
    void clear();

    // Returns whether an element is in the arraylist.
    bool contains(T &e);

    // Returns whether the arraylist is empty.
    bool isEmpty();

    // Returns the size of the arraylist.
    inline int size() { return count; }

private:
    int arrayListSize;  // Size of the arraylist.
    int count;          // Number of elements in the arraylist.
    T *data = nullptr;  // Pointer to the data.

    // Checks whether the arraylist needs expansion.
    bool needsExpansion();

    // Expands the arraylist.
    void expand();

    // Returns whether index is in range (0 -> size).
    bool isValidIndex(int index);

};
