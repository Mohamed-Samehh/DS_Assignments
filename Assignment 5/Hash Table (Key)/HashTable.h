class Node
{
public:
    int key;
    Node *next;
    Node(int key)
    {
        this->key = key;
        next = nullptr;
    }
};

class HashTable
{
    int size;
    Node **table;

public:
    HashTable(int size);
    int hashFunction(int key);
    void insert(int key);
    void remove(int key);
    Node *search(int key);
    void display();
    ~HashTable();
};