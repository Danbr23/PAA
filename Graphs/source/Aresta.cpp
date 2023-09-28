#include "../header/Aresta.h"

Aresta::Aresta(){};

Aresta::Aresta(Vertice origem, Vertice destino){
    Aresta::origem = origem;
    Aresta::destino = destino;
};

Aresta::Aresta(Vertice origem, Vertice destino, double peso){

    Aresta::origem = origem;
    Aresta::destino = destino;
    Aresta::peso = peso;
};

Vertice Aresta::getOrigem(){
    return Aresta::origem;
};

void Aresta::setOrigem(Vertice origem){
    Aresta::origem = origem;
};

Vertice Aresta::getDestino(){
    return Aresta::destino;
};

void Aresta::setDestino(Vertice destino){
    Aresta::destino=destino;
};

double Aresta::getPeso(){
    return Aresta::peso;
};

void Aresta::setPeso(double peso){
    Aresta::peso=peso;
};




