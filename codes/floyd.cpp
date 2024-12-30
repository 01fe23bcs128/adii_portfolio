
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to implement Floyd's algorithm for all pair shortest paths
    vector<vector<int>> floyd(vector<vector<int>>& W, int n) {
        // Distance matrix D initialized with the same values as W
        vector<vector<int>> D = W;

        // Perform the three nested loops as per Floyd's algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        return D;
    }

    // Function to print the distance matrix
    void print_matrix(const vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MAX) {
                    cout << "INF" << " ";
                } else {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Create the weight matrix W where W[i][j] is the weight of the edge from i to j
    vector<vector<int>> W(n, vector<int>(n));

    cout << "Enter the weight matrix (use INF for no path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
            if (W[i][j] == 0 && i != j) {
                W[i][j] = INT_MAX;  // No path between different vertices
            }
        }
    }

    Solution obj;
    // Call Floyd's algorithm to calculate the shortest path distances
    vector<vector<int>> shortest_paths = obj.floyd(W, n);

    // Print the shortest path distance matrix
    cout << "The shortest path matrix is:" << endl;
    obj.print_matrix(shortest_paths, n);

    return 0;
}
