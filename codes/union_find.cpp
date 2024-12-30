#include <iostream>
using namespace std;

// Function to find if two elements are in the same set
int find(int arr[], int u, int v) {
    if (arr[u] == arr[v]) {
        return 1; // Elements u and v are in the same set
    } else {
        return 0; // Elements u and v are in different sets
    }
}

// Function to union two sets containing u and v
void union_sets(int arr[], int n, int u, int v) {
    int temp = arr[u];
    for (int i = 0; i < n; i++) {
        if (arr[i] == temp) {
            arr[i] = arr[v]; // Make the set containing u the same as the set containing v
        }
    }
}

// Main function
int main() {
    int n, m;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    
    // Initially, each element is in its own set
    for (int i = 0; i < n; i++) {
        arr[i] = i; // Assign each element to its own set
    }
    
    cout << "Enter the number of union operations: ";
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter two elements to union: ";
        cin >> u >> v;
        
        if (find(arr, u, v)) {
            cout << u << " and " << v << " are already in the same set.\n";
        } else {
            union_sets(arr, n, u, v);
            cout << u << " and " << v << " have been unioned.\n";
        }
    }

    return 0;
}
