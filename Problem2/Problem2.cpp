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
    int V;
    vector<int>* adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isEdge(int v, int w);
    int getNumNodes();
    void printGraph();
    void BFS(int v);
    list<int> getNeighbours(int s);
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
        cout << "\nAdjacency list of node " << v << "\n head ";
        vector<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            cout << "-> " << *i << " ";
        }
    }
}

list<int> Graph::getNeighbours(int s) {
    list<int> neighbours;
    
    vector<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
        cout << "-> " << *i << " ";
    }

    return neighbours;
}

/*
* Function: printList
* Description: Print a list of integers
* @param l: the list to print
*/
void printList(list<int> l)
{
    for (int i = 0; i < (int)l.size(); i++)
    {
        cout << l.front();
        l.pop_front();
	}
	cout << endl;
}

/*
* Function: BFS
* Description: Find the shortest path from a node to all other nodes
* @param v: the starting node
*/
void Graph::BFS(int v)
{
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[v] = true;
    queue.push_back(v);

    while (!queue.empty()) {
        v = queue.front();
        cout << v << " ";
        queue.pop_front();
        for (auto adjacent : adj[v]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main(){
    Graph network(4);
    network.addEdge(0, 1); //A dislikes B
    network.addEdge(1, 2); //B dislikes C
    network.addEdge(1, 3); //B dislikes D
    network.addEdge(2, 3); //C dislikes D
    network.addEdge(2, 1); //C dislikes B
    network.printGraph();

    list<int> neighbours = network.getNeighbours(2);

    cout << "printing neighbours: \n";
    printList(neighbours);
    
    const int i = network.getNumNodes();
    list<int> nodes[4];
    cout << "\n" << "Number of nodes: " << i << "\n";
    cout << "Breadth First Traversal from A: \n";
    network.BFS(0);
}

bool isAdversary(Graph network) {
    
    return true;
}