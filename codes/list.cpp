#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor for creating a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            cout << value << " added to the list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << value << " added to the list." << endl;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " added to the beginning of the list." << endl;
    }

    // Delete a node by value
    void deleteValue(int value) {
        if (!head) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from the list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << value << " deleted from the list." << endl;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    while (true) {
        int choice, value;
        cout << "\nChoose an operation:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Delete a Value\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert at End
                cout << "Enter a value to insert at the end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 2: // Insert at Beginning
                cout << "Enter a value to insert at the beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 3: // Delete a Value
                cout << "Enter a value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;

            case 4: // Display List
                list.display();
                break;

            case 5: // Exit
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
