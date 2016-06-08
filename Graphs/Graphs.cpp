//// Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BellmanFord.h"
#include "Kruskals.h"
using namespace std;
#include "Common.h"
//#include "BFS.cpp"
//#define V 9

int minDistance(int dist[], bool sptSet[]);
int printSolution(int dist[], int n);
void dijkstra(int graph[9][9], int src);

struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void dijkstraPQ(struct Graph* graph, int src);

void printGraph(struct Graph* graph);
struct Graph* createGraphAdjacency(int V);
void addEdge(struct Graph* graph, int src, int dest);

struct GraphBellmanFord* createGraphBellmanFord(int V, int E);
void BellmanFord(struct GraphBellmanFord* graph, int src);

void primMST(int graph[5][5]);

struct KruskalsGraph* createGraphKruskals(int V, int E);
void KruskalMST(struct KruskalsGraph* graph);

//Prims Heap
void addEdgePrimsHeap(struct PrimsHeapGraph* PrimsHeapGraph, int src, int dest, int weight);
struct PrimsHeapGraph* createPrimsHeapGraph(int V);
void PrimMST(struct PrimsHeapGraph* PrimsHeapGraph);

//Union Find
struct UnionFindGraph* createUnionFindGraph(int V, int E);
int UnionFindisCycle(struct UnionFindGraph* UnionFindGraph);

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

	//// create the graph given in above fugure
	//int V = 9;
	//struct Graph* graph = createGraph(V);
	//addEdge(graph, 0, 1, 4);
	//addEdge(graph, 0, 7, 8);
	//addEdge(graph, 1, 2, 8);
	//addEdge(graph, 1, 7, 11);
	//addEdge(graph, 2, 3, 7);
	//addEdge(graph, 2, 8, 2);
	//addEdge(graph, 2, 5, 4);
	//addEdge(graph, 3, 4, 9);
	//addEdge(graph, 3, 5, 14);
	//addEdge(graph, 4, 5, 10);
	//addEdge(graph, 5, 6, 2);
	//addEdge(graph, 6, 7, 1);
	//addEdge(graph, 6, 8, 6);
	//addEdge(graph, 7, 8, 7);

	//dijkstraPQ(graph, 0);


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
	//int V1 = 5;  // Number of vertices in graph
	//int E = 8;  // Number of edges in graph
	//struct GraphBellmanFord* bellManFordgraph = createGraphBellmanFord(V1, E);
	//
	//// add edge 0-1 (or A-B in above figure)
	//bellManFordgraph->edge[0].src = 0;
	//bellManFordgraph->edge[0].dest = 1;
	//bellManFordgraph->edge[0].weight = -1;

	//// add edge 0-2 (or A-C in above figure)
	//bellManFordgraph->edge[1].src = 0;
	//bellManFordgraph->edge[1].dest = 2;
	//bellManFordgraph->edge[1].weight = 4;

	//// add edge 1-2 (or B-C in above figure)
	//bellManFordgraph->edge[2].src = 1;
	//bellManFordgraph->edge[2].dest = 2;
	//bellManFordgraph->edge[2].weight = 3;

	//// add edge 1-3 (or B-D in above figure)
	//bellManFordgraph->edge[3].src = 1;
	//bellManFordgraph->edge[3].dest = 3;
	//bellManFordgraph->edge[3].weight = 2;

	//// add edge 1-4 (or A-E in above figure)
	//bellManFordgraph->edge[4].src = 1;
	//bellManFordgraph->edge[4].dest = 4;
	//bellManFordgraph->edge[4].weight = 2;

	//// add edge 3-2 (or D-C in above figure)
	//bellManFordgraph->edge[5].src = 3;
	//bellManFordgraph->edge[5].dest = 2;
	//bellManFordgraph->edge[5].weight = 5;

	//// add edge 3-1 (or D-B in above figure)
	//bellManFordgraph->edge[6].src = 3;
	//bellManFordgraph->edge[6].dest = 1;
	//bellManFordgraph->edge[6].weight = 1;

	//// add edge 4-3 (or E-D in above figure)
	//bellManFordgraph->edge[7].src = 4;
	//bellManFordgraph->edge[7].dest = 3;
	//bellManFordgraph->edge[7].weight = -3;

	//BellmanFord(bellManFordgraph, 0);

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


//BFS

//0----1
//|   /
//|  /
//| /
//2------3

//BFSGraph g(4);
//g.addEdge(0, 1);
//g.addEdge(0, 2);
//g.addEdge(1, 2);
//g.addEdge(2, 0);
//g.addEdge(2, 3);
//g.addEdge(3, 3);
//
//cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
//g.BFS(2);
//
//
//// Create a graph given in the above diagram
//DFSGraph g1(4);
//g1.addEdge(0, 1);
//g1.addEdge(0, 2);
//g1.addEdge(1, 2);
//g1.addEdge(2, 0);
//g1.addEdge(2, 3);
//g1.addEdge(3, 3);
//
//cout << "\n\nFollowing is Depth First Traversal (starting from vertex 2) \n";
//g1.DFS(2);
//
//
////Toplogical Sort
//// Create a graph given in the above diagram
//TopologicalGraph g2(4);
////g2.addEdge(5, 2);
////g2.addEdge(5, 0);
////g2.addEdge(4, 0);
////g2.addEdge(4, 1);
////g2.addEdge(2, 3);
////g2.addEdge(3, 1);
//g2.addEdge(0, 1);
//g2.addEdge(0, 2);
//g2.addEdge(1, 2);
//g2.addEdge(2, 0);
//g2.addEdge(2, 3);
//g2.addEdge(3, 3);
//
//cout << "\n\nFollowing is a Topological Sort of the given graph \n";
//g2.topologicalSort();

// Let us create the graph given in above fugure
//int V = 9;
//struct PrimsHeapGraph* PrimsHeapgraph = createPrimsHeapGraph(V);
//addEdgePrimsHeap(PrimsHeapgraph, 0, 1, 4);
//addEdgePrimsHeap(PrimsHeapgraph, 0, 7, 8);
//addEdgePrimsHeap(PrimsHeapgraph, 1, 2, 8);
//addEdgePrimsHeap(PrimsHeapgraph, 1, 7, 11);
//addEdgePrimsHeap(PrimsHeapgraph, 2, 3, 7);
//addEdgePrimsHeap(PrimsHeapgraph, 2, 8, 2);
//addEdgePrimsHeap(PrimsHeapgraph, 2, 5, 4);
//addEdgePrimsHeap(PrimsHeapgraph, 3, 4, 9);
//addEdgePrimsHeap(PrimsHeapgraph, 3, 5, 14);
//addEdgePrimsHeap(PrimsHeapgraph, 4, 5, 10);
//addEdgePrimsHeap(PrimsHeapgraph, 5, 6, 2);
//addEdgePrimsHeap(PrimsHeapgraph, 6, 7, 1);
//addEdgePrimsHeap(PrimsHeapgraph, 6, 8, 6);
//addEdgePrimsHeap(PrimsHeapgraph, 7, 8, 7);
//
//PrimMST(PrimsHeapgraph);

//UnionFind
	int V = 3, E = 3;
	UnionFindGraph* UnionFindgraph = createUnionFindGraph(V, E);

	// add edge 0-1
	UnionFindgraph->UnionFindEdge[0].src = 0;
	UnionFindgraph->UnionFindEdge[0].dest = 1;

	// add edge 1-2
	UnionFindgraph->UnionFindEdge[1].src = 1;
	UnionFindgraph->UnionFindEdge[1].dest = 2;

	// add edge 0-2
	UnionFindgraph->UnionFindEdge[2].src = 0;
	UnionFindgraph->UnionFindEdge[2].dest = 2;

	if (UnionFindisCycle(UnionFindgraph))
	printf("graph contains cycle");
	else
	printf("graph doesn't contain cycle");

	getchar();
	return 0;
}

