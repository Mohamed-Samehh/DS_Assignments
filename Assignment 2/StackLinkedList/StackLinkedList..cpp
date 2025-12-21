#include "StackLinkedList.h"
#include <iostream>

using namespace std;

StackLinkedList::StackLinkedList()
{
    tail = NULL;
}

void StackLinkedList::push(int data)
{
    // Create New Node
    Node *newNode = new Node(data);
    newNode->prev = tail;

    // Update Tail
    tail = newNode;
}

int StackLinkedList::pop()
{
    if (tail == NULL)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    // Backup Tail
    Node *temp = tail;

    // Move Tail Back
    tail = tail->prev;
    int data = temp->data;

    // Delete Tail
    delete temp;
    return data;
}

void StackLinkedList::display()
{
    if (tail == NULL)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    Node *curr = tail;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

StackLinkedList::~StackLinkedList()
{
    Node *curr = tail;

    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->prev;
        delete temp;
    }
}