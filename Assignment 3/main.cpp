#include "SortingLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    SortingLinkedList list;

    // Inserting elements
    list.insert(38);
    list.insert(64);
    list.insert(34);
    list.insert(25);

    cout << "Original list: ";
    list.display();
    cout << endl;

    list.selectionSort();
    cout << "Sorted list using Selection Sort: ";
    list.display();
    cout << endl;

    // Re-insert elements for next sort
    list.insert(12);
    list.insert(22);
    list.insert(11);
    list.insert(90);

    list.bubbleSort();
    cout << "Sorted list using Bubble Sort: ";
    list.display();
    cout << endl;

    // Re-insert elements for next sort
    list.insert(23);
    list.insert(11);
    list.insert(59);
    list.insert(16);

    list.insertionSort();
    cout << "Sorted list using Insertion Sort: ";
    list.display();
    cout << endl;

    // Searching elements
    list.linearSearch(25);
    list.binarySearch(59);

    return 0;
}