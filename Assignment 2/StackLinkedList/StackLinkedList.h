#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
    }
};

class StackLinkedList
{
    Node *tail;

public:
    StackLinkedList();
    void push(int data);
    int pop();
    void display();
    ~StackLinkedList();
};