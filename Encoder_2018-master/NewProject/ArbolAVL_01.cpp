//
// Created by juanp on 9/11/2018.
//

#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

#include "NodoArbolAVL__01.h"
#include "ArbolAVL_01.h"


void ArbolAVL_01::preorden(NodoArbolAVL__01 *recorrer){
/** Recorrido preOrden */

    if (recorrer != NULL) {
     /**cout<<"Clave "<<recorrer->codigo<<endl;
		cout<<"Codifica a: "<<recorrer->corresponde<<endl;
		*/
        preorden(recorrer->izq);
        preorden(recorrer->dere);
    }
}

void ArbolAVL_01::inorden(NodoArbolAVL__01 *recorrer){
/** Recorrido InOrden */

    if (recorrer != NULL) {
        inorden(recorrer->izq);
     /**cout<<"Clave "<<recorrer->codigo<<endl;
		cout<<"Codifica a: "<<recorrer->corresponde<<endl;
     */
         inorden(recorrer->dere);
    }
}

void ArbolAVL_01::postorden(NodoArbolAVL__01 *recorrer){
/** Recorrido postOrden */

    if (recorrer != NULL) {
        postorden(recorrer->izq);
        postorden(recorrer->dere);
    /** cout<<"Clave "<<recorrer->codigo<<endl;
		cout<<"Codifica a: "<<recorrer->corresponde<<endl;
    */
     }
}

void ArbolAVL_01::insertarNuevo( NodoArbolAVL__01 *recorrer, NodoArbolAVL__01 *nuevo, NodoArbolAVL__01 *PadreAB){
/** Recursivamente se llama asi mismo hasta encontrar la ubicacion donde se guardara el nuevo nodo, envio como
    parametros (La direccion del lado del arbol hacia donde entrara, La nueva hoja, Referencia al padre. */


    if (raiz==NULL){                     /** Si es el primer nodo entonces la raiz aun sera nula porque no existe nada dentro de ella. */
        raiz=nuevo;                      /** Asignar a la raiz el valor del nuevo nodo creado...*/
        raiz->padre=NULL;
    }else{
        if(nuevo->codigo <= recorrer->codigo){
            if(recorrer->izq!=NULL){
                PadreAB=recorrer->izq;
                insertarNuevo(recorrer->izq, nuevo, PadreAB);
            }else{
                recorrer->izq=nuevo;
                nuevo->padre=PadreAB;
                return;
            }
        }else
        if (nuevo->codigo > recorrer->codigo){
            if (recorrer->dere!=NULL){
                PadreAB=recorrer->dere;
                insertarNuevo(recorrer->dere, nuevo, PadreAB);
            }else{
                recorrer->dere=nuevo;
                nuevo->padre=PadreAB;
                return;
            }
        }
    }
}

void ArbolAVL_01::agregarDatos( int Codigo , char Corresponde) {
    recorrer = raiz;                                                 /** Se apunta a recorrer en al mismo nodo donde apunta la raiz */
    nuevo = nuevoNodo(Codigo , Corresponde);                         /** Almacena el nuevo nodo para luego insertarlo en el arbol. */

    if (exiteenArbol(recorrer, nuevo->codigo) == 1) {                /** Evalua si el nodo ya existe en el arbol. */
        PadreAB = raiz;
        insertarNuevo(recorrer, nuevo, PadreAB);
    }
    necesidadEquilibrar(recorrer);
}

int ArbolAVL_01::exiteenArbol(NodoArbolAVL__01 *recorrer, int buscado){
/** Funcion que devuelve 0 si el dato existe en un arbol y 1 si no existe. */


    if (recorrer==NULL){
        return 1;
    }else{
        if(buscado<recorrer->codigo){
            exiteenArbol(recorrer->izq, buscado);
        }else if (buscado>recorrer->codigo){
            exiteenArbol(recorrer->dere, buscado);
        }else{
            return 0;
        }
    }
}

int ArbolAVL_01::altura(NodoArbolAVL__01 *recorrer){
    if (recorrer == NULL)   /** Si el nodo esta vacio entonces que salga,
        return 0 ;              devuelve el valor cero. */
    else{
        recorrer->alturaIzq=altura (recorrer->izq);
        recorrer->alturaDere=altura (recorrer->dere);
        recorrer->fe=recorrer->alturaDere-recorrer->alturaIzq;

        if (recorrer->alturaIzq > recorrer->alturaDere)
            return recorrer->alturaIzq + 1;
        else
            return recorrer->alturaDere + 1;
    }
}

void ArbolAVL_01::necesidadEquilibrar(NodoArbolAVL__01 *recorrer){
/**Con esta funcion analiza si es necesario equilibrar el arbol, esta funcion busca el valor -2 o 2. */

    if (recorrer != NULL) {

        necesidadEquilibrar(recorrer->izq);
        necesidadEquilibrar(recorrer->dere);

        if ((recorrer->fe==2)||(recorrer->fe==-2)){
            /** Es necesario equilibrar el arbol */

            PadreAB=recorrer;
            sHijo=PadreAB->dere;

            /** Identificar si usar Rotacion Derecha Derecha. */
            if ((PadreAB->fe>1)&&(sHijo->fe>0)){
                rotarDD();
                altura(raiz);
                return;
            /** Identificar si usar Rotaciin Derecha Izquierda. */
            }else if((PadreAB->fe>1)&&(sHijo->fe<0)){
                rotarDI();
                altura(raiz);
                return;
            }else{
                PadreAB=recorrer;
                sHijo=PadreAB->izq;

            /** Identificar Si es el caso  RII, Rotacion Izquierda, Izquierda. */
                if((PadreAB->fe<-1)&&(sHijo->fe<0)){
                    rotarII();
                    altura(raiz);
                    return;

            /** Identificar Si es el caso  RID, Rotaci�n Izquierda, Derecha. */
                }else if((PadreAB->fe<-1)&&(sHijo->fe>0)){
                    rotarID();
                    altura(raiz);
                    return;
                }
            }
            return;
        }
    }
}

void ArbolAVL_01::vaciarArbol(NodoArbolAVL__01 *recorrer){
    if (recorrer != NULL) {
        postorden(recorrer->izq);
        postorden(recorrer->dere);

        if (recorrer->codigo == raiz->codigo){
            raiz=NULL;
        }else{
            delete(recorrer);   /** Liberamos la memoria. */
        }
    }
}


void ArbolAVL_01::rotarII(){
/** Rotacion  Izquierda Izquierda. */
    if(PadreAB==raiz){
        raiz=sHijo;
        hijoHijo=sHijo->izq;
        sHijo->dere=PadreAB;
        PadreAB->izq=NULL;
        PadreAB->padre=sHijo;
        sHijo->padre=NULL;
        //PadreAB->dere=hijoHijo;
        //hijoHijo->padre=PadreAB;
        //sHijo->dere=PadreAB;
    }else{
        abuelo=PadreAB->padre;
        abuelo->izq=PadreAB->izq;
        sHijo->padre=abuelo;
        sHijo->dere=PadreAB;
        PadreAB->padre=sHijo;
        PadreAB->izq=NULL;
    }
}

void ArbolAVL_01::rotarDD(){
/** Rotacion  Derecha Derecha */
    if (PadreAB==raiz){
        raiz=sHijo;
        //sHijo->dere=hijoHijo;
        //hijoHijo->padre=sHijo;
        //hijoHijo->dere=NULL;
        sHijo->izq=PadreAB;
        PadreAB->padre=sHijo;
        PadreAB->dere=NULL;
        sHijo->padre=NULL;
    }else{
        abuelo=PadreAB->padre;
        abuelo->dere=PadreAB->dere;
        sHijo->padre=abuelo;
        sHijo->izq=PadreAB;
        PadreAB->padre=sHijo;
        PadreAB->dere=NULL;
    }
}

void ArbolAVL_01::rotarID(){
/**Rotacion  Izquierda Derecha */
    if (PadreAB==raiz){
        hijoHijo=sHijo->dere;                   /** Ubico al hijo del hijo. */
        raiz=hijoHijo;                          /** Cambiar el apuntador de la raiz. */
        hijoHijo->padre=NULL;                   /** Aseguro que el padre de la raiz se quede en null. */
        hijoHijo->izq=sHijo;                    /** El nuevo padre debe apuntar al hijo izquierdo. */
        sHijo->padre=hijoHijo;                  /** El hijo debe apuntar a su nuevo padre. */
        sHijo->dere=NULL;                       /** Apuntar a null la parte izquierda del hijo, ya que ahora no tendra hijos. */
        PadreAB->izq=NULL;                      /** El antiguo padre debe apuntar ahora a null. */
        hijoHijo->dere=PadreAB;                 /** El nuevo padre debe apuntar al hijo derecho. */
        if(PadreAB->dere==NULL){
            PadreAB->dere=NULL;                 /** El antiguo padre debe apuntar ahora a null. */
        }
        PadreAB->padre=hijoHijo;                /** Apuntar al nuevo padre. */
    }else{
        abuelo=PadreAB->padre;
        hijoHijo=sHijo->dere;                   /** Ubico al hijo del hijo. */
        hijoHijo->padre=abuelo;                 /** Aseguro que el padre de la raiz se quede apuntando al abuelo. */
        abuelo->izq=hijoHijo;
        hijoHijo->izq=sHijo;                    /** El nuevo padre debe apuntar al hijo izquierdo. */
        sHijo->padre=hijoHijo;                  /** El hijo debe apuntar a su nuevo padre. */
        sHijo->dere=NULL;                       /** Apuntar a null la parte izquierda del hijo, ya que ahora no tendri hijos. */
        hijoHijo->dere=PadreAB;                 /** El nuevo padre debe apuntar al hijo derecho. */
        PadreAB->izq=NULL;                      /** El antiguo padre debe apuntar ahora a null. */
        if(PadreAB->dere==NULL){
            PadreAB->dere=NULL;                 /** El antiguo padre debe apuntar ahora a null. */
        }
        PadreAB->padre=hijoHijo;                /** Apuntar al nuevo padre. */
    }
}


void ArbolAVL_01::rotarDI(){
/** Rotacion Derecha Izquierda */
    if (PadreAB==raiz){
        hijoHijo=sHijo->izq;                    /** Ubico al hijo del hijo. */
        raiz=hijoHijo;                          /** Cambiar el apuntador de la raiz. */
        hijoHijo->padre=NULL;                   /** Aseguro que el padre de la raiz se quede en null. */
        hijoHijo->dere=sHijo;                   /** El nuevo padre debe apuntar al hijo izquierdo. */
        sHijo->padre=hijoHijo;                  /** El hijo debe apuntar a su nuevo padre. */
        if(sHijo->izq!=NULL){
            sHijo->izq=hijoHijo->izq;
        }else{
            sHijo->izq=NULL;                    /** Apuntar a Null la parte izquierda del hijo, ya que ahora no tendra hijos. */
        }
        hijoHijo->izq=PadreAB;                  /** El nuevo padre debe apuntar al hijo derecho. */
        if(PadreAB->izq==NULL){
            PadreAB->izq=NULL;                  /** El antiguo padre debe apuntar ahora a null. */
        }
        PadreAB->dere=NULL;                     /** El antiguo padre debe apuntar ahora a null. */
        PadreAB->padre=hijoHijo;                /** Apuntar al nuevo padre. */
    }else{
        abuelo=PadreAB->padre;
        hijoHijo=sHijo->izq;                    /** Ubico al hijo del hijo. */
        hijoHijo->padre=abuelo;                 /** Aseguro que el padre de la raiz se quede apuntando al abuelo. */
        hijoHijo->dere=sHijo;                   /** El nuevo padre debe apuntar al hijo izquierdo. */
        sHijo->padre=hijoHijo;                  /** El hijo debe apuntar a su nuevo padre. */
        if(sHijo->izq!=NULL){
            sHijo->izq=hijoHijo->izq;
        }else{
            sHijo->izq=NULL;                    /** Apuntar a Null la parte izquierda del hijo, ya que ahora no tendra hijos. */
        }
        hijoHijo->izq=PadreAB;                  /** El nuevo padre debe apuntar al hijo derecho. */
        if(PadreAB->izq==NULL){
            PadreAB->izq=NULL;                  /** El antiguo padre debe apuntar ahora a null. */
        }
        PadreAB->dere=NULL;                     /** El antiguo padre debe apuntar ahora a null. */
        PadreAB->padre=hijoHijo;                /** Apuntar al nuevo padre. */
        abuelo->dere=hijoHijo;
    }
}

