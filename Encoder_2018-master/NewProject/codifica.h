//
// Created by Usuario on 06/11/2018.
//
#ifndef NEWPROJECT_CODIFICA_H
#define NEWPROJECT_CODIFICA_H
#include "NodoArbolAVL__01.h"
#include "ArbolAVL_01.h"



class codifica : ArbolAVL_01 {

private:

    std::string Direccion;
    std::ifstream Dic;
    std::ifstream Men;
    int CondicionDic , CondicionMen;

protected:

    char Texto_1[20] , Texto_2[20] , Texto_3_Men[20];
    int Long_1 , Long_2 , Long_3_Men;


public:

    int codifica();
    void Opciones();
    void Error(int);
    void LecturaDic();
    void LecturaMen();
    void ObtencionDic();
    void ObtencionMen();
    void SetDireccion();
    void SetFile(int);
    void Numeracion_Dic ();
    void Numeracion_Men();
};


#endif //NEWPROJECT_CODIFICA_H
