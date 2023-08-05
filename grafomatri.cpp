// graph_matriz.cpp

#include "grafomatri.h"
#include <iostream>
#include <climits>
#include <iomanip>
#include <unistd.h>


//Constructor grafo matriz
GrafoMatriz::GrafoMatriz(int nodos) {

    numNodos = nodos; //Asigna la cantidad de nodos

    matriz = new int*[numNodos]; //asigna memroria para cada fila

    // ciclo para inicializar la matriz
    for (int i = 0; i < numNodos; i++) {

        matriz[i] = new int[numNodos];//asigna memoria para casa columna

        for (int j = 0; j < numNodos; j++) {

            matriz[i][j] = 0; //inicializa los valores de la matriz en 0

        }
    }

    //
    visited = new bool[numNodos]{false}; // asigna memoria para los punteros de tipo bool e inicializa con valor false

}


//desctructor grafo matriz
GrafoMatriz::~GrafoMatriz() {

    for (int i = 0; i < numNodos; i++) {
        delete[] matriz[i];//libera la memoria de las columnas
    }

    delete[] matriz;//libera la memoria de las filas

    delete[] visited;//libera memoria de los arrglos de visita
}


//funcion para agregar una arista (conecciones)
void GrafoMatriz::agregarArista(int origen, int destino, int peso) {

    //Verifica que la posición inicial y posición inicial no sean menores a 0 ni mayores a la cantidad de nodos
    if (origen >= 0 && origen < numNodos && destino >= 0 && destino < numNodos) {

        matriz[origen][destino] = peso;//Asigna el peso de la coneccion en la matriz

    }
    else {
        std::cout << "Error: Los nodos especificados están fuera de los límites del grafo." << std::endl;
    }

}


//imprimir grafo
void GrafoMatriz::imprimirGrafo() {
    std::cout << std::endl << "Matriz de adyacencia:" << std::endl << std::endl;

    // Imprimir encabezado de columnas con números de nodo
    std::cout << std::setw(4) << " "; // Espacio en blanco para esquina superior izquierda

    for (int j = 0; j < numNodos; j++) {
        std::cout << std::setw(4) << j + 1;
    }
    std::cout << std::endl;

    // Imprimir línea divisoria horizontal
    std::cout << "   +";
    for (int j = 0; j < numNodos; j++) {
        std::cout << "----";
    }
    std::cout << std::endl;

    for (int i = 0; i < numNodos; i++) {
        // Imprimir número de nodo de la fila
        std::cout << std::setw(3) << i + 1 << "|";

        for (int j = 0; j < numNodos; j++) {
            std::cout << std::setw(4) << matriz[i][j];
        }
        std::cout << std::endl;
    }

    // Imprimir línea divisoria horizontal final
    std::cout << "   +";
    for (int j = 0; j < numNodos; j++) {
        std::cout << "----";
    }
    std::cout << std::endl;
}


//recorrido profundo del grafo
bool GrafoMatriz::dfs(int origen, int sumidero, std::vector<int>& ruta) {

    visited[origen] = true;//marca como visitado el nodo

    ruta.push_back(origen);//lleva un registro de los que se visita durante el recorrido

    if (origen == sumidero) {// si el origen llega a ser igual al sumidero, existe una ruta
        return true;
    }

    //recorre los nodos
    for (int i = 0; i < numNodos; i++) {

        //si el nodo no ha sido visitado y si existe una arista entre los nodos
        if (!visited[i] && matriz[origen][i] > 0) {

            if (dfs(i, sumidero, ruta)) {
                return true; //encuentra una ruta
            }
        }
    }

    ruta.pop_back(); //si no se encontro una ruta, se elimina el nodo actual
    return false;
}


void GrafoMatriz::fordFulkerson(int origen, int sumidero) {

    int maxFlujo = 0; //variable para contar el flujo

    std::vector<int> ruta; //vector para almacenar la ruta encontrada


    //ciclo que se ejecuta mientras se pueda encontrar una ruta
    while (dfs(origen, sumidero, ruta)) {

        int capacidadMinima = INT_MAX;

        //busca la capicidad minima
        for (size_t i = 1; i < ruta.size(); i++) {
            int u = ruta[i - 1];
            int v = ruta[i];
            capacidadMinima = std::min(capacidadMinima, matriz[u][v]); //para almacenar la capacidad minima
        }

        //actualiza el valor de las aristas (caminos)
        for (size_t i = 1; i < ruta.size(); i++) {
            int u = ruta[i - 1];
            int v = ruta[i];
            matriz[u][v] -= capacidadMinima;
            matriz[v][u] += capacidadMinima;
        }

        maxFlujo += capacidadMinima;//se actualiza el valor de flujo maximo

        // Muestra el flujo y la matriz
        std::cout << "Flujo maximo: " << maxFlujo << std::endl;
        imprimirGrafo();
        std::cout<<std::endl<<".........cargando"<<std::endl<<std::endl;
        sleep(3);

        // Reiniciar el vector visitado y el camino para el próximo aumento del flujo
        for (int i = 0; i < numNodos; i++) {
            visited[i] = false;
        }
        ruta.clear();
    }

    std::cout << "Flujo maximo total: " << maxFlujo << std::endl;
}

