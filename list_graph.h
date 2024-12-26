#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include <vector>
#include "igraph.h"

class ListGraph : public IGraph
{
    std::vector<std::vector<int>> adjLists;
    std::vector<std::vector<int>> prevLists;

public:
    ListGraph(int vertexCount);
    ListGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif