#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    this->top = -1;
    this->data = new int[capacity];
}

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
        return;
    }

    ++top;
    data[top] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return data[top--];
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == capacity - 1;
}

void Stack::display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

Stack::~Stack()
{
    delete[] data;
}