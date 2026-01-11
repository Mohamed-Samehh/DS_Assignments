class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class SortingLinkedList
{
public:
    Node *tail;
    Node *head;
    int size;

    SortingLinkedList();
    void insert(int data);
    void del(int data);
    Node *linearSearch(int data);
    Node *binarySearch(int data);
    void swap(Node *N1, Node *N2);
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void display();
    ~SortingLinkedList();
};