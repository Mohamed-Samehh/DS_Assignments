#include "HashTable.h"
#include <iostream>

using namespace std;

int main()
{
    HashTable table(10);

    table.insert("Test1", "One");
    table.insert("Test2", "Two");
    table.insert("Test3", "Three");
    table.display();

    cout << endl;

    table.search("Test1") ? cout << "Found" << endl : cout << "Not Found" << endl;
    table.search("Test") ? cout << "Found" << endl : cout << "Not Found" << endl;

    cout << endl;

    table.remove("Test2");
    table.display();
}