#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

void LinkedList::addElement(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void LinkedList::removeElement(int val)
{
    Node *target = findElement(val);

    // Element not found
    if (target == NULL)
        return;

    // Only one element in the list
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }

    // Target is the head
    else if (target == head)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
    }

    // Target is the tail
    else if (target == tail)
    {
        tail = tail->prev;
        if (tail)
            tail->next = NULL;
    }

    // Target is in the middle
    else
    {
        Node *prevNode = target->prev;
        Node *nextNode = target->next;

        if (prevNode != NULL)
            prevNode->next = target->next;

        if (nextNode != NULL)
            nextNode->prev = target->prev;
    }

    delete target;
}

void LinkedList::removeAll(int val)
{
    if (head == NULL)
    {
        cout << "No elements inserted yet" << endl;
        return;
    }

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            Node *temp = curr;
            curr = curr->next;
            removeElement(temp->data);
        }
        else
        {
            curr = curr->next;
        }
    }
}

void LinkedList::insertAfter(Node *target, int val)
{
    Node *NewNode = new Node(val);

    NewNode->next = target->next;

    if (target->next)
        target->next->prev = NewNode;
    else
        tail = NewNode;

    target->next = NewNode;
    NewNode->prev = target;
}

void LinkedList::insertBefore(Node *target, int val)
{
    Node *NewNode = new Node(val);

    if (target == head)
    {
        NewNode->next = target;
        target->prev = NewNode;
        head = NewNode;
        return;
    }

    NewNode->prev = target->prev;

    if (target->prev)
        target->prev->next = NewNode;

    target->prev = NewNode;
    NewNode->next = target;
}

Node *LinkedList::findElement(int val)
{
    if (head == NULL)
    {
        cout << "No elements inserted yet" << endl;
        return NULL;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == val)
            return curr;

        curr = curr->next;
    }

    cout << "Element not found" << endl;
    return NULL;
}

int LinkedList::getDataByIndex(int index)
{
    Node *curr = head;

    for (int i = 0; i < index && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return -1;
    }

    return curr->data;
}

int LinkedList::getCount()
{
    Node *curr = head;
    int count = 0;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    return count;
}

void LinkedList::displayList()
{
    if (head == NULL)
    {
        cout << "No elements to show" << endl;
        return;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";

        curr = curr->next;
    }
}

LinkedList::~LinkedList()
{
    while (head != NULL)
    {
        Node *curr = head;
        head = head->next;
        delete curr;
    }
}