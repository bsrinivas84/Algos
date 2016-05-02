// a structure to represent a weighted edge in graph
struct KruskalsEdge
{
	int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct KruskalsGraph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges. Since the graph is
	// undirected, the edge from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	struct KruskalsEdge* edge;
}; 
