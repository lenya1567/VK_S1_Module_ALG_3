#ifndef SET_GRAPH_H
#define SET_GRAPH_H

#include <vector>
#include <set>

#include "igraph.h"

class SetGraph : public IGraph
{
    std::vector<std::set<int>> adjLists;
    std::vector<std::set<int>> prevLists;

public:
    SetGraph(int vertexCount);
    SetGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif