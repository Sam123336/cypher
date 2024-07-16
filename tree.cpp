#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;

    // Constructor
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to insert a node with a given key into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to insert multiple keys into the BST
Node* insertMultiple(Node* root, vector<int>& keys) {
    for (int key : keys) {
        root = insert(root, key);
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

// Function to print tree structure
void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == nullptr) return;

    space += indent;

    printTree(root->right, space, indent);

    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";

    cout << "|__" << root->key << endl;

    printTree(root->left, space, indent);
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Insert key\n";
    cout << "2. Insert multiple keys\n";
    cout << "3. Inorder traversal\n";
    cout << "4. Preorder traversal\n";
    cout << "5. Postorder traversal\n";
    cout << "6. Delete key\n";
    cout << "7. Print Tree\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Node* root = nullptr;
    int choice, key;
    vector<int> keys;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Enter keys to insert (enter -1 to stop):\n";
                while (true) {
                    cin >> key;
                    if (key == -1) break;
                    keys.push_back(key);
                }
                root = insertMultiple(root, keys);
                keys.clear(); // Clear the keys vector for next use
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                cout << "Inorder after deletion: ";
                inorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Tree structure:\n";
                printTree(root);
                cout << endl;
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
