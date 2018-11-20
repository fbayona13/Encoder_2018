//
// Created by juanp on 17/11/2018.
//

#ifndef NUEVOOOOO_NODO_H
#define NUEVOOOOO_NODO_H

#include <iostream>
using namespace std;


class Nodo {
public:
    int fe;
    string valor, Cod;
    Nodo *hijoizq, *hijoder;

    Nodo(string x , string z){
        valor=x;
        Cod= z;
        fe=0;
        hijoizq=NULL;
        hijoder=NULL;
    }
};


#endif //NUEVOOOOO_NODO_H
