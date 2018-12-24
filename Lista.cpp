#include "Lista.h"
#include <ctime>
#include <stdlib.h>
Lista::~Lista()
{
    pnodo aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarNodo(Datos vagon)
{
    pnodo aux;
    if(listaVacia())
    {
        cabeza = new Nodo(vagon, NULL);
        finall = cabeza;
    }
    else
    {
        aux = new Nodo(vagon, NULL);
        finall->siguiente = aux;
        finall=aux;
    }
}

/*void Lista::borrarVagon(string des)
{
    pnodo anterior;
    actual= cabeza;
    while (actual->vagon.destino!=des && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza)//primer elemento
    {
        cabeza = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
        if(actual==finall)
        {
            finall=anterior;
        }
    }
    actual->siguiente=NULL;
    delete actual;

}*/

/*Datos Lista::borrarNodo(string des) // Borrar nodo y guardar los datos del nodo que vamos a borrar en un struct auxiliar,
{                                   //  que sera lo que devuelva la funcion. //
    pnodo anterior;
    actual= cabeza;
    Datos datos_aux;
    while (actual->vagon.destino!=des && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza)//primer elemento
    {
        cabeza = actual->siguiente;
    }
    else
    {
        anterior->siguiente = actual->siguiente;
        if(actual==finall)
        {
            finall=anterior;
        }
    }
    datos_aux = actual->vagon;  // Guardo los datos del nodo //
    actual->siguiente=NULL;
    delete actual;              // Borrar el nodo //
    return datos_aux;           // La funcion devuelve los datos del nodo borrado //
}*/

pnodo Lista::getSigNodo(string des)//Busca en la lista el vagon que tenga el destino especificado
{
    pnodo nodo = NULL;
    pnodo anterior = cabeza;
    actual = cabeza->siguiente;
    string currentDest;
    bool encontrado = false;
    while (!encontrado && (actual->siguiente)!=NULL)
    {
        string auxDest = actual->vagon.destino;
        if(auxDest == des)
        {
            encontrado = true;
        }
        else
        {
            anterior=actual;
            actual=actual->siguiente;
        }
    }

    if(encontrado) // tiene en cuenta el caso especial en el que lo que busca esta en la primera posicion
    {              //de la lista
        anterior->siguiente = actual->siguiente;
        actual->siguiente = NULL;
        nodo = actual;
    }
    else if(actual->vagon.destino == des)//tiene en cuenta el caso especial en el que lo que se busca esta
    {                                    // en la ultima posicion de la lista
        anterior->siguiente = actual->siguiente;
        finall = anterior;
        nodo = actual;
    }

    return nodo;
}

bool Lista::listaVacia()
{
    return cabeza == NULL;
}

Datos Lista::llenarVagon(bool v, int i)//este metodo llena los vagones
{
    bool esVagon = v;
    int indice = i;

    struct Datos tren = {0,0," "," "," "};

    string origen[6] = {"Sevilla","Zamora","Badajoz","Cuenca","Albacete"};

    int id_tren[6]= {123, 456, 789, 101, 203};
    int id_vagon = 0;
    int n_rnd = 0;
    id_vagon = 1000 + rand() % 8999;
    n_rnd = rand()%5;

    string destino[6]={"Valladolid","Zaragoza","Burgos","Orense","Bilbao"};
    string carga[6]={"Coches","Alimentos","Madera","Hierro","Ropa"};

    if (esVagon){ // Condicion para que rellene los datos de un vagon (5 VALORES). //
        tren = {id_tren[indice], id_vagon, origen[indice], destino[n_rnd], carga[n_rnd]};
    } else { // Condicion para que rellene los datos de la punta del tren (3 VALORES). //
        tren = {id_tren[indice], 0, origen[indice], destino[indice], " "};
    }
    return tren;
}

void Lista::mostrarLista()
{
    Nodo *aux;
    aux = cabeza;
    bool semaforo = false;
    while(aux)
    {
        if (!semaforo){
            cout<<"[TREN: "<<aux->vagon.id_tren<<" ("<<aux->vagon.origen<<"-"<<aux->vagon.destino<<")]"<<endl;
            aux = aux->siguiente;
            semaforo = true;
        } else {
            cout<<"Tren: "<<aux->vagon.id_tren<<" Vagon: "<<aux->vagon.id_vagon<<" ("<<aux->vagon.origen<<"-"<<aux->vagon.destino<<")"<<endl;
            aux = aux->siguiente;
        }
    }
    cout<< endl;
}
int Lista::existe(string des) // Devuelve el numero de vagones que tiene el tren con el destino especificado por parametro de la funcion. //
{
    Nodo *aux;
    aux = cabeza->siguiente;
    int cont = 0;
    while(aux)
    {
        if(aux->vagon.destino == des){
            cont++;
        }
        aux = aux->siguiente;
    }
    return cont;
}

/*Datos Lista::buscarVagon(string des) // Devuelve el numero de vagones que tiene el tren con el destino especificado por parametro de la funcion. //
{
    Nodo *aux;
    aux = cabeza;
    Datos datos_aux;
    while(aux)
    {
        if(aux->vagon.destino == des){
            datos_aux = actual->vagon;
        }
        aux = aux->siguiente;
        return datos_aux;
    }

}*/

void Lista::esSiguiente()
{
    if(actual) actual=actual->siguiente;
}
void Lista::esPrimero()
{
    actual=cabeza;
}

void Lista::esFinal()
{
    esPrimero();
    if(!listaVacia())
    while(actual->siguiente)
    esSiguiente();
}
bool Lista::esActual()
{
    return actual !=NULL;
}

pnodo Lista::primero()//Devuelve un puntero a la cabeza de la lista.
{
    return cabeza;
}

void Lista::insertaNodo(pnodo nodo)// inserta el nodo en la lista
{
    if(finall == NULL)
    {
        cout<<"FINALL ES NULL"<<"\n";
    }
    finall->siguiente = nodo;
    finall = nodo;
}
