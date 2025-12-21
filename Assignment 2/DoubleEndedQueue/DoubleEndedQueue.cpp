#include "DoubleEndedQueue.h"
#include <iostream>

using namespace std;

DoubleEndedQueue::DoubleEndedQueue(int capacity)
{
    rear = -1;
    front = -1;
    size = 0;
    this->capacity = capacity;
    items = new int[capacity];
}

void DoubleEndedQueue::enqueueRear(int item)
{
    if (size == capacity) // Check Full
    {
        cout << "Queue is full" << endl;
        return;
    }

    if (size == 0) // First Element
    {
        rear = 0;
        front = 0;
    }

    else // Normal Case
    {
        rear = (rear + 1) % capacity;
    }

    items[rear] = item;
    size++;
}

void DoubleEndedQueue::enqueueFront(int item)
{
    if (size == capacity) // Check Full
    {
        cout << "Queue is full" << endl;
        return;
    }

    if (size == 0) // First Element
    {
        rear = 0;
        front = 0;
    }

    else // Normal Case
    {
        // if front is 0 (first index), it wraps around to capacity - 1 (last index)
        front = (front - 1 + capacity) % capacity;
    }

    items[front] = item;
    size++;
}

int DoubleEndedQueue::dequeueFront()
{
    if (size == 0) // Check Empty
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    // Backup Item
    int temp = items[front];

    if (size == 1) // Only one element
    {
        front = -1;
        rear = -1;
    }

    else // Normal case
    {
        front = (front + 1) % capacity;
    }

    size--;

    return temp;
}

int DoubleEndedQueue::dequeueRear()
{
    if (size == 0) // Check Empty
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    // Backup Item
    int temp = items[rear];

    if (size == 1) // Only one element
    {
        front = -1;
        rear = -1;
    }

    else // Normal case
    {
        rear = (rear - 1 + capacity) % capacity;
    }

    size--;

    return temp;
}

void DoubleEndedQueue::display()
{
    if (size == 0)
    {
        cout << "No elements to display" << endl;
        return;
    }

    int curr = front;
    for (int i = 0; i < size; ++i)
    {
        cout << items[curr] << " ";
        curr = (curr + 1) % capacity;
    }
    cout << endl;
}

DoubleEndedQueue::~DoubleEndedQueue()
{
    delete[] items;
}