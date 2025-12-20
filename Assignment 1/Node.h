class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data);

    void setData(int data);
    int getData();

    void setNext(Node *next);
    Node *getNext();

    void setPrev(Node *prev);
    Node *getPrev();
};