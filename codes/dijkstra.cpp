
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class dijkstra {
    public:
        int n; // Number of vertices
        vector<int> dist; // Distance array to store shortest distances
        vector<int> pv; // Penultimate vertex array to store the preceding vertex
        vector<int> vis; // Visited array to keep track of processed vertices
        vector<vector<int>> cost; // Cost matrix to store graph weights

        void read(); // Function to read input
        void dijkstra_algorithm(int src); // Function to implement Dijkstra's algorithm
        void print(); // Function to print the graph
        void print_shortest_paths(); // Function to print the shortest paths

        // Initialize vertex priority queue to empty
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
};

// Function to read graph input from the user
void dijkstra::read() {
    cout << "Enter the no. of vertices" << endl;
    cin >> n;
    cout << "Enter the vertices" << endl;
    for (int i = 0; i < n; i++) {
        int vertex;
        cin >> vertex;
    }
    cout << "Enter the cost matrix" << endl;
    cost.resize(n, vector<int>(n, -1)); // Initialize the cost matrix with -1 (no edge)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
}

// Function to implement Dijkstra's algorithm to find the shortest path
void dijkstra::dijkstra_algorithm(int src) {
    dist.resize(n, INT_MAX); // Initialize all distances to infinity
    pv.resize(n, -1); // Initialize penultimate vertices to -1
    vis.resize(n, 0); // Initialize visited array to false

    dist[src] = 0; // Distance of source vertex to itself is 0
    pv[src] = src; // Source path is to itself

    // Step 1: Insert all vertices with infinite distance into the priority queue
    for (int v = 0; v < n; v++) {
        Q.push({dist[v], v}); // Insert each vertex with its distance into the priority queue
    }

    // Step 2: Set the distance of the source to 0
    Q.push({0, src}); // Update the priority of source vertex to 0

    // Step 3: Process the vertices
    while (!Q.empty()) {
        int u = Q.top().second; // Get the vertex with the minimum distance
        Q.pop();

        if (vis[u]) continue; // Skip if the vertex has already been processed
        vis[u] = 1; // Mark the vertex as visited

        // Step 4: Relax the edges of u
        for (int v = 0; v < n; v++) {
            if (!vis[v] && cost[u][v] != -1 && dist[u] != INT_MAX) {
                if (dist[u] + cost[u][v] < dist[v]) { // Relaxation condition
                    dist[v] = dist[u] + cost[u][v]; // Update the shortest distance
                    pv[v] = u; // Update the penultimate vertex
                    Q.push({dist[v], v}); // Insert the updated vertex into the priority queue
                }
            }
        }
    }
}

// Function to print the graph
void dijkstra::print() {
    cout << "Graph Cost Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << "     ";
        }
        cout << endl;
    }
}

// Function to print the shortest paths
void dijkstra::print_shortest_paths() {
    cout << "Shortest distances from source vertex:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : " << dist[i] << ", Path: ";
        int vertex = i;
        while (vertex != pv[vertex]) {
            cout << vertex << " <- ";
            vertex = pv[vertex];
        }
        cout << vertex << endl;
    }
}

// Driver function
int main() {
    dijkstra d;
    int src;

    cout << "Enter the source vertex" << endl;
    cin >> src;

    d.read(); // Read graph input
    d.dijkstra_algorithm(src); // Apply Dijkstra's algorithm

    d.print_shortest_paths(); // Print the shortest paths and distances
    d.print(); // Print the cost matrix
    return 0;
}
