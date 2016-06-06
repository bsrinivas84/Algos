// C / C++ program for Prim's MST for adjacency list representation of PrimsHeapGraph

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a node in adjacency list
struct PrimsHeapAdjListNode
{
	int dest;
	int weight;
	struct PrimsHeapAdjListNode* next;
};

// A structure to represent an adjacency liat
struct PrimsHeapAdjList
{
	struct PrimsHeapAdjListNode *head;  // pointer to head node of list
};

// A structure to represent a PrimsHeapGraph. A PrimsHeapGraph is an array of adjacency lists.
// Size of array will be V (number of vertices in PrimsHeapGraph)
struct PrimsHeapGraph
{
	int V;
	struct PrimsHeapAdjList* array;
};

// A utility function to create a new adjacency list node
struct PrimsHeapAdjListNode* newPrimsHeapAdjListNode(int dest, int weight)
{
	struct PrimsHeapAdjListNode* newNode =
		(struct PrimsHeapAdjListNode*) malloc(sizeof(struct PrimsHeapAdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a PrimsHeapGraph of V vertices
struct PrimsHeapGraph* createPrimsHeapGraph(int V)
{
	struct PrimsHeapGraph* PrimsHeapGraph = (struct PrimsHeapGraph*) malloc(sizeof(struct PrimsHeapGraph));
	PrimsHeapGraph->V = V;

	// Create an array of adjacency lists.  Size of array will be V
	PrimsHeapGraph->array = (struct PrimsHeapAdjList*) malloc(V * sizeof(struct PrimsHeapAdjList));

	// Initialize each adjacency list as empty by making head as NULL
	for (int i = 0; i < V; ++i)
		PrimsHeapGraph->array[i].head = NULL;

	return PrimsHeapGraph;
}

// Adds an edge to an undirected PrimsHeapGraph
void addEdgePrimsHeap(struct PrimsHeapGraph* PrimsHeapGraph, int src, int dest, int weight)
{
	// Add an edge from src to dest.  A new node is added to the adjacency
	// list of src.  The node is added at the begining
	struct PrimsHeapAdjListNode* newNode = newPrimsHeapAdjListNode(dest, weight);
	newNode->next = PrimsHeapGraph->array[src].head;
	PrimsHeapGraph->array[src].head = newNode;

	// Since PrimsHeapGraph is undirected, add an edge from dest to src also
	newNode = newPrimsHeapAdjListNode(src, weight);
	newNode->next = PrimsHeapGraph->array[dest].head;
	PrimsHeapGraph->array[dest].head = newNode;
}

// Structure to represent a min heap node
struct MinHeapNode
{
	int  v;
	int key;
};

// Structure to represent a min heap
struct MinHeap
{
	int size;      // Number of heap nodes present currently
	int capacity;  // Capacity of min heap
	int *pos;     // This is needed for decreaseKey()
	struct MinHeapNode **array;
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* PrimsHeapnewMinHeapNode(int v, int key)
{
	struct MinHeapNode* minHeapNode =
		(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->key = key;
	return minHeapNode;
}

// A utilit function to create a Min Heap
struct MinHeap* PrimsHeapcreateMinHeap(int capacity)
{
	struct MinHeap* minHeap =
		(struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array =
		(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void PrimsHeapswapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void PrimsHeapminHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->key < minHeap->array[smallest]->key)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->key < minHeap->array[smallest]->key)
		smallest = right;

	if (smallest != idx)
	{
		// The nodes to be swapped in min heap
		MinHeapNode *smallestNode = minHeap->array[smallest];
		MinHeapNode *idxNode = minHeap->array[idx];

		// Swap positions
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		PrimsHeapswapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		PrimsHeapminHeapify(minHeap, smallest);
	}
}

// A utility function to check if the given minHeap is ampty or not
int PrimsHeapisEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* PrimsHeapextractMin(struct MinHeap* minHeap)
{
	if (PrimsHeapisEmpty(minHeap))
		return NULL;

	// Store the root node
	struct MinHeapNode* root = minHeap->array[0];

	// Replace root node with last node
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--minHeap->size;
	PrimsHeapminHeapify(minHeap, 0);

	return root;
}

// Function to decreasy key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void PrimsHeapdecreaseKey(struct MinHeap* minHeap, int v, int key)
{
	// Get the index of v in  heap array
	int i = minHeap->pos[v];

	// Get the node and update its key value
	minHeap->array[i]->key = key;

	// Travel up while the complete tree is not hepified.
	// This is a O(Logn) loop
	while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
	{
		// Swap this node with its parent
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		PrimsHeapswapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool PrimsHeapisInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

// A utility function used to print the constructed MST
void PrimsHeapprintArr(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
		printf("%d - %d\n", arr[i], i);
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(struct PrimsHeapGraph* PrimsHeapGraph)
{
	int V = PrimsHeapGraph->V;// Get the number of vertices in PrimsHeapGraph
	int parent[9];   // Array to store constructed MST
	int key[9];      // Key values used to pick minimum weight edge in cut

					 // minHeap represents set E
	struct MinHeap* minHeap = PrimsHeapcreateMinHeap(V);

	// Initialize min heap with all vertices. Key value of
	// all vertices (except 0th vertex) is initially infinite
	for (int v = 1; v < V; ++v)
	{
		parent[v] = -1;
		key[v] = INT_MAX;
		minHeap->array[v] = PrimsHeapnewMinHeapNode(v, key[v]);
		minHeap->pos[v] = v;
	}

	// Make key value of 0th vertex as 0 so that it
	// is extracted first
	key[0] = 0;
	minHeap->array[0] = PrimsHeapnewMinHeapNode(0, key[0]);
	minHeap->pos[0] = 0;

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes
	// not yet added to MST.
	while (!PrimsHeapisEmpty(minHeap))
	{
		// Extract the vertex with minimum key value
		struct MinHeapNode* minHeapNode = PrimsHeapextractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

								// Traverse through all adjacent vertices of u (the extracted
								// vertex) and update their key values
		struct PrimsHeapAdjListNode* pCrawl = PrimsHeapGraph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If v is not yet included in MST and weight of u-v is
			// less than key value of v, then update key value and
			// parent of v
			if (PrimsHeapisInMinHeap(minHeap, v) && pCrawl->weight < key[v])
			{
				key[v] = pCrawl->weight;
				parent[v] = u;
				PrimsHeapdecreaseKey(minHeap, v, key[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	/// print edges of MST
	PrimsHeapprintArr(parent, V);
}