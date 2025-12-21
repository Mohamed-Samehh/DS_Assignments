#include "QueueLinkedList.h"
#include <iostream>

using namespace std;

QueueLinkedList::QueueLinkedList()
{
    front = NULL;
    rear = NULL;
    size = 0;
}

void QueueLinkedList::enqueue(int item)
{
    // Create New Node
    Node *newNode = new Node(item);

    // If Queue is Empty
    if (size == 0)
    {
        front = rear = newNode;
        size++;
        return;
    }

    // Add New Node at Rear
    rear->next = newNode;
    rear = newNode;
    size++;
}

int QueueLinkedList::dequeue()
{
    if (size == 0)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }

    // Backup Front
    Node *temp = front;

    // Move Front Forward
    front = front->next;

    // Delete Old Front
    int data = temp->data;
    delete temp;
    size--;

    // If Queue Becomes Empty
    if (size == 0)
    {
        rear = NULL;
    }

    return data;
}

void QueueLinkedList::display()
{
    if (size == 0)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    Node *curr = front;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

QueueLinkedList::~QueueLinkedList()
{
    Node *curr = front;

    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
}