#include <iostream>

using namespace std;

class Node
{
public:
    string key;
    string value;
    Node *next;
    Node(string key, string val)
    {
        this->key = key;
        this->value = val;
        next = NULL;
    }
};

class HashTable
{
private:
    Node **table;
    int size;

public:
    HashTable(int size);
    int hashFunction(string key);
    void insert(string key, string val);
    void remove(string key);
    Node *search(string key);
    void display();
    ~HashTable();
};