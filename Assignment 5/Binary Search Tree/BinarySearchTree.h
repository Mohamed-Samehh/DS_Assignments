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

    // Helper functions
    Node *getMaxRight(Node *current);
    Node *getParent(Node *current);
    Node *getNodeByData(int data);
    void displayLDR(Node *node);
    int getNodeDepth(Node *node);

public:
    BinarySearchTree();
    void add(int data);
    bool checkDataInTree(int data);
    void removeNode(int data);
    void traverse();
    int getMaxDepth();
};