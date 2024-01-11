// Vedant Kokane
// 31430

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF 1e9

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adj; // adjacency list (vertex, weight)

    Graph(int V) : vertices(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); 
    }

    vector<int> dijkstra(int start) {
        vector<int> dist(vertices, INF);
        dist[start] = 0;
        
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
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 7);
    
    int startVertex = 0;
    vector<int> shortestDistances = graph.dijkstra(startVertex);

    cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < graph.vertices; ++i) {
        cout << "To vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
