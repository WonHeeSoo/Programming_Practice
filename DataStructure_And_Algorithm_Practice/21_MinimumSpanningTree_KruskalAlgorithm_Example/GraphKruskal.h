#pragma once
#include <queue>
#include <list>

using namespace std;

struct Edge
{
	int		startVertex;
	int		endVertex;
	int		weight;

	Edge(int startVertex = Vertex::INVALID_ID, int endVertex = Vertex::INVALID_ID, int weight = Vertex::INVALID_ID)
		: startVertex(startVertex), endVertex(endVertex), weight(weight) {}
};

struct Vertex
{
	int				id;
	bool			visited;
	list<Edge>		edges;

	static const int INVALID_ID;

	Vertex(int id = INVALID_ID, bool visited = false) : id(id), visited(visited) {}
};

class GraphKruskal
{
public:
	GraphKruskal(int numVertex, int numEdge);
	~GraphKruskal();

public:
	bool InsertEdge(int fromVertex, int toVertex, int weight);
	bool RemoveEdge(int fromVertex, int toVertex, int weight);
	bool ConnectVertices(int AVertex, int BVertex);
	bool KruskalMST();

protected:
	void HandleVertex(const Vertex &vertex);
	
	void ResetVisited();

protected:
	int						nVertex;
	int						nEdge;
	Vertex					*vertices;
	priority_queue<Edge>	priorityEdges;
};

