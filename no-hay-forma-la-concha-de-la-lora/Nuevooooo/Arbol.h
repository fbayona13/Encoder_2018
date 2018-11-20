//
// Created by juanp on 17/11/2018.
//

#ifndef NUEVOOOOO_ARBOL_H
#define NUEVOOOOO_ARBOL_H

#include <iostream>
#include "Nodo.h"
#include <string>

using namespace std;


class ArbolAVL {

public:
    Nodo *Raiz;

    ArbolAVL() {
        Raiz = nullptr;
    }

    Nodo *get_raiz() {
        return Raiz;
    }

    string buscar(string x, Nodo *raiz) { // Buscar Dato

        if (raiz == nullptr) {
            return "";
        }
        if (raiz->valor == x) {
            return raiz->Cod;

        }

        if (raiz->valor < x) {
            buscar(x, raiz->hijoder);
        } else {
            buscar(x, raiz->hijoizq);
        }

    }

    int obtenerfe(Nodo *x) {// Obtener factor equilibrio

        if (x == nullptr) {

            return -1;
        } else {
            return x->fe;
        }
    }

    Nodo *rotacionizquierda(Nodo *c) { //Rotacion simple a la izqierda

        Nodo *aux = c->hijoizq;
        c->hijoizq = aux->hijoder;
        aux->hijoder = c;
        int maximovalorc;
        int maximovaloraux;

        if (obtenerfe(c->hijoizq) > obtenerfe(c->hijoder)) {
            maximovalorc = obtenerfe(c->hijoizq) + 1;

        } else {
            maximovalorc = obtenerfe(c->hijoder) + 1;
        }

        c->fe = maximovalorc;


        if (obtenerfe(aux->hijoizq) > obtenerfe(aux->hijoder)) {
            maximovaloraux = obtenerfe(aux->hijoizq) + 1;

        } else {
            maximovaloraux = obtenerfe(aux->hijoder) + 1;
        }

        aux->fe = maximovaloraux;

        return aux;

    }

    Nodo *rotacionderecha(Nodo *c) { //Rotacion simple a la derecha

        Nodo *aux = c->hijoder;
        c->hijoder = aux->hijoizq;
        aux->hijoizq = c;
        int maximovalorc;
        int maximovaloraux;

        if (obtenerfe(c->hijoizq) > obtenerfe(c->hijoder)) {
            maximovalorc = obtenerfe(c->hijoizq);

        } else {
            maximovalorc = obtenerfe(c->hijoder);
        }

        c->fe = maximovalorc + 1;


        if (obtenerfe(aux->hijoizq) > obtenerfe(aux->hijoder)) {
            maximovaloraux = obtenerfe(aux->hijoizq);

        } else {
            maximovaloraux = obtenerfe(aux->hijoder);
        }

        aux->fe = maximovaloraux + 1;

        return aux;
    }


    Nodo *rotaciondobleizq(Nodo *c) {

        Nodo *temp;
        c->hijoizq = rotacionderecha(c->hijoizq);
        temp = rotacionizquierda(c);
        return temp;
    }


    Nodo *rotaciondobleder(Nodo *c) {
        Nodo *temp;
        c->hijoder = rotacionizquierda(c->hijoder);
        temp = rotacionderecha(c);
        return temp;
    }


    Nodo *insertaravl(Nodo *nuevo, Nodo *subarbol) {

        Nodo *nuevoPadre = subarbol;

        if (nuevo->valor < subarbol->valor) {
            if (subarbol->hijoizq == nullptr) {
                subarbol->hijoizq = nuevo;
            } else {
                subarbol->hijoizq = insertaravl(nuevo, subarbol->hijoizq);
                if ((obtenerfe(subarbol->hijoizq) - obtenerfe(subarbol->hijoder) == 2)) {
                    if (nuevo->valor < subarbol->hijoizq->valor) {
                        nuevoPadre = rotacionizquierda(subarbol);
                    } else {
                        nuevoPadre = rotaciondobleizq(subarbol);

                    }

                }
            }
        } else if (nuevo->valor > subarbol->valor) {
            if (subarbol->hijoder == nullptr) {
                subarbol->hijoder = nuevo;
            } else {
                subarbol->hijoder = insertaravl(nuevo, subarbol->hijoder);
                if ((obtenerfe(subarbol->hijoder) - obtenerfe(subarbol->hijoizq) == 2)) {

                    if (nuevo->valor > subarbol->hijoder->valor) {
                        nuevoPadre = rotacionderecha(subarbol);

                    } else {

                        nuevoPadre = rotaciondobleder(subarbol);
                    }

                }

            }


        } else {
            cout << "Nodo Duplicado" << endl;
        }

        if ((subarbol->hijoizq == nullptr) && (subarbol->hijoder != nullptr)) {

            subarbol->fe = subarbol->hijoder->fe + 1;
        } else {

            if ((subarbol->hijoder == nullptr) && (subarbol->hijoizq != nullptr)) {

                subarbol->fe = subarbol->hijoizq->fe + 1;


            } else {
                int maximovalor;

                if (obtenerfe(subarbol->hijoizq) > obtenerfe(subarbol->hijoder)) {
                    maximovalor = obtenerfe(subarbol->hijoizq);

                } else {
                    maximovalor = obtenerfe(subarbol->hijoder);
                }
                subarbol->fe = maximovalor + 1;

            }

        }

        return nuevoPadre;
    }

    void insertar(string d, string f) {
        Nodo *nuevo = new Nodo(d, f);
        if (Raiz == nullptr) {
            Raiz = nuevo;

        } else {

            Raiz = insertaravl(nuevo, Raiz);
        }

    }

};


#endif //NUEVOOOOO_ARBOL_H
