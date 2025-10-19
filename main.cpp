#include <iostream>
#include <vector>
#include <math.h>
#include "Node.h"

int main()
{
    // menu for picking tree operations
    int choice;
    // loop until user decides to exit
    bool running = true;
    std::cout << "Pick an option:" << std::endl;
    std::cout << "1. Insert node" << std::endl;
    std::cout << "2. Inorder Traversal" << std::endl;
    std::cout << "3. Preorder Traversal" << std::endl;
    std::cout << "4. Postorder Traversal" << std::endl;
    std::cout << "5. Tree Height" << std::endl;
    std::cout << "6. Search tree" << std::endl;
    std::cout << "7. Exit" << std::endl;
    // create the root of the tree
    Node *root = nullptr;
    Node node(0); // Temporary node to access member functions
    // main loop
    while (running)
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        // insert node (singular)
        case 1:
        {
            int val;
            std::cout << "Enter value to insert: ";
            std::cin >> val;
            root = node.insert(root, val);
            break;
        }
        // inorder traversal
        case 2:
        {
            std::cout << "Inorder Traversal: ";
            node.inorder(root);
            std::cout << std::endl;
            break;
        }
        // preorder traversal
        case 3:
        {
            std::cout << "Preorder Traversal: ";
            node.preorder(root);
            std::cout << std::endl;
            break;
        }
        // postorder traversal
        case 4:
        {
            std::cout << "Postorder Traversal: ";
            node.postorder(root);
            std::cout << std::endl;
            break;
        }
        // tree height
        case 5:
        {
            int height = 0;
            node.treeHeight(root, height, 0);
            std::cout << "Tree Height: " << height << std::endl;
            break;
        }
        // search tree
        case 6:
        {
            int val;
            int depth = 0;
            std::cout << "Enter value to search: ";
            std::cin >> val;
            bool found = false;
            node.searchTree(root, val, found, depth);
            if (!found)
            {
                std::cout << "Value " << val << " not found in the tree." << std::endl;
            }
            break;
        }
        // exit
        case 7:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}