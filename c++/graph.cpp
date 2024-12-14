// C++ implementation of Graph using an Adjacency List,
// Depth First Search using recursion,
// Breath First Search using a while loop
#include <iostream>
#include <queue>
#define MAXV 1000

using namespace std;

struct edgeNode {
  int y;
  int weight;
  struct edgeNode *next;
};

class Graph {
 private:
  edgeNode *edges[MAXV + 1];
  int degree[MAXV + 1];  // number of connections of edges w a vertex
  int nVertices;         // max vertex count
  int nEdges;            // max edges count
  bool directed;         // if graph is directed

 public:
  Graph() {
    this->nVertices = 0;
    this->nEdges = 0;
    this->directed = false;

    for (int i = 0; i <= MAXV; i++) {
      this->degree[i] = 0;
      this->edges[i] = NULL;
    }
  }
  Graph(bool directed) {
    this->nVertices = 0;
    this->nEdges = 0;
    this->directed = directed;

    for (int i = 0; i <= MAXV; i++) {
      this->degree[i] = 0;
      this->edges[i] = NULL;
    }
  }
  void printGraph();
  void insertEdge(int x, int y, bool directed);
  void dfs();
  void dfsHelper(int vertex, bool *visited);
  void bfs();
  void bfsHelper(int start, bool *visited);
};

void Graph::printGraph() {
  edgeNode *temp;
  for (int i = 0; i <= this->nVertices; i++) {
    cout << i << ": ";  // Print the vertex
    temp = this->edges[i];
    while (temp != NULL) {
      cout << temp->y << " ";  // Print its adjacent
      temp = temp->next;
    }
    cout << endl;
  }
}

void Graph::insertEdge(int x, int y, bool directed) {
  // create a new edge node
  edgeNode *newEdge = new edgeNode();
  newEdge->y = y;
  newEdge->weight = 0;
  newEdge->next = NULL;

  // insert new edge at the beginning of the list
  newEdge->next = this->edges[x];
  this->edges[x] = newEdge;
  this->degree[x]++;

  // update max vertex count
  if (x > this->nVertices) {
    this->nVertices = x;
  }
  if (y > this->nVertices) {
    this->nVertices = y;
  }

  // if graph is undirected
  if (directed == false) {
    insertEdge(y, x, true);  // insert edge going the opposite way
  } else {
    this->nEdges++;
  }
}

// Depth-First Search using recursion
void Graph::dfs() {
  // create visited array
  bool visited[MAXV + 1];
  // set all verticies as not visited
  for (int i = 0; i <= MAXV; i++) {
    visited[i] = false;
  }

  // call recursive DFS helper function for each unvisted vertex
  for (int i = 0; i < nVertices; i++) {
    if (!visited[i]) {
      dfsHelper(i, visited);
    }
  }
}

void Graph::dfsHelper(int v, bool *visited) {
  // mark current vertex as visited and print
  visited[v] = true;
  cout << v << " ";

  // recursively visit adjacent unvisted verticies
  edgeNode *temp = edges[v];
  while (temp != NULL) {
    if (!visited[temp->y]) {
      dfsHelper(temp->y, visited);
    }
    temp = temp->next;
  }
}

// Breadth-First Search using a queue
void Graph::bfs() {
  // create visited array
  bool visited[MAXV + 1];
  // set all verticies as not visited
  for (int i = 0; i <= MAXV; i++) {
    visited[i] = false;
  }

  // call BFS helper function for each unvisted vertex
  for (int i = 0; i < nVertices; i++) {
    if (!visited[i]) {
      bfsHelper(i, visited);
    }
  }
}

void Graph::bfsHelper(int start, bool *visited) {
  // create queue
  queue<int> q;

  // mark current node as visited and enqueue
  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    // dequeue a vertex from queue and print it
    int v = q.front();
    cout << v << " ";
    q.pop();

    // get all adjacent verticies of dequeued vertex
    edgeNode *temp = edges[v];
    while (temp != NULL) {
      // if not visited, mark as visited and enqueue it
      if (!visited[temp->y]) {
        visited[temp->y] = visited;
        q.push(temp->y);
      }
      temp = temp->next;
    }
  }
}

int main(void) {
  // Create an undirected graph
  Graph graph(false);

  graph.insertEdge(0, 1, false);
  graph.insertEdge(0, 2, false);
  graph.insertEdge(1, 2, false);
  graph.insertEdge(2, 3, false);

  cout << "Graph Adjacency List:" << endl;
  graph.printGraph();

  cout << "\nDepth-First Search traversal:" << endl;
  graph.dfs();

  cout << "\n\nBreadth-First Search traversal:" << endl;
  graph.bfs();

  return 0;
}