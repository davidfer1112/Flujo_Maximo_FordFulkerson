
// grafomatri.h

#ifndef GRAFOMATRI_H
#define GRAFOMATRI_H

#include <vector>


//calse grafo matriz
class GrafoMatriz {

    //atributos
    private:

        //numero de nodos
        int numNodos;
        //puntero de matriz
        int** matriz;
        //estado de visita(seguimiento de nodos)
        bool* visited;


//metodos
public:

    GrafoMatriz(int nodes);

    ~GrafoMatriz();

    void agregarArista(int origen, int destino, int peso);

    void imprimirGrafo();

    bool dfs(int origen, int sumidero, std::vector<int>& ruta);

    void fordFulkerson(int origen, int sumidero);
};

#endif // GRAFOMATRI_H
