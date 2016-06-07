// A union-find algorithm to detect cycle in a UnionFindGraph
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure to represent an UnionFindEdge in UnionFindGraph
struct UnionFindEdge
{
	int src, dest;
};

// a structure to represent a UnionFindGraph
struct UnionFindGraph
{
	// V-> Number of vertices, E-> Number of UnionFindEdges
	int V, E;

	// UnionFindGraph is represented as an array of UnionFindEdges
	struct UnionFindEdge* UnionFindEdge;
};

// Creates a UnionFindGraph with V vertices and E UnionFindEdges
struct UnionFindGraph* createUnionFindGraph(int V, int E)
{
	struct UnionFindGraph* UnionFindGraph =
		(struct UnionFindGraph*) malloc(sizeof(struct UnionFindGraph));
	UnionFindGraph->V = V;
	UnionFindGraph->E = E;

	UnionFindGraph->UnionFindEdge =
		(struct UnionFindEdge*) malloc(UnionFindGraph->E * sizeof(struct UnionFindEdge));

	return UnionFindGraph;
}

// A utility function to find the subset of an element i
int UnionFindfind(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return UnionFindfind(parent, parent[i]);
}

// A utility function to do union of two subsets 
void UnionFindUnion(int parent[], int x, int y)
{
	int xset = UnionFindfind(parent, x);
	int yset = UnionFindfind(parent, y);
	parent[xset] = yset;
}

// The main function to check whether a given UnionFindGraph contains 
// cycle or not
int UnionFindisCycle(struct UnionFindGraph* UnionFindGraph)
{
	// Allocate memory for creating V subsets
	int *parent = (int*)malloc(UnionFindGraph->V * sizeof(int));

	// Initialize all subsets as single element sets
	memset(parent, -1, sizeof(int) * UnionFindGraph->V);

	// Iterate through all UnionFindEdges of UnionFindGraph, find subset of both
	// vertices of every UnionFindEdge, if both subsets are same, then 
	// there is cycle in UnionFindGraph.
	for (int i = 0; i < UnionFindGraph->E; ++i)
	{
		int x = UnionFindfind(parent, UnionFindGraph->UnionFindEdge[i].src);
		int y = UnionFindfind(parent, UnionFindGraph->UnionFindEdge[i].dest);

		if (x == y)
			return 1;

		UnionFindUnion(parent, x, y);
	}
	return 0;
}