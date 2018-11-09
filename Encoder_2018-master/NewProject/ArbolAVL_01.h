//
// Created by juanp on 9/11/2018.
//

#ifndef ENCODER_2018_MASTER_ARBOLAVL_01_H
#define ENCODER_2018_MASTER_ARBOLAVL_01_H

#include "NodoArbolAVL__01.h"
#include "codifica.h"

/**     Clase donde se le dara forma al arbol TIPO autobalanceable (AVL), se creara e incluira una hoja NodoArbolAVL.H donde se instanciara el nodo correspondiente al arbol
 *
 * @tparam T
 */

template <class T>

class ArbolAVL_01 : public NodoArbolAVL__01 {


public:

    void preorden( NodoArbolAVL__01 *recorrer);
    void inorden( NodoArbolAVL__01 *recorrer);
    void postorden( NodoArbolAVL__01 *recorrer);
    void insertarNuevo( NodoArbolAVL__01 *recorrer,  NodoArbolAVL__01 *nuevo,  NodoArbolAVL__01 *padre);
    void agregarDatos(int , char);
    int  exiteenArbol( NodoArbolAVL__01 *recorrer, int buscado);
    int  altura(NodoArbolAVL__01 *recorrer);
    void necesidadEquilibrar( NodoArbolAVL__01 *recorrer);
    void vaciarArbol( NodoArbolAVL__01 *recorrer);

    /** Funciones que reestructuran el arbol */

    void rotarII();
    void rotarDD();
    void rotarID();
    void rotarDI();


};



#endif //ENCODER_2018_MASTER_ARBOLAVL_01_H
