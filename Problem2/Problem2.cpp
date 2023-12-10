// Problem 2: Social Network
// Description: 
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 29-11-2023
//

#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int nodes; //Number of nodes
    vector<int>* adj;
public:
    Graph(int nodes);
    void addEdge(int src, int dest); //src == Source node, dest == Destintaion node
    bool isEdge(int src, int dest);
    int getNumNodes();
    void printGraph();
    bool BFS(int src, int dest, int distance[], int predecessor[]);
    void printShortPath(int src, int dest);
};

Graph::Graph(int nodes) {
    this->nodes = nodes;
    adj = new vector <int>[nodes];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool Graph::isEdge(int src, int dest) {
    vector<int>::iterator i;
    for (i = adj[src].begin(); i != adj[src].end(); i++) {
        if (dest == *i) {
            return(true);
        }
        return(false);
    }
}

int Graph::getNumNodes() {
    return nodes;
}

void Graph::printGraph() {
    for (int src = 0; src < nodes; ++src) {
        cout << "\nAdjacency list of node " << src << "\n head ";
        vector<int>::iterator i;
        for (i = adj[src].begin(); i != adj[src].end(); ++i) {
            cout << "-> " << *i << " ";
        }
    }
}

bool Graph::BFS(int src, int dest, int distance[], int predecessor[]) {
    list<int> queue;
    vector<bool> visited(nodes, false);

    for (int i = 0; i < nodes; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    visited[src] = true;
    distance[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();
        for (auto adjacent : adj[current]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                distance[adjacent] = distance[current] + 1;
                predecessor[adjacent] = current;
                queue.push_back(adjacent);
                if (adjacent == dest) return true;
            }
        }
    }
    return false;
}

void Graph::printShortPath(int src, int dest) {
    int* distance = new int[nodes];
    int* predecessor = new int[nodes];
    if (BFS(src, dest, distance, predecessor)) {
        cout << "Path: ";
        list<int> path;
        int crawl = dest;
        path.push_front(crawl);
        while (predecessor[crawl] != -1) {
            path.push_front(predecessor[crawl]);
            crawl = predecessor[crawl];
        }
        for (auto i : path) {
            cout << i << " ";
        }

        // A node is a friend if the shortest path is even
        if (distance[dest] % 2 == 0) {
            cout << endl << "node: " << dest << " is a ";
            cout << "Friend\n";
        }
        else {
            cout << endl << "node: " << dest << " is an ";
            cout << "Adversary\n";
        }
    }
    else {
        cout << "No path found from " << src << " to " << dest << "\n";
    }
    delete[] distance;
    delete[] predecessor;
}

int main() {
    Graph network(4);
    int start = 0; // the head-node
    int end = 2; // the target-node
    network.addEdge(0, 1); //A dislikes B
    network.addEdge(1, 2); //B dislikes C
    network.addEdge(1, 3); //B dislikes D
    network.addEdge(2, 3); //C dislikes D
    network.addEdge(2, 1); //C dislikes B
    //network.printGraph();
    
    cout << endl << "Shortest Path from starting node to end node: \n";
    network.printShortPath(start, end);
}