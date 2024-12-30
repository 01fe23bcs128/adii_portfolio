#include <iostream>
using namespace std;

int BIT[20], a[20], n;

void update(int x, int delta) {
    // Update BIT with the given delta at index x
    for (; x <= n; x += x & -x) {
        BIT[x] += delta;
    }
}

int query(int x) {
    // Query the prefix sum from 1 to x
    int sum = 0;
    for (; x > 0; x -= x & -x) {
        sum += BIT[x];
    }
    return sum;
}

int main() {
    cout<<"Enter the number of elements"<<endl;
    cin >> n;

    // Read input array and initialize the Fenwick Tree
     cout<<"Enter the elements"<<endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);  // Update BIT with the value of a[i]
    }

    // Example query to find the sum of the first 10 items
    cout << "The sum of the first 10 items is: " << query(10) << endl;

    return 0;
}
