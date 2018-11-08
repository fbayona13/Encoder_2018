//
// Created by Usuario on 06/11/2018.
//
#ifndef NEWPROJECT_CODIFICA_H
#define NEWPROJECT_CODIFICA_H
#include "NodoDic_1.h"



class codifica {

private:

    std::string Direccion;
    std::ifstream Dic;
    std::ifstream Men;
    int CondicionDic , CondicionMen;

protected:

    char Texto_1[20] , Texto_2[20];
    int Long_1 , Long_2;


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
    void Numeracion ();
};


#endif //NEWPROJECT_CODIFICA_H
