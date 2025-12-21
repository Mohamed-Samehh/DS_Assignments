#include "QueueLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    QueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue elements: ";
    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;

    cout << "Queue elements after dequeue: ";
    queue.display();

    return 0;
}