#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size)
{
    this->size = size;
    table = new Node *[size];

    for (int i = 0; i < size; i++)
    {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(string key)
{
    unsigned long hash = 0;
    int p = 31; // a small prime number
    for (char c : key)
    {
        hash = hash * p + c;
    }
    return hash % size;
}

void HashTable::insert(string key, string val)
{
    int index = hashFunction(key);

    Node *current = table[index];

    while (current != nullptr)
    {
        if (current->key == key)
        {
            current->value = val;
            return;
        }
        current = current->next;
    }

    Node *NewNode = new Node(key, val);

    NewNode->next = table[index];

    table[index] = NewNode;
}

// This function is added by me and wasn't in lecture code
void HashTable::remove(string key)
{
    int index = hashFunction(key);

    Node *current = table[index];
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev == nullptr)
            {
                table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

Node *HashTable::search(string key)
{
    int index = hashFunction(key);

    Node *current = table[index];

    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void HashTable::display()
{
    for (int i = 0; i < size; i++)
    {
        Node *current = table[i];

        cout << "Index " << i << ": ";
        while (current != nullptr)
        {
            cout << current->key << "->" << current->value << " , ";
            current = current->next;
        }

        cout << endl;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < size; i++)
    {
        Node *current = table[i];

        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}