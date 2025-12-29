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
    void insertAfter(Node *target, int val);
    void insertBefore(Node *target, int val);
    Node *findElement(int val);
    int getDataByIndex(int index);
    int getCount();
    void displayList();
    ~LinkedList();
};