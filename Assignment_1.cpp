// Vedant Kokane
// 31430

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<list<int>> adjacencyList;


public:
    Graph(int vertices) : vertices(vertices) {
        adjacencyList.resize(vertices);
    }

    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v); // For an undirected graph, we add edges in both directions
    }

    void dfsRecursive(int startVertex) {
        vector<bool> visited(vertices, false);
        dfsRecursiveHelper(startVertex, visited);
    }

    void dfsRecursiveHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (const auto& neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                dfsRecursiveHelper(neighbor, visited);
            }
        }
    }

    void bfsRecursive(int startVertex) {
        vector<bool> visited(vertices, false);
        list<int> queue;
        bfsRecursiveHelper(startVertex, visited, queue);
    }

    void bfsRecursiveHelper(int startVertex, vector<bool>& visited, list<int>& queue) {
        visited[startVertex] = true;
        cout << startVertex << " ";
        queue.push_back(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop_front();

            for (const auto& neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    cout << neighbor << " ";
                    queue.push_back(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    cout << "DFS Recursive: ";
    graph.dfsRecursive(1);
    cout << endl;

    cout << "BFS Recursive: ";
    graph.bfsRecursive(1);
    cout << endl;

    return 0;
}


/*
  1---2
  |   |
  4---3
   \
    5
    Graph graph(6);

    // Adding edges to the graph
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    cout << "DFS Recursive: ";
    graph.dfsRecursive(1);
    cout << endl;

    cout << "BFS Recursive: ";
    graph.bfsRecursive(1);
    cout << endl;
*/

