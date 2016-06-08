
// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include "stdafx.h"
#include<iostream>
#include <list>
#include <stack>

using namespace std;

// This class represents a directed BFSGraph using adjacency list representation
class BFSGraph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
public:
	BFSGraph(int V);  // Constructor
	void addEdge(int v, int w); // function to add an edge to BFSGraph
	void BFS(int s);  // prints BFS traversal from a given source s
};


class DFSGraph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
	void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
	DFSGraph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void DFS(int v);    // DFS traversal of the vertices reachable from v
};

class TopologicalGraph
{
	int V;    // No. of vertices'

			  // Pointer to an array containing adjacency listsList
	list<int> *adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	TopologicalGraph(int V);   // Constructor

					// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};


// A structure to represent a node in adjacency list
struct PrimsHeapAdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct PrimsAdjList
{
	struct PrimsHeapAdjListNode *head;  // pointer to head node of list
};

// A structure to represent a PrimsHeapGraph. A PrimsHeapGraph is an array of adjacency lists.
// Size of array will be V (number of vertices in PrimsHeapGraph)
struct PrimsHeapGraph
{
	int V;
	struct PrimsAdjList* array;
};

// A utility function to create a new adjacency list node
//struct PrimsHeapAdjListNode* newAdjListNode1(int dest, int weight)
//{
//	struct PrimsHeapAdjListNode* newNode =
//		(struct PrimsHeapAdjListNode*) malloc(sizeof(struct PrimsHeapAdjListNode));
//	newNode->dest = dest;
//	newNode->weight = weight;
//	newNode->next = NULL;
//	return newNode;
//}

//Union-Find
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


//Union-Find-Rank-Compression
struct  UnionFindFRCEdge 
{
	int src, dest;
};

// a structure to represent a  UnionFindFRCGraph
struct  UnionFindFRCGraph
{
	// V-> Number of vertices, E-> Number of  UnionFindFRCEdges
	int V, E;

	//  UnionFindFRCGraph is represented as an array of  UnionFindFRCEdges
	struct  UnionFindFRCEdge*  UnionFindFRCEdge;
};

struct  UnionFindFRCsubset
{
	int parent;
	int rank;
};
