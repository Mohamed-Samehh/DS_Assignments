#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

void BinarySearchTree::add(int data)
{
    Node *NewNode = new Node(data);

    if (root == NULL)
    {
        root = NewNode;
        return;
    }

    Node *current = root;
    Node *parent = nullptr;

    while (current != nullptr)
    {
        parent = current;

        if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    if (data > parent->data)
    {
        parent->right = NewNode;
    }
    else
    {
        parent->left = NewNode;
    }
}

Node *BinarySearchTree::getNodeByData(int data)
{
    Node *current = root;

    while (current != nullptr)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            return current;
        }
    }

    return nullptr;
}

bool BinarySearchTree::checkDataInTree(int data)
{
    if (getNodeByData(data) != nullptr)
    {
        return true;
    }

    return false;
}

Node *BinarySearchTree::getMaxRight(Node *current)
{
    if (current == NULL)
    {
        return NULL;
    }

    while (current->right != nullptr)
    {
        current = current->right;
    }

    return current;
}

Node *BinarySearchTree::getParent(Node *current)
{
    if (current == root)
    {
        return NULL;
    }

    Node *parent = root;

    while (parent != nullptr)
    {
        if (parent->right == current || parent->left == current)
        {
            return parent;
        }
        else
        {
            if (current->data > parent->data)
            {
                parent = parent->right;
            }
            else
            {
                parent = parent->left;
            }
        }
    }
    return nullptr;
}

int BinarySearchTree::getParentMain(int data)
{
    Node *current = getNodeByData(data);

    if (current != nullptr)
    {
        Node *parent = getParent(current);

        if (parent != nullptr)
        {
            return parent->data;
        }
        else
        {
            cout << "This is the root node" << endl;
            return -2;
        }
    }
    else
    {
        cout << "The node is not found" << endl;
        return -1;
    }
}

int BinarySearchTree::getMaxRightMain(int data)
{
    Node *current = getNodeByData(data);

    if (current != nullptr)
    {
        Node *right = getMaxRight(current);
        return right->data;
    }
    else
    {
        cout << "The node is not found" << endl;
        return -1;
    }
}