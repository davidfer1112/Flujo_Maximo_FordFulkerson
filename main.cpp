// main.cpp

#include "grafomatri.h"
#include <iostream>

int main() {


    // Crear un grafo con 8 nodos
    GraphMatrix graph(8);

    // Definir la matriz de adyacencia
    int adjacencyMatrix[8][8] = {
        {0, 8, 5, 9, 0, 0, 0, 0},
        {0, 0, 0, 0, 9, 0, 0, 0},
        {0, 3, 0, 0, 0, 4, 0, 0},
        {0, 0, 6, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 3, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 2, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Copiar los valores de la matriz de adyacencia al grafo
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            graph.addEdge(i, j, adjacencyMatrix[i][j]);
        }
    }

    // Imprimir el grafo inicial
    std::cout << "Grafo inicial:" << std::endl;
    graph.printGraph();
    std::cout << std::endl;

    // Ejecutar el algoritmo de Ford-Fulkerson y mostrar paso a paso
    std::cout << "Algoritmo de Ford-Fulkerson:" << std::endl;
    graph.fordFulkerson(0, 7);

    return 0;
}
