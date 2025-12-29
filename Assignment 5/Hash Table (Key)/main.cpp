#include "HashTable.h"
#include <iostream>

using namespace std;

int main()
{
    HashTable a(10);
    a.insert(15);
    a.insert(10);
    a.insert(115); // Collision
    a.insert(215); // Collision

    a.search(215) ? cout << "Found" << endl : cout << "Not Found" << endl;
    a.search(10) ? cout << "Found" << endl : cout << "Not Found" << endl;
    a.search(45) ? cout << "Found" << endl : cout << "Not Found" << endl;
    a.search(15) ? cout << "Found" << endl : cout << "Not Found" << endl;
    a.search(22) ? cout << "Found" << endl : cout << "Not Found" << endl;

    a.display();

    return 0;
}