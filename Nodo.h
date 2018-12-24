#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>
using namespace std;
struct Datos
{
    int id_tren;
    int id_vagon;
    string origen;
    string destino;
    string carga;
};

class Nodo {
	private:
        Datos vagon;
        Nodo *siguiente;
        friend class Lista;
    public:
        Nodo(Datos v,Nodo *sig = NULL);
        string getDestino();
        void updateIdTren(int id_tren);
        int getIdTren();
};
typedef Nodo *pnodo;
#endif
