// Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BellmanFord.h"
#include "Kruskals.h"
//#define V 9

int minDistance(int dist[], bool sptSet[]);
int printSolution(int dist[], int n);
void dijkstra(int graph[9][9], int src);

struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void dijkstra(struct Graph* graph, int src);

void printGraph(struct Graph* graph);
struct Graph* createGraphAdjacency(int V);
void addEdge(struct Graph* graph, int src, int dest);

struct GraphBellmanFord* createGraphBellmanFord(int V, int E);
void BellmanFord(struct GraphBellmanFord* graph, int src);

void primMST(int graph[5][5]);

struct KruskalsGraph* createGraphKruskals(int V, int E);
void KruskalMST(struct KruskalsGraph* graph);

int main()
{
	//Dkstra
	//int graph[9][9] = { 
	//					//0, 1, 2, 3, 4, 5, 6, 7, 8	
	//			/*0*/   { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	//			/*1*/   { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	//	        /*2*/	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	//			/*3*/   { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	//			/*4*/	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	//			/*5*/   { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
	//			/*6*/   { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
	//			/*7*/   { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	//			/*8*/   { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	//};

	//dijkstra(graph, 0);

	//Dkstra Priority Queue

	// create the graph given in above fugure
	int V = 9;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1, 4);
	addEdge(graph, 0, 7, 8);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 7, 11);
	addEdge(graph, 2, 3, 7);
	addEdge(graph, 2, 8, 2);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 3, 4, 9);
	addEdge(graph, 3, 5, 14);
	addEdge(graph, 4, 5, 10);
	addEdge(graph, 5, 6, 2);
	addEdge(graph, 6, 7, 1);
	addEdge(graph, 6, 8, 6);
	addEdge(graph, 7, 8, 7);

	dijkstra(graph, 0);


//Adjcency List
	//int V = 5;
	//struct Graph* graph = createGraphAdjacency(V);
	//addEdge(graph, 0, 1);
	//addEdge(graph, 0, 4);
	//addEdge(graph, 1, 2);
	//addEdge(graph, 1, 3);
	//addEdge(graph, 1, 4);
	//addEdge(graph, 2, 3);
	//addEdge(graph, 3, 4);

	//// print the adjacency list representation of the above graph
	//printGraph(graph);

//BellManFord
	/* Let us create the graph given in above example */
	//int V = 5;  // Number of vertices in graph
	//int E = 8;  // Number of edges in graph
	//struct GraphBellmanFord* graph = createGraphBellmanFord(V, E);
	//
	//// add edge 0-1 (or A-B in above figure)
	//graph->edge[0].src = 0;
	//graph->edge[0].dest = 1;
	//graph->edge[0].weight = -1;

	//// add edge 0-2 (or A-C in above figure)
	//graph->edge[1].src = 0;
	//graph->edge[1].dest = 2;
	//graph->edge[1].weight = 4;

	//// add edge 1-2 (or B-C in above figure)
	//graph->edge[2].src = 1;
	//graph->edge[2].dest = 2;
	//graph->edge[2].weight = 3;

	//// add edge 1-3 (or B-D in above figure)
	//graph->edge[3].src = 1;
	//graph->edge[3].dest = 3;
	//graph->edge[3].weight = 2;

	//// add edge 1-4 (or A-E in above figure)
	//graph->edge[4].src = 1;
	//graph->edge[4].dest = 4;
	//graph->edge[4].weight = 2;

	//// add edge 3-2 (or D-C in above figure)
	//graph->edge[5].src = 3;
	//graph->edge[5].dest = 2;
	//graph->edge[5].weight = 5;

	//// add edge 3-1 (or D-B in above figure)
	//graph->edge[6].src = 3;
	//graph->edge[6].dest = 1;
	//graph->edge[6].weight = 1;

	//// add edge 4-3 (or E-D in above figure)
	//graph->edge[7].src = 4;
	//graph->edge[7].dest = 3;
	//graph->edge[7].weight = -3;

	//BellmanFord(graph, 0);

//Prims
	/* Let us create the following graph
	2    3
	(0)--(1)--(2)
	|   / \   |
	6| 8/   \5 |7
	| /     \ |
	(3)-------(4)
	9          */
	//int graph[5][5] = { { 0, 2, 0, 6, 0 },
	//{ 2, 0, 3, 8, 5 },
	//{ 0, 3, 0, 0, 7 },
	//{ 6, 8, 0, 0, 9 },
	//{ 0, 5, 7, 9, 0 },
	//};

	//// Print the solution
	//primMST(graph);

//Kruskals

	/* Let us create following weighted graph
	10
	0--------1
	|  \     |
	6|   5\   |15
	|      \ |
	2--------3
	4       */

	//int V = 4;  // Number of vertices in graph
	//int E = 5;  // Number of edges in graph
	//struct KruskalsGraph* graph = createGraphKruskals(V, E);
	//
	//
	//// add edge 0-1
	//graph->edge[0].src = 0;
	//graph->edge[0].dest = 1;
	//graph->edge[0].weight = 10;
	//
	//// add edge 0-2
	//graph->edge[1].src = 0;
	//graph->edge[1].dest = 2;
	//graph->edge[1].weight = 6;
	//
	//// add edge 0-3
	//graph->edge[2].src = 0;
	//graph->edge[2].dest = 3;
	//graph->edge[2].weight = 5;
	//
	//// add edge 1-3
	//graph->edge[3].src = 1;
	//graph->edge[3].dest = 3;
	//graph->edge[3].weight = 15;
	//
	//// add edge 2-3
	//graph->edge[4].src = 2;
	//graph->edge[4].dest = 3;
	//graph->edge[4].weight = 4;
	//
	//KruskalMST(graph);


	getchar();
	return 0;
}

