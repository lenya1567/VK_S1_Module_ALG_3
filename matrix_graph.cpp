#include "matrix_graph.h"

MatrixGraph::MatrixGraph(int vertexCount)
{
    matrix.resize(vertexCount);
    for (auto &row : matrix)
    {
        row.resize(vertexCount);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph)
{
    matrix.resize(graph.VerticesCount());
    for (auto &row : matrix)
    {
        row.resize(matrix.size());
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int vertex : graph.GetNextVertices(i))
        {
            matrix[i][vertex] = true;
        }
        for (int vertex : graph.GetPrevVertices(i))
        {
            matrix[vertex][i] = true;
        }
    }
}

int MatrixGraph::VerticesCount() const
{
    return matrix.size();
}

void MatrixGraph::AddEdge(int from, int to)
{
    matrix[from][to] = true;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    std::vector<int> adjList;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[vertex][i])
            adjList.push_back(i);
    }
    return adjList;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevAdjList;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][vertex])
            prevAdjList.push_back(i);
    }
    return prevAdjList;
}