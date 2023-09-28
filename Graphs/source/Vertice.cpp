#include "../header/Vertice.h"

Vertice::Vertice(){};

Vertice::Vertice(int v){ vertice = v; };

int Vertice::id(){ return vertice; };

void Vertice::setVertice(int v){vertice=v;};