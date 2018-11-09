//
// Created by juanp on 9/11/2018.
//
#include <conio.h>
#include <iostream>
#include <stdio.h>


#ifndef ENCODER_2018_MASTER_NODOARBOLAVL_01_H
#define ENCODER_2018_MASTER_NODOARBOLAVL_01_H

template <class T>

/**        *.- codigo: clave de la palabra correspondiente
           *.- corresponde: Palabra a la que codifica tal codigo
           *.- alturaIzq: Mantendra el valor de la altura izquierda del nodo
           *.- alturaDere: Mantendra el valor de la altura derecha del nodo
           *.- fe: Almacenara el factor equilibrio
           *.- buscado: Variable para guardar un valor buscado
*/

class NodoArbolAVL__01  {

public:
    T codigo;
    char corresponde[20];
    int fe, alturaIzq, alturaDere;
    int buscado = 0;
    int sw = 0;                         /**  Si es 1= insertar, 0=fe */
    NodoArbolAVL__01 *izq;              /** Apunta a la izquierda del nodo */
    NodoArbolAVL__01 *dere;             /** Apunta a la derecha del nodo */
    NodoArbolAVL__01 *padre;            /** Apunta hacia el padre del nodo */
    NodoArbolAVL__01 *raiz;             /** Mantendra el enlace a la raiz o cabeza de todo el arbol, este puntero se asigna una vez y se modifica si se reestructura o elimina nodo.  */
    NodoArbolAVL__01 *nuevo;            /** Almacenara cada nuevo nodo que se cree. */
    NodoArbolAVL__01 *recorrer;         /** Recorre el arbol para encontra x nodo */
    NodoArbolAVL__01 *PadreAB;          /** Mantiene el puntero del padre de un nodo X con el que se esta trabajando. */
    NodoArbolAVL__01 *sHijo;            /** Mantiene el puntero Hijo segun el nodo que se esta trabajando. */
    NodoArbolAVL__01 *predecesor;       /** Mantiene el puntero en el nodo que relevara al padre cuando este sea modificado o eliminado. */
    NodoArbolAVL__01 *abuelo;           /** Mantiene el puntero en el padre del padre del nodo que se este trabajando. */
    NodoArbolAVL__01 *hijoHijo;         /** Mantiene el punteror en el hijo del hijo. */



    /** Setear nuevo dato
        *.- Variable "nuevo" almacenara una nueva hoja para el arbol.
    */

    NodoArbolAVL__01 *nuevoNodo(int Codigo , char Corresponde)
        {
            nuevo = new(NodoArbolAVL__01);                                /** Crea la reserva de espacio en memoria. */
            nuevo->codigo = Codigo;
            nuevo->corresponde[20] = Corresponde;
            nuevo->izq=NULL;                                              /** Punteros a tierra */
            nuevo->dere=NULL;                                             /** Punteros a tierra */
            nuevo->alturaIzq=0;                                           /** Setea en cero la altura izquierda el nodo */
            nuevo->alturaDere=0;                                          /** Setea en cero la altura derecha el nodo */
            nuevo->fe= nuevo->alturaDere-nuevo->alturaIzq;                /** Calculo del factor equilibrio, podria asignarse el valor cero desde la entrada. */

            return nuevo;
        };


};




#endif //ENCODER_2018_MASTER_NODOARBOLAVL_01_H
