#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
    BinarySearchTree bst;

    bst.add(50);
    bst.add(30);
    bst.add(70);
    bst.add(20);
    bst.add(40);
    bst.add(60);
    bst.add(80);

    cout << "50 in tree? ";
    bst.checkDataInTree(50) != false ? cout << "Found" << endl : cout << "Not Found" << endl;

    cout << "25 in tree? ";
    bst.checkDataInTree(25) != false ? cout << "Found" << endl : cout << "Not Found" << endl;

    cout << "45 in tree? ";
    bst.checkDataInTree(30) != false ? cout << "Found" << endl : cout << "Not Found" << endl;

    cout << "60 in tree? ";
    bst.checkDataInTree(60) != false ? cout << "Found" << endl : cout << "Not Found" << endl;

    cout << "Tree traversal (LDR): ";
    bst.traverse();
    cout << endl;

    cout << "Max Depth of tree: " << bst.getMaxDepth() << endl;

    return 0;
}