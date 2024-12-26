#include "arc_graph.h"

ArcGraph::ArcGraph(int initVertexCount) : vertexCount(initVertexCount) {}

ArcGraph::ArcGraph(const IGraph &graph)
{
    vertexCount = graph.VerticesCount();

    for (int i = 0; i < vertexCount; i++)
    {
        for (int V : graph.GetNextVertices(i))
        {
            edges.push_back(std::pair<int, int>(i, V));
        }
    }
}

int ArcGraph::VerticesCount() const
{
    return vertexCount;
}

void ArcGraph::AddEdge(int from, int to)
{
    edges.push_back(std::pair<int, int>(from, to));
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    std::vector<int> adjList;
    for (auto &edge : edges)
    {
        if (edge.first == vertex)
            adjList.push_back(edge.second);
    }
    return adjList;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> adjList;
    for (auto &edge : edges)
    {
        if (edge.second == vertex)
            adjList.push_back(edge.first);
    }
    return adjList;
}