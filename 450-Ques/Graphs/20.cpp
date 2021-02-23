#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	struct Edge *edges;
};

Graph* createGraph(int V, int E) {
	Graph* newGraph = new Graph();
	newGraph->V = V;
	newGraph->E = E;
	newGraph->edges = new Edge[E];

	return newGraph;
}

void printArr(vector<int> distance, int n) {
	for(int i = 0; i < n; i++) {
		cout << i << " " <<  distance[i] << endl;
	}
}

void bellmanFord(Graph* graph, int src) {
	int V = graph->V;
	int E = graph->E;
	vector<int> distance(V, INT_MAX);
	distance[0] = 0;

	for(int i = 0; i < V - 1; i++) {
		for(int j = 0; j < E; j++) {
			int u = graph->edges[j].src;
			int v = graph->edges[j].dest;
			int weight = graph->edges[j].weight;

			if(distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
				distance[v] = distance[u] + weight;
			}
		}
	}

	for(int j = 0; j < E; j++) {
		int u = graph->edges[j].src;
			int v = graph->edges[j].dest;
			int weight = graph->edges[j].weight;

			if(distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
				cout << "Graph contains negative cycle" << endl;
				return;
			}
	}

	printArr(distance, V);
	return;
}

int main() {
	 /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph 
    int E = 8; // Number of edges in graph 
    struct Graph* graph = createGraph(V, E); 
  
    // add edge 0-1 (or A-B in above figure) 
    graph->edges[0].src = 0; 
    graph->edges[0].dest = 1; 
    graph->edges[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edges[1].src = 0; 
    graph->edges[1].dest = 2; 
    graph->edges[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edges[2].src = 1; 
    graph->edges[2].dest = 2; 
    graph->edges[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edges[3].src = 1; 
    graph->edges[3].dest = 3; 
    graph->edges[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edges[4].src = 1; 
    graph->edges[4].dest = 4; 
    graph->edges[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edges[5].src = 3; 
    graph->edges[5].dest = 2; 
    graph->edges[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edges[6].src = 3; 
    graph->edges[6].dest = 1; 
    graph->edges[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edges[7].src = 4; 
    graph->edges[7].dest = 3; 
    graph->edges[7].weight = -3; 
  
  	bellmanFord(graph, 0);

	return 0;	
}
