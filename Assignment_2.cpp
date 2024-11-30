// Vedant Kokane
// 31430


#include <bits/stdc++.h>
using namespace std;
#define INF 1e9


class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adj; // adjacency list (vertex, weight)

    Graph(int V) : vertices(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    pair<vector<int>, vector<int>> dijkstra(int start) {
        vector<int> dist(vertices, INF);
        dist[start] = 0;
        vector<int> parent(vertices, -1);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (const auto& it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if (edgeWeight + dis < dist[adjNode]) {
                    dist[adjNode] = edgeWeight + dis;
                    parent[adjNode] = node; 
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return {dist,parent};
    }
    
    void printPath(vector<int>& parent, int start, int end, vector<string>& cities) {
        stack<int> path;
        int current = end;

        // Reconstruct the path using the parent array
        while (current != -1) {
            path.push(current);
            current = parent[current];
        }

        // Print the path
        cout << "Shortest path from " << cities[start] << " to " << cities[end] << ": ";
        while (!path.empty()) {
            cout << cities[path.top()];
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << endl;
    }

};

int main() {
    Graph graph(5);
    vector<string> cities = {"Pune", "Mumbai", "Delhi", "Chennai", "Banglore"};
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 7);
    
    int startVertex = 1;
    pair<vector<int>, vector<int>> result = graph.dijkstra(startVertex);
    vector<int> shortestDistances = result.first;
    vector<int> parent = result.second;

    cout << "Shortest distances from city " << cities[startVertex] << ":\n";
    for (int i = 0; i < graph.vertices; ++i) {
        cout << "from "<<cities[startVertex] <<" to " << cities[i] << ": " << shortestDistances[i] << endl;
    }
    
    int destinationVertex = 4; // Banglore
    graph.printPath(parent, startVertex, destinationVertex, cities);
    
    return 0;
}


/*
Graph:
Vertex 0: (1, 1) (2, 4)
Vertex 1: (0, 1) (2, 2) (3, 5)
Vertex 2: (0, 4) (1, 2) (3, 1)
Vertex 3: (1, 5) (2, 1) (4, 7)
Vertex 4: (3, 7)

from Mumbai to Pune: 1
from Mumbai to Mumbai: 0
from Mumbai to Delhi: 2
from Mumbai to Chennai: 3
from Mumbai to Banglore: 10


*/
