class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;
    Node *getMaxRight(Node *current);
    Node *getParent(Node *current);
    Node *getNodeByData(int data);

public:
    BinarySearchTree();
    void add(int data);
    bool checkDataInTree(int data);
    int getParentMain(int data);
    int getMaxRightMain(int data);
};