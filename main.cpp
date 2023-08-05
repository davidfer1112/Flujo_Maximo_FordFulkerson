// main.cpp

#include "grafomatri.h"
#include <iostream>
#include <unistd.h>

int main() {


    // Crear un grafo con 8 nodos
    GrafoMatriz graph(8);

    // Matriz de adyacencia
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
            graph.agregarArista(i, j, adjacencyMatrix[i][j]);
        }
    }

    // Imprimir el grafo inicial
    std::cout << "Grafo inicial:" << std::endl;
    graph.imprimirGrafo();
    std::cout << std::endl;

    // Ejecutar el algoritmo de Ford-Fulkerson y mostrar paso a paso
    std::cout << "Algoritmo de Ford-Fulkerson:" << std::endl<< std::endl;
    graph.fordFulkerson(0, 7);


    std::cout<<std::endl<<"Fin del programa :)"<<std::endl<<std::endl;

    return 0;
}
