// A union by rank and path compression based program to detect cycle in a  UnionFindFRCGraph
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Common.h"

// Creates a  UnionFindFRCGraph with V vertices and E  UnionFindFRCEdges
struct  UnionFindFRCGraph* createUnionFindFRCGraph(int V, int E)
{
	struct  UnionFindFRCGraph*  UnionFindFRCGraph = (struct  UnionFindFRCGraph*) malloc(sizeof(struct  UnionFindFRCGraph));
	 UnionFindFRCGraph->V = V;
	 UnionFindFRCGraph->E = E;

	 UnionFindFRCGraph->UnionFindFRCEdge = (struct  UnionFindFRCEdge*) malloc( UnionFindFRCGraph->E * sizeof(struct  UnionFindFRCEdge));

	return  UnionFindFRCGraph;
}

// A utility function to find set of an element i
// (uses path compression technique)
int UnionFindFRCfind(struct  UnionFindFRCsubset  UnionFindFRCsubsets[], int i)
{
	// find root and make root as parent of i (path compression)
	if ( UnionFindFRCsubsets[i].parent != i)
		 UnionFindFRCsubsets[i].parent = UnionFindFRCfind( UnionFindFRCsubsets,  UnionFindFRCsubsets[i].parent);

	return  UnionFindFRCsubsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void UnionFindFRCUnion(struct  UnionFindFRCsubset  UnionFindFRCsubsets[], int x, int y)
{
	int xroot = UnionFindFRCfind( UnionFindFRCsubsets, x);
	int yroot = UnionFindFRCfind( UnionFindFRCsubsets, y);

	// Attach smaller rank tree under root of high rank tree
	// (Union by Rank)
	if ( UnionFindFRCsubsets[xroot].rank <  UnionFindFRCsubsets[yroot].rank)
		 UnionFindFRCsubsets[xroot].parent = yroot;
	else if ( UnionFindFRCsubsets[xroot].rank >  UnionFindFRCsubsets[yroot].rank)
		 UnionFindFRCsubsets[yroot].parent = xroot;

	// If ranks are same, then make one as root and increment
	// its rank by one
	else
	{
		 UnionFindFRCsubsets[yroot].parent = xroot;
		 UnionFindFRCsubsets[xroot].rank++;
	}
}

// The main function to check whether a given  UnionFindFRCGraph contains cycle or not
int UnionFindFRCisCycle(struct  UnionFindFRCGraph*  UnionFindFRCGraph)
{
	int V =  UnionFindFRCGraph->V;
	int E =  UnionFindFRCGraph->E;

	// Allocate memory for creating V sets
	struct  UnionFindFRCsubset * UnionFindFRCsubsets =
		(struct  UnionFindFRCsubset*) malloc(V * sizeof(struct  UnionFindFRCsubset));

	for (int v = 0; v < V; ++v)
	{
		 UnionFindFRCsubsets[v].parent = v;
		 UnionFindFRCsubsets[v].rank = 0;
	}

	// Iterate through all  UnionFindFRCEdges of  UnionFindFRCGraph, find sets of both
	// vertices of every  UnionFindFRCEdge, if sets are same, then there is
	// cycle in  UnionFindFRCGraph.
	for(int e = 0; e < E; ++e)
	{
		int x = UnionFindFRCfind( UnionFindFRCsubsets,  UnionFindFRCGraph-> UnionFindFRCEdge[e].src);
		int y = UnionFindFRCfind( UnionFindFRCsubsets,  UnionFindFRCGraph-> UnionFindFRCEdge[e].dest);

		if (x == y)
			return 1;

		UnionFindFRCUnion(UnionFindFRCsubsets, x, y);
	}
	return 0;
}
