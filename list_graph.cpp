#include "list_graph.h"

ListGraph::ListGraph(int vertexCount)
{
    adjLists.resize(vertexCount);
    prevLists.resize(vertexCount);
}

ListGraph::ListGraph(const IGraph &graph)
{
    adjLists.resize(graph.VerticesCount());
    prevLists.resize(graph.VerticesCount());

    for (int i = 0; i < adjLists.size(); i++)
    {
        adjLists[i] = graph.GetNextVertices(i);
        prevLists[i] = graph.GetPrevVertices(i);
    }
}

int ListGraph::VerticesCount() const
{
    return adjLists.size();
}

void ListGraph::AddEdge(int from, int to)
{
    adjLists[from].push_back(to);
    prevLists[to].push_back(from);
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    return adjLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
    return prevLists[vertex];
}