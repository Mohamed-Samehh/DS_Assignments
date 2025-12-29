#include <iostream>
#include "Node.h"

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}