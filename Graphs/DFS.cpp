// C++ program to print DFS traversal from a given vertex in a  given DFSGraph
#include "stdafx.h"
#include<iostream>
#include        <list>

using namespace std;

// DFSGraph class represents a directed DFSGraph using adjacency list representation
class DFSGraph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
	void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
	DFSGraph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to DFSGraph
	void DFS(int v);    // DFS traversal of the vertices reachable from v
};

DFSGraph::DFSGraph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void DFSGraph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void DFSGraph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void DFSGraph::DFS(int v)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal
	DFSUtil(v, visited);
}
