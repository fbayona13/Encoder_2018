//
// Created by Usuario on 06/11/2018.
//
#ifndef NEWPROJECT_CODIFICA_H
#define NEWPROJECT_CODIFICA_H


class codifica {

private:

    std::string Direccion;
    std::ifstream Dic;
    char Texto_1[15] , Texto_2[15];
    int Long_1 , Long_2;
    int Condicion;


public:

    int Codifica();
    void Opciones();
    void Error(int);
    void Lectura(int);
    void Obtencion();
    void SetDireccion();
    void SetDic();
    void Numeracion ();
    void SetCondicion();

};


#endif //NEWPROJECT_CODIFICA_H
