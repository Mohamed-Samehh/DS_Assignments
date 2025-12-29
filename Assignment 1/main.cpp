#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedList list;

    list.addElement(10);
    list.addElement(20);
    list.insertAfter(list.findElement(20), 30);
    list.addElement(40);
    list.insertBefore(list.findElement(40), 20);
    list.addElement(20);
    list.addElement(20);

    cout << "Initial List: ";
    list.displayList();
    cout << endl;

    cout << "Removing element 20" << endl;
    list.removeElement(20);
    cout << "List after removal: ";
    list.displayList();
    cout << endl;

    cout << "Removing all occurrences of 20" << endl;
    list.removeAll(20);
    cout << "List after removing all occurrences: ";
    list.displayList();
    cout << endl;

    int searchVal = 30;
    Node *foundNode = list.findElement(searchVal);
    if (foundNode != NULL)
        cout << "Element " << searchVal << " found in the list." << endl;
    else
        cout << "Element " << searchVal << " not found in the list." << endl;

    cout << "Data of node in index 1: " << list.getDataByIndex(1) << endl;
    cout << "Count of nodes in the list: " << list.getCount() << endl;

    return 0;
}