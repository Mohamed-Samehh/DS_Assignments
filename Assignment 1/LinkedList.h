#include "Node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    void addElement(int val);
    void removeElement(int val);
    void removeAll(int val);
    Node *findElement(int val);
    void displayList();
    ~LinkedList();
};