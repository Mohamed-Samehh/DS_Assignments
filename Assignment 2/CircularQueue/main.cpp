#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main()
{
    CircularQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.display();

    queue.enqueue(60);
    queue.enqueue(70);
    queue.display();

    queue.enqueue(80);

    return 0;
}