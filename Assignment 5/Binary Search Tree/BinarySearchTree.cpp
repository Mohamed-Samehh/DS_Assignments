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

void BinarySearchTree::removeNode(int data)
{
    Node *current = getNodeByData(data);
    if (current == nullptr)
        return;

    Node *parent = getParent(current);

    // Case 1: The node has no children
    if (current->right == nullptr && current->left == nullptr)
    {
        if (parent != nullptr) // Not the root
        {
            if (parent->data < current->data)
            {
                parent->right = nullptr;
            }
            else
            {
                parent->left = nullptr;
            }
        }
        else // The root
        {
            root = nullptr;
        }

        delete current;
    }

    // Case 2: The node has one child
    else if (current->right == nullptr || current->left == nullptr)
    {
        Node *child = current->right ? current->right : current->left;
        if (parent != nullptr) // Not the root
        {
            if (parent->right == current)
            {
                parent->right = child;
            }
            else
            {
                parent->left = child;
            }
        }
        else
        {
            root = child;
        }

        delete current;
    }

    // Case 3: The node has two children
    else if (current->right != nullptr && current->left != nullptr)
    {
        // Find the in-order predecessor (max right of left subtree)
        Node *NewCurrent = getMaxRight(current->left);
        Node *NewCurrentParent = getParent(NewCurrent);

        // Attach NewCurrent's left child to its parent
        // Note: NewCurrent cannot have a right child since it's the max right
        if (NewCurrentParent == current)
            current->left = NewCurrent->left; // Msh fahemha
        else
            NewCurrentParent->right = NewCurrent->left;

        // Re-link parent to NewCurrent
        if (parent != nullptr)
        {
            if (parent->left == current)
            {
                parent->left = NewCurrent;
            }
            else
            {
                parent->right = NewCurrent;
            }
        }
        else
        {
            root = NewCurrent;
        }

        // Attach children to NewCurrent (avoid self-link)
        if (NewCurrent != current->left)
            NewCurrent->left = current->left;

        if (NewCurrent != current->right)
            NewCurrent->right = current->right;

        delete current;
    }
}

void BinarySearchTree::displayLDR(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    displayLDR(node->left);
    cout << node->data << " ";
    displayLDR(node->right);
}

void BinarySearchTree::traverse()
{
    if (root != nullptr)
    {
        displayLDR(root);
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

int BinarySearchTree::getNodeDepth(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        return 1;
    }

    int leftDepth = getNodeDepth(node->left);
    int rightDepth = getNodeDepth(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int BinarySearchTree::getMaxDepth()
{
    if (root == nullptr)
    {
        return 0;
    }

    return getNodeDepth(root);
}