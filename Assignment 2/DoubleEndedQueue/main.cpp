#include <iostream>
#include "DoubleEndedQueue.h"

using namespace std;

int main()
{
    DoubleEndedQueue queue(5);

    queue.enqueueFront(10);
    queue.enqueueRear(20);
    queue.enqueueFront(30);
    queue.enqueueRear(40);
    queue.enqueueFront(50);
    queue.display();

    cout << "Dequeued: " << queue.dequeueFront() << endl;
    cout << "Dequeued: " << queue.dequeueRear() << endl;
    queue.display();

    queue.enqueueFront(60);
    queue.enqueueRear(70);
    queue.display();

    queue.enqueueFront(80);

    return 0;
}