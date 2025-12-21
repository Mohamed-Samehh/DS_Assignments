#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class QueueLinkedList
{
    Node *front;
    Node *rear;
    int size;

public:
    QueueLinkedList();
    void enqueue(int item);
    int dequeue();
    void display();
    ~QueueLinkedList();
};