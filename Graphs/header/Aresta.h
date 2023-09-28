#pragma once
#include "Vertice.h"

class Aresta{

    private:
        Vertice origem;
        Vertice destino;
        double peso;

    public:

        Aresta();

        Aresta(Vertice origem, Vertice destino);

        Aresta(Vertice origem, Vertice destino, double peso);

        Vertice getOrigem();

        void setOrigem(Vertice origem);

        Vertice getDestino();

        void setDestino(Vertice destino);

        double getPeso();

        void setPeso(double peso);


};