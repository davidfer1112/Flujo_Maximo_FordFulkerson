// graph_matrix.cpp

#include "grafomatri.h"
#include <iostream>
#include <climits>


//Constructor grafo matriz
GraphMatrix::GraphMatrix(int nodes) {

    numNodes = nodes; //Asigna la cantidad de nodos

    matrix = new int*[numNodes]; //asigna memroria para cada fila

    // ciclo para inicializar la matriz
    for (int i = 0; i < numNodes; i++) {

        matrix[i] = new int[numNodes];//asigna memoria para casa columna

        for (int j = 0; j < numNodes; j++) {

            matrix[i][j] = 0; //inicializa los valores de la matriz en 0

        }
    }

    //
    visited = new bool[numNodes]{false}; // asigna memoria para los punteros de tipo bool e inicializa con valor false

}

//desctructor grafo matriz
GraphMatrix::~GraphMatrix() {

    for (int i = 0; i < numNodes; i++) {
        delete[] matrix[i];//libera la memoria de las columnas
    }

    delete[] matrix;//libera la memoria de las filas

    delete[] visited;//libera memoria de los arrglos de visita
}

void GraphMatrix::addEdge(int source, int destination, int weight) {
    if (source >= 0 && source < numNodes && destination >= 0 && destination < numNodes) {
        matrix[source][destination] = weight;
    } else {
        std::cout << "Error: Los nodos especificados están fuera de los límites del grafo." << std::endl;
    }
}

void GraphMatrix::printGraph() {
    std::cout << "Grafo dirigido representado de forma matricial:" << std::endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool GraphMatrix::dfs(int source, int sink, std::vector<int>& path) {
    visited[source] = true;
    path.push_back(source);

    if (source == sink) {
        return true;
    }

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i] && matrix[source][i] > 0) {
            if (dfs(i, sink, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

void GraphMatrix::fordFulkerson(int source, int sink) {
    int maxFlow = 0;
    std::vector<int> path;

    while (dfs(source, sink, path)) {
        int minCapacity = INT_MAX;

        for (size_t i = 1; i < path.size(); i++) {
            int u = path[i - 1];
            int v = path[i];
            minCapacity = std::min(minCapacity, matrix[u][v]);
        }

        for (size_t i = 1; i < path.size(); i++) {
            int u = path[i - 1];
            int v = path[i];
            matrix[u][v] -= minCapacity;
            matrix[v][u] += minCapacity;
        }

        maxFlow += minCapacity;

        // Mostrar la matriz actual después de cada aumento del flujo
        std::cout << "Flujo máximo: " << maxFlow << std::endl;
        printGraph();

        // Reiniciar el vector visited y el camino para el próximo aumento del flujo
        for (int i = 0; i < numNodes; i++) {
            visited[i] = false;
        }
        path.clear();
    }

    std::cout << "Flujo máximo total: " << maxFlow << std::endl;
}

