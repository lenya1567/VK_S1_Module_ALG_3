#include <iostream>
#include <functional>

#include "list_graph.h"
#include "matrix_graph.h"
#include "set_graph.h"
#include "arc_graph.h"

void BFS(const IGraph *graph, int start, std::function<void(int)> visit)
{
    std::vector<bool> visited(graph->VerticesCount(), false);
    std::queue<int> verticesQueue;

    verticesQueue.push(start);
    while (!verticesQueue.empty())
    {
        int current = verticesQueue.front();
        verticesQueue.pop();
        visit(current);

        std::vector<int> currentVertices = graph->GetNextVertices(current);
        for (int i = 0; i < currentVertices.size(); i++)
        {
            if (!visited[currentVertices[i]])
            {
                verticesQueue.push(currentVertices[i]);
                visited[currentVertices[i]] = true;
            }
        }
    }
}

// Функция сохраняет определённый граф в переменную graph
void fillGraph(IGraph *graph)
{
    graph->AddEdge(0, 1);
    graph->AddEdge(1, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(1, 4);
    graph->AddEdge(4, 5);
    graph->AddEdge(2, 3);
    graph->AddEdge(3, 4);
}

// Функция проверяет, что BFS над графом проходит каждую вершину ровно один раз
// На вход подаётся граф, у которого от вершины 0 можно дойти до любой другой вершины
bool testGraph(IGraph *graph)
{
    int vertexCount = graph->VerticesCount();
    bool vertexUnique = true;  // Один ли раз прохошлись по рёбрам
    int vertexResultCount = 0; // Количество ребёр, которое было уже пройдено
    std::vector<bool> visited(vertexCount, false);

    BFS(graph, 0, [&](int i)
        {
        if (visited[i]) {
            vertexUnique = false;
        } else {
            vertexResultCount++;
            visited[i] = true;
        } });

    return vertexResultCount == vertexCount && vertexUnique;
}

int main()
{

    // Проверка заключается в том, что создаётся и заполняется граф
    // Потом создаётся его копия. После чего оба графа уже проверяются через testGraph.
    // В конце запускается BFS заполненного графа

    // ListGraph

    IGraph *listGraph = new ListGraph(6);
    fillGraph(listGraph);
    IGraph *listGraphCopy = new ListGraph(*listGraph);

    std::cout << "List graph test:        " << (testGraph(listGraph) ? "OK" : "NO") << std::endl;
    std::cout << "List graph copy test:   " << (testGraph(listGraphCopy) ? "OK" : "NO") << std::endl;
    BFS(listGraph, 0, [](int i)
        { std::cout << i << ' '; });
    std::cout << std::endl
              << std::endl;

    delete listGraph;
    delete listGraphCopy;

    // MatrixGraph

    IGraph *matrixGraph = new MatrixGraph(6);
    fillGraph(matrixGraph);
    IGraph *matrixGraphCopy = new MatrixGraph(*matrixGraph);

    std::cout << "Matrix graph test:      " << (testGraph(matrixGraph) ? "OK" : "NO") << std::endl;
    std::cout << "Matrix graph copy test: " << (testGraph(matrixGraphCopy) ? "OK" : "NO") << std::endl;
    BFS(matrixGraph, 0, [](int i)
        { std::cout << i << ' '; });
    std::cout << std::endl
              << std::endl;

    delete matrixGraph;
    delete matrixGraphCopy;

    // SetGraph

    IGraph *setGraph = new SetGraph(6);
    fillGraph(setGraph);
    IGraph *setGraphCopy = new SetGraph(*setGraph);

    std::cout << "Set graph test:         " << (testGraph(setGraph) ? "OK" : "NO") << std::endl;
    std::cout << "Set graph copy test:    " << (testGraph(setGraphCopy) ? "OK" : "NO") << std::endl;
    BFS(setGraph, 0, [](int i)
        { std::cout << i << ' '; });
    std::cout << std::endl
              << std::endl;

    delete setGraph;
    delete setGraphCopy;

    // ArcGraph

    IGraph *arcGraph = new ArcGraph(6);
    fillGraph(setGraph);
    IGraph *arcGraphCopy = new ArcGraph(*setGraph);

    std::cout << "Arc graph test:         " << (testGraph(arcGraph) ? "OK" : "NO") << std::endl;
    std::cout << "Arc graph copy test:    " << (testGraph(arcGraphCopy) ? "OK" : "NO") << std::endl;
    BFS(arcGraph, 0, [](int i)
        { std::cout << i << ' '; });
    std::cout << std::endl
              << std::endl;

    delete arcGraph;
    delete arcGraphCopy;

    return 0;
}