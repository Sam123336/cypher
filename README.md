Tech Stack Used:

    Language: C++
    Libraries: <bits/stdc++.h> (Standard Library)
    Tools: freopen for file I/O

Project Details:

This project implements a Binary Search Tree (BST) in C++. Below are the key functionalities and features:

    Node Structure:
        struct Node: Represents a node in the BST with key, left, and right pointers.

    Functions:
        newNode(int key): Creates a new node with the given key.
        insert(Node* root, int key): Inserts a node with a given key into the BST.
        search(Node* root, int key): Searches for a key in the BST.
        inorder(Node* root): Performs inorder traversal of the BST.
        preorder(Node* root): Performs preorder traversal of the BST.
        postorder(Node* root): Performs postorder traversal of the BST.
        deleteNode(Node* root, int key): Deletes a node with the specified key from the BST.

    Main Function:
        Sets up the BST, inserts nodes from input (cin), performs various traversals (inorder, preorder, postorder), and demonstrates deletion of a node.

