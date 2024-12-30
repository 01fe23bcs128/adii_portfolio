#include <iostream>
#include <cstdlib>
using namespace std;

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

typedef struct tree TREE;

class BinarySearchTree {
public:
    TREE* insert_into_bst(TREE*, int);
    void inorder(TREE*);
    void preorder(TREE*);
    void postorder(TREE*);
    TREE* delete_from_bst(TREE*, int);
};

TREE* BinarySearchTree::insert_into_bst(TREE* root, int data) {
    // Dynamically allocate memory using malloc
    TREE* newnode = (TREE*)malloc(sizeof(TREE));

    // Check if the memory allocation was successful
    if (newnode == NULL) {
        cout << "Memory allocation failed" << endl;
        return root;
    }

    // Manually initialize the node
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    // When the first insertion happens, which is the root node
    if (root == NULL) {
        root = newnode;
        cout << "Root node inserted into tree" << endl;
        return root;
    }

    // Traverse through the desired part of the tree
    TREE* currnode = root;
    TREE* parent = NULL;

    while (currnode != NULL) {
        parent = currnode;
        if (newnode->data < currnode->data)
            currnode = currnode->left;
        else
            currnode = currnode->right;
    }

    // Attach the node at the appropriate place using parent
    if (newnode->data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    cout << "Node inserted successfully into the tree" << endl;
    return root;
}

void BinarySearchTree::inorder(TREE* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

void BinarySearchTree::preorder(TREE* root) {
    if (root != NULL) {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void BinarySearchTree::postorder(TREE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}

TREE* BinarySearchTree::delete_from_bst(TREE* root, int data) {
    TREE* currnode = root;
    TREE* parent = NULL;
    TREE* successor = NULL;
    TREE* p = NULL;

    // Check if the tree is empty
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return root;
    }

    // Traverse and reach the appropriate part of the tree
    while (currnode != NULL && currnode->data != data) {
        parent = currnode;
        if (data < currnode->data)
            currnode = currnode->left;
        else
            currnode = currnode->right;
    }

    // If the data is not present in the tree
    if (currnode == NULL) {
        cout << "Item not found" << endl;
        return root;
    }

    // Check and manipulate if either left subtree is absent, right subtree is absent, or both are present
    if (currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else {
        // Process of finding the inorder successor
        successor = currnode->right;
        while (successor->left != NULL)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    // The case of root deletion
    if (parent == NULL) {
        free(currnode);
        return p;
    }

    if (currnode == parent->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    return root;
}

int main() {
    BinarySearchTree bst;
    TREE* root = NULL;
    int choice = 0;
    int data = 0;

    while (1) {
        cout << "\n******** Menu *************\n";
        cout << "1-Insert into BST\n";
        cout << "2-Inorder Traversal\n";
        cout << "3-Preorder Traversal\n";
        cout << "4-Postorder Traversal\n";
        cout << "5-Delete from BST\n";
        cout << "Any other option to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the item to insert: ";
            cin >> data;
            root = bst.insert_into_bst(root, data);
            break;

        case 2:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Inorder Traversal is...\n";
                bst.inorder(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Preorder Traversal is...\n";
                bst.preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Postorder Traversal is...\n";
                bst.postorder(root);
                cout << endl;
            }
            break;

        case 5:
            cout << "Enter the item to be deleted: ";
            cin >> data;
            root = bst.delete_from_bst(root, data);
            break;

        default:
            cout << "Exiting Code.\n";
            exit(0);
        }
    }

    return 0;
}
