#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include "igraph.h"
#include <iostream>

class MatrixGraph : public IGraph
{
    std::vector<std::vector<bool>> matrix;

public:
    MatrixGraph(int vertexCount);
    MatrixGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif