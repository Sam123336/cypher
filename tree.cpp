#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;

    // Constructor
};

Node* newNode(int key) {
    Node* root = new Node;
    root->key = key;
    root->left = root->right = nullptr;
    return root;
}

// Function to insert a node with a given key into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr) {
        return false; // Key is not present in the BST
    }

    if (root->key == key) {
        return true; // Key found
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->key << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << ' ';
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node* root = nullptr;
    int key;
    while (cin >> key) {
        root = insert(root, key);
    }

    // Example to show the tree (in-order traversal)
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    // Example delete operation
    root = deleteNode(root, key); // Assuming 'key' is the key to be deleted

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
