#include <iostream>
#include <vector>
#include "insertValues.h"
#include "Node.h"
void InsertValues::display()
{
    bool addMore = true;
    Node node;
    while (addMore)
    {
        i = 0;
        val[100] = {0};
        std::cout << "insert values for the tree separated by spaces and end with -1: ";
        std::cin >> temp;
        while (temp != -1)
        {
            if (temp == -1)
            {
                break;
            }
            val[i] = temp;
            i += 1;
            std::cin >> temp;
        }

        node.insertValues(val, i);
        std::cout << "In-order: ";
        node.inorder(&node);
        std::cout << std::endl;
        std::cout << "Pre-order: ";
        node.preorder(&node);
        std::cout << std::endl;

        std::cout << "Post-order: ";
        node.postorder(&node);
        std::cout << std::endl;

        std::cout << "Tree Height: ";
        node.treeHeight(&node, height, 0);
        std::cout << height << std::endl;
        std::cout << "\n\nWould you like to add more values? (1 for yes, 0 for no): ";
        std::cin >> addMore;
        std::cout << std::endl;
    }
    addMore = true;
    std::cout << "Would you like to search the tree? (1 for yes, 0 for no): " << std::endl;
    std::cin >> addMore;
    while (addMore)
    {
        int searchVal;
        bool found = false;
        std::cout << "Enter a value to search in the tree: ";
        std::cin >> searchVal;
        node.searchTree(&node, searchVal, found, 0);
        if (!found)
        {
            std::cout << "Value " << searchVal << " not found in the tree." << std::endl;
        }
        std::cout << "\n\nWould you like to search for another value? (1 for yes, 0 for no): ";
        std::cin >> addMore;
        std::cout << std::endl;
    }

    node.~Node();
};