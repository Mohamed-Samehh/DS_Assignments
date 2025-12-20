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

    tail->setNext(newNode);
    newNode->setPrev(tail);
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
        head = head->getNext();
        head->setPrev(NULL);
    }

    // Target is the tail
    else if (target == tail)
    {
        tail = tail->getPrev();
        tail->setNext(NULL);
    }

    // Target is in the middle
    else
    {
        Node *prevNode = target->getPrev();
        Node *nextNode = target->getNext();

        if (prevNode != NULL)
            prevNode->setNext(target->getNext());

        if (nextNode != NULL)
            nextNode->setPrev(target->getPrev());
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
        if (curr->getData() == val)
        {
            Node *temp = curr;
            curr = curr->getNext();
            removeElement(temp->getData());
        }
        else
        {
            curr = curr->getNext();
        }
    }
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
        if (curr->getData() == val)
            return curr;

        curr = curr->getNext();
    }

    cout << "Element not found" << endl;
    return NULL;
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
        cout << curr->getData() << " ";

        curr = curr->getNext();
    }
}

LinkedList::~LinkedList()
{
    while (head != NULL)
    {
        Node *curr = head;
        head = head->getNext();
        delete curr;
    }
}