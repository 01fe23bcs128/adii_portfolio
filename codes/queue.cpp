#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* arr;

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Enqueue an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (front == -1) front = 0; // First element being inserted
        arr[++rear] = value;
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        if (front == rear) { // Queue becomes empty after dequeuing
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    while (true) {
        int choice, value;
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Enqueue
                cout << "Enter a value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2: // Dequeue
                q.dequeue();
                break;

            case 3: // Peek
                value = q.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;

            case 4: // Display
                q.display();
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
