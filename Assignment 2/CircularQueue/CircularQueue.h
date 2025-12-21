class CircularQueue
{
private:
    int *items;
    int rear;
    int front;
    int capacity;
    int size;

public:
    CircularQueue(int capacity);
    void enqueue(int item);
    int dequeue();
    void display();
    ~CircularQueue();
};