#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <string>

class Lista
{
    private:
        pnodo cabeza, finall;
        pnodo actual;
    public:
        Lista(){cabeza = actual = NULL;}
        ~Lista();
        void insertarNodo(Datos vagon);
        Datos borrarNodo(string des);
        void borrarVagon(string des);
        bool listaVacia();
        void mostrarLista();
        void esSiguiente();
        void esPrimero();
        void esUltimo();
        void esFinal();
        bool esActual();
        int valorActual();
        Datos llenarVagon(bool v, int i);
        int existe(string des);
        Datos buscarVagon(string des);
        pnodo primero();
        pnodo getSigNodo(string des);
        void insertaNodo(pnodo nodoRecolocado);
};

#endif // LISTA_H
