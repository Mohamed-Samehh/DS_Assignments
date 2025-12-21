class DoubleEndedQueue
{
private:
    int *items;
    int rear;
    int front;
    int capacity;
    int size;

public:
    DoubleEndedQueue(int capacity);
    void enqueueRear(int item);
    void enqueueFront(int item);
    int dequeueRear();
    int dequeueFront();
    void display();
    ~DoubleEndedQueue();
};