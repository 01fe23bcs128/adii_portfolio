#include <iostream>
#include <vector>
using namespace std;

// Function to construct a heap using the bottom-up algorithm
void heap_bottom_up(vector<int>& heap, int n) {
    for (int i = n / 2; i >= 1; i--) {
        int k = i;
        int value = heap[k];
        bool is_heap = false;

        while (!is_heap && 2 * k <= n) {
            int j = 2 * k;

            if (j < n && heap[j] < heap[j + 1]) {
                j = j + 1; // Select the larger child
            }

            if (value >= heap[j]) {
                is_heap = true; // Property satisfied
            } else {
                heap[k] = heap[j];
                k = j; // Move down the tree
            }
        }
        heap[k] = value; // Place the value in its proper position
    }
}

// Function to delete the maximum key and "heapify" the heap
void delete_max(vector<int>& heap, int& n) {
    // Step 01: Exchange the root with the last element
    swap(heap[1], heap[n]);

    // Step 02: Reduce the size of the heap
    n--;

    // Step 03: Restore the heap property
    int k = 1;
    int value = heap[k];
    bool is_heap = false;

    while (!is_heap && 2 * k <= n) {
        int j = 2 * k;

        if (j < n && heap[j] < heap[j + 1]) {
            j = j + 1; // Select the larger child
        }

        if (value >= heap[j]) {
            is_heap = true; // Property satisfied
        } else {
            heap[k] = heap[j];
            k = j; // Move down the tree
        }
    }
    heap[k] = value; // Place the value in its proper position
}

// Function to perform heap sort
void heap_sort(vector<int>& arr) {
    int n = arr.size() - 1;

    // Step 01: Build the heap
    heap_bottom_up(arr, n);

    // Step 02: Perform n-1 deletions
    for (int i = n; i > 1; i--) {
        delete_max(arr, n);
    }
}

// Driver code
int main() {
    int n;

    // Input array size from user
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n + 1); // Array of size n+1 to use 1-based indexing

    // Input elements from user
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform heap sort
    heap_sort(arr);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
