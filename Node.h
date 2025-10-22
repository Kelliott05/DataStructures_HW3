#ifndef Node_h
#define Node_h
#include <iostream>
#include <vector>
struct Node
{
private:
    // data members
    int data;
    Node *left;
    Node *right;

public:
    // constructor
    Node() : data(), left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    // insert function (singular)
    ~Node() {
        delete left;
        delete right;
    }
    Node *insert(Node *root, int val)
    {
        
        if (root == nullptr )
        {
            return new Node(val);
        }
        if (data == 0)
        {
            data = val;
            return root = new Node(val);
        }
        else if (val < root->data)
        {
            if (val == -1) {
                return root; // Skip insertion for -1
            }
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
        return root;
    }
  
    void insertValues(int vals[], int size)
    {
        for (int i = 0; i < size; ++i)
        {
            insert(this, vals[i]);
        }
    }

    // traversal functions
    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            std::cout << root->data << " ";
            inorder(root->right);
        }
    }
    void preorder(Node *root)
    {
        if (root != nullptr)
        {
            std::cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(Node *root)
    {
        if (root != nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->data << " ";
        }
    }
    // search function
    void searchTree(Node *root, int val, bool &found, int depth)
    {
        // for end of tree
        if (root == nullptr)
        {
            return;
        }
        // for if found
        if (root->data == val)
        {
            found = true;
            std::cout << "Value " << val << " found at depth " << depth << "." << std::endl;
            return;
        }
        // traverse tree - left or right depending on value comparison
        if (val < root->data)
        {
            searchTree(root->left, val, found, depth + 1);
        }
        else
        {
            searchTree(root->right, val, found, depth + 1);
        }
    }

    // tree height function
    void treeHeight(Node *root, int &height,int currentHeight)
    {
        // base case
        if (root == nullptr)
        {
            // update height if currentHeight is greater
            if (currentHeight - 1 > height)
            {
                height = currentHeight - 1;
            }
            return;
        }
        // traverse left and right subtrees
        treeHeight(root->left, height, currentHeight + 1);
        treeHeight(root->right,height, currentHeight + 1);
    }
};
#endif