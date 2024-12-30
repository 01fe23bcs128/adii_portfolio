#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS on the graph
void dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Traverse all the adjacent nodes
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1); // Adjacency list (1-based indexing)
    vector<bool> visited(n + 1, false); // Visited array to track visited nodes

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph
    }

    cout << "DFS Traversal starting from node 1: ";
    dfs(1, visited, adjList);

    return 0;
}
