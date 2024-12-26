#ifndef ARC_GRAPH_H
#define ARC_GRAPH_H

#include <vector>
#include "igraph.h"

class ArcGraph : public IGraph
{
    int vertexCount;
    std::vector<std::pair<int, int>> edges;

public:
    ArcGraph(int vertexCount);
    ArcGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif