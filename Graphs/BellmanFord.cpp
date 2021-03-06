// A C / C++ program for Bellman-Ford's single source 
// shortest path algorithm.

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "BellmanFord.h"

// Creates a graph with V vertices and E edges
struct GraphBellmanFord* createGraphBellmanFord(int V, int E)
{
	struct GraphBellmanFord* graph =
		(struct GraphBellmanFord*) malloc(sizeof(struct GraphBellmanFord));
	graph->V = V;
	graph->E = E;

	graph->edge =
		(struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;
}

// A utility function used to print the solution
void printArrBellmanFord(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void BellmanFord(struct GraphBellmanFord* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[5];

	// Step 1: Initialize distances from src to all other vertices
	// as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times. A simple shortest 
	// path from src to any other vertex can have at-most |V| - 1 
	// edges
	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles.  The above step 
	// guarantees shortest distances if graph doesn't contain 
	// negative weight cycle.  If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			printf("GraphBellmanFord contains negative weight cycle");
	}

	printArrBellmanFord(dist, V);

	return;
}