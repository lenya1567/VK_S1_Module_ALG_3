#include "set_graph.h"

SetGraph::SetGraph(int vertexCount)
{
    adjLists.resize(vertexCount);
}

SetGraph::SetGraph(const IGraph &graph)
{
    adjLists.resize(graph.VerticesCount());

    for (int i = 0; i < adjLists.size(); i++)
    {
        std::vector<int> nextV = graph.GetNextVertices(i);

        adjLists[i].insert(nextV.begin(), nextV.end());
    }
}

int SetGraph::VerticesCount() const
{
    return adjLists.size();
}

void SetGraph::AddEdge(int from, int to)
{
    adjLists[from].insert(to);
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    return std::vector<int>(adjLists[vertex].begin(), adjLists[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevAdjList;
    for (int i = 0; i < adjLists.size(); i++)
    {
        if (adjLists[i].find(i) != adjLists[i].end())
            prevAdjList.push_back(i);
    }
    return prevAdjList;
}