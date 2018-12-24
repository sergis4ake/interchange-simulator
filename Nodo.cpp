#include "Nodo.h"

Nodo::Nodo(Datos v, Nodo *sig)
{
    //ctor
    vagon = v;
    siguiente = sig;
}

string Nodo::getDestino()
{
    return vagon.destino;
}

void Nodo::updateIdTren(int id_tren)
{
    vagon.id_tren = id_tren;
}

int Nodo::getIdTren()
{
    return vagon.id_tren;
}
