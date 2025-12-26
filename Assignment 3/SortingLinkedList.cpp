#include "SortingLinkedList.h"
#include <iostream>

using namespace std;

SortingLinkedList::SortingLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
}

void SortingLinkedList::insert(int data)
{
    Node *NewNode = new Node(data);

    if (!head && !tail)
    {
        head = NewNode;
        tail = NewNode;
        size++;
        return;
    }

    NewNode->prev = tail;
    tail->next = NewNode;
    tail = tail->next;
    size++;
}

Node *SortingLinkedList::linearSearch(int data)
{
    Node *curr = head;

    for (int i = 0; i < size; i++)
    {
        if (curr->data == data)
        {
            cout << "Element found at index " << i << endl;
            return curr;
        }

        curr = curr->next;
    }

    cout << "Element not found" << endl;
    return nullptr;
}

Node *SortingLinkedList::binarySearch(int data)
{
    Node *start = head;
    int startIndex = 0;

    Node *end = tail;
    int endIndex = size - 1;

    Node *mid = head;
    int midIndex = (startIndex + endIndex) / 2;

    while (start && end && startIndex <= endIndex)
    {
        // Get node at mid index
        mid = start;
        for (int i = 0; i < (midIndex - startIndex); i++)
        {
            if (!mid)
                break;
            mid = mid->next;
        }
        if (!mid)
            break;

        if (mid->data == data)
        {
            cout << "Element found at index " << midIndex << endl;
            return mid;
        }
        else if (mid->data > data)
        {
            end = mid->prev;
            endIndex = midIndex - 1;
        }
        else
        {
            start = mid->next;
            startIndex = midIndex + 1;
        }

        midIndex = (startIndex + endIndex) / 2;
    }

    cout << "Element not found" << endl;
    return nullptr;
}

void SortingLinkedList::del(int data)
{
    Node *target = linearSearch(data);

    if (!target)
        return;

    if (!head && !tail)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head == tail && head == target)
    {
        head = nullptr;
        tail = nullptr;
    }

    else if (head == target)
    {
        if (head->next)
            head->next->prev = nullptr;
        head = head->next;
    }

    else if (tail == target)
    {
        if (tail->prev)
            tail->prev->next = nullptr;
        tail = tail->prev;
    }

    else
    {
        if (target->prev)
            target->prev->next = target->next;
        if (target->next)
            target->next->prev = target->prev;
    }

    delete target;
    size--;
}

void SortingLinkedList::swap(Node *N1, Node *N2)
{
    int temp = N1->data;
    N1->data = N2->data;
    N2->data = temp;
}

void SortingLinkedList::bubbleSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        Node *inner = head;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (inner->data > inner->next->data)
            {
                swap(inner, inner->next);
            }

            inner = inner->next;
        }
    }
}

void SortingLinkedList::selectionSort()
{
    Node *outer = head;
    for (int i = 0; i < size - 1; i++)
    {
        Node *min = outer;
        Node *curr = outer->next;
        for (int j = i + 1; j < size; j++)
        {
            if (min && curr && min->data > curr->data)
            {
                min = curr;
            }
            curr = curr->next;
        }
        swap(min, outer);
        outer = outer->next;
    }
}

void SortingLinkedList::insertionSort()
{
    for (int i = 1; i < size; i++)
    {
        // Get node at index i
        Node *curr = head;
        for (int k = 0; k < i; k++)
        {
            curr = curr->next;
        }

        for (int j = i; j > 0 && curr->prev; j--)
        {
            if (curr->data < curr->prev->data)
            {
                swap(curr, curr->prev);
                curr = curr->prev;
            }
            else
            {
                break;
            }
        }
    }
}

void SortingLinkedList::display()
{
    if (!head)
    {
        cout << "No elements inserted yet" << endl;
        return;
    }

    Node *curr = head;

    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

SortingLinkedList::~SortingLinkedList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}