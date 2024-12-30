#include <iostream>
#include <vector>
using namespace std;

// Class to represent a Graph
class Graph {
private:
    int numVertices;                     // Number of vertices
    vector<vector<int>> adjList;         // Adjacency list to store the graph

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices + 1);   // 1-based indexing
    }

    // Add an edge to the graph
    void addEdge(int u, int v, bool isDirected = false) {
        adjList[u].push_back(v);        // Add v to u's list
        if (!isDirected) {
            adjList[v].push_back(u);    // Add u to v's list (for undirected graphs)
        }
    }

    // Display the graph as an adjacency list
    void display() {
        for (int i = 1; i <= numVertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v); // By default, it's an undirected graph
    }

    cout << "\nAdjacency List Representation of the Graph:" << endl;
    graph.display();

    return 0;
}
