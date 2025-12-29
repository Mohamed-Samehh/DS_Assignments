#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size)
{
    this->size = size;
    this->table = new Node *[size];

    for (int i = 0; i < size; i++)
    {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int key)
{
    return key % size;
}

void HashTable::insert(int key)
{
    int index = hashFunction(key);
    Node *NewNode = new Node(key);

    // Insert the new node at the beginning of the linked list at table[index]
    NewNode->next = table[index];

    // Update the head of the linked list to point to the new node
    table[index] = NewNode;
}

// This function is added by me and wasn't in lecture code
void HashTable::remove(int key)
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
                // Node to remove is head
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

Node *HashTable::search(int key)
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

        cout << "index " << i << ": ";
        while (current != nullptr)
        {
            cout << current->key << " --> ";
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
            Node *target = current;
            current = current->next;
            delete target;
        }
    }
    delete[] table;
}