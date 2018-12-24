#include <iostream>
#include <string>
#include "Lista.h"
#include <ctime>
#include <stdlib.h>
int main ()  {

    // CREA TRENES //

    srand(time(NULL)); // Necesario para crear un número aleatorio cada vez diferente. //

    Lista tren[6]; // Array de listas, que serán nuestros 5 trenes. //

    int n_rnd=0;
    int i=0, j=0;
    int x = 0;
    int y = 0;

    for (i=0;i<5;i++){
        n_rnd = 1 + rand() % 4; // Numero de vagones aleatorio para cada tren. //
        tren[i].insertarNodo(tren[i].llenarVagon(false,i)); // Llenar la punta del tren con sus datos. //
        for (j=0;j<=n_rnd;j++){
            tren[i].insertarNodo(tren[i].llenarVagon(true,i)); //Insertamos datos aleatorios con el metodo llenarVagon en cada vagon
        }                                                //y a su vez un numero de vagones aleatorios en cada tren. //
        tren[i].mostrarLista();
        cout<<"============\n";
    }

    // ORDENAR TRENES //
    for(x=0; x < 5; x++)
    {
        pnodo primerVagon = tren[x].primero(); //guarda el puntero de la cabeza del tren
        string destino = primerVagon->getDestino(); //saca un dato del puntero y lo guarda en destino
        int id_tren = primerVagon->getIdTren(); //saca un dato del puntero y lo guarda en id_tren
        for (y=0;y<5;y++)
        {
            if(y!=x) //condicion que permite no entrar en el tren con el destino igual al que se va a buscar.
            {
               int z = 0;
               int total = tren[y].existe(destino); //contabiliza
               for(z = 0; z < total; z++)
               {
                    pnodo nodoARecolocar = NULL;//inicializa el puntero a null
                    nodoARecolocar = tren[y].getSigNodo(destino);//busca en la lista el vagon con el destino especificado y lo guarda en nodoARecolocar
                    nodoARecolocar->updateIdTren(id_tren);//modifica los id_tren de los vagones cambiados.
                    tren[x].insertaNodo(nodoARecolocar);//inserta el nodo en la lista correspondiente.
               }
           }
        }
    }

    int auxCont = 0;
    cout<<"************============************"<<"\n";
    cout<<"\n";
    for(auxCont = 0; auxCont < 5; auxCont++)
    {
        tren[auxCont].mostrarLista();
    }
    cout<<"************============************"<<"\n";

    return 0;
}

