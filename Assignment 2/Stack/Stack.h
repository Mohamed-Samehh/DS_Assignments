class Stack
{
private:
    int capacity;
    int top;
    int *data;

public:
    Stack(int capacity);
    void push(int value);
    int pop();
    bool isEmpty();
    bool isFull();
    void display();
    ~Stack();
};