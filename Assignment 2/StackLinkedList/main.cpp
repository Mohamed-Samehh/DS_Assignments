#include <iostream>
#include "StackLinkedList.h"

using namespace std;

int main()
{
    StackLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack elements: ";
    stack.display();

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}