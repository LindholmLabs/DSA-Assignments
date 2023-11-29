// Problem 2: Social Network
// Description: 
// Course: IT405G - Datastructures and Algorithms
// Authors: William Lindholm, Lili Tran, Victor Adamson
// Date: 29-11-2023
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<int>* adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isEdge(int v, int w);
    int getNumNodes();
    void printGraph();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector <int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::isEdge(int v, int w) {
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (w == *i) {
            return(true);
        }
        return(false);
    }
}

int Graph::getNumNodes() {
    return V;
}

void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of node " << v << "\n head ";
        vector<int>::iterator i;
        for (i = adj[v].begin();
            i != adj[v].end(); ++i) {
            cout << "-> " << *i << " ";
        }
    }
}

int main(){
    queue<int>;
    Graph network(4);
    vector<bool> visited[4];
    network.addEdge(0, 1);
    network.addEdge(1, 2);
    network.addEdge(1, 3);
    network.addEdge(3, 1);
    network.addEdge(3, 2);

    network.printGraph();

}

bool isAdversary(Graph network) {
    return true;
}