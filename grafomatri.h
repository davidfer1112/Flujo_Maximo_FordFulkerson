
// grafomatri.h

#ifndef GRAFOMATRI_H
#define GRAFOMATRI_H

#include <vector>


//calse grafo matriz
class GraphMatrix {

    //atributos
    private:

        //numero de nodos
        int numNodes;
        //puntero de matriz
        int** matrix;
        //estado de visita(seguimiento de nodos)
        bool* visited;


//metodos
public:

    GraphMatrix(int nodes);

    ~GraphMatrix();

    void addEdge(int source, int destination, int weight);

    void printGraph();

    bool dfs(int source, int sink, std::vector<int>& path);

    void fordFulkerson(int source, int sink);
};

#endif // GRAFOMATRI_H
