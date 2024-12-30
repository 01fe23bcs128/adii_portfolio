#include <iostream>
using namespace std;

// Node structure for AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor for creating a node
    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// AVL Tree class
class AVLTree {
private:
    // Get the height of a node
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    // Calculate the balance factor
    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Right rotate
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left rotate
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Insert a value into the AVL tree
    Node* insert(Node* node, int value) {
        // Perform the normal BST insertion
        if (!node) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; // Duplicate values not allowed

        // Update the height of this node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor
        int balance = getBalanceFactor(node);

        // Balance the tree
        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node; // Return the unchanged node pointer
    }

    // Find the node with the smallest value
    Node* getMinValueNode(Node* node) {
        Node* current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    // Delete a value from the AVL tree
    Node* deleteNode(Node* root, int value) {
        // Perform the normal BST deletion
        if (!root) return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            // Node with only one child or no child
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                // Node with two children
                Node* temp = getMinValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (!root) return root;

        // Update height of the current node
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        // Get the balance factor
        int balance = getBalanceFactor(root);

        // Balance the tree
        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rotateRight(root);

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return rotateLeft(root);

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

public:
    Node* root;

    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Insert wrapper
    void insert(int value) {
        root = insert(root, value);
    }

    // Delete wrapper
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Display the tree (inorder)
    void display() {
        if (!root) {
            cout << "Tree is empty." << endl;
        } else {
            cout << "Inorder traversal: ";
            inorder(root);
            cout << endl;
        }
    }
};

int main() {
    AVLTree tree;

    while (true) {
        int choice, value;
        cout << "\nChoose an operation:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert
                cout << "Enter a value to insert: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2: // Delete
                cout << "Enter a value to delete: ";
                cin >> value;
                tree.deleteValue(value);
                break;

            case 3: // Display
                tree.display();
                break;

            case 4: // Exit
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
