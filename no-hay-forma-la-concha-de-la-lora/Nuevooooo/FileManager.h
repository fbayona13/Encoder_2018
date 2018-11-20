//
// Created by juanp on 17/11/2018.
//

#ifndef NUEVOOOOO_FILEMANAGER_H
#define NUEVOOOOO_FILEMANAGER_H


#include <iostream>
#include <string>
#include <fstream>
#include "Arbol.h"
#include "Nodo.h"
using namespace std;


class FileManager {

    ArbolAVL l;

protected:
    string Dic_Name;
    string Men_Name;
    string Out_Name;
    string Men_Line;
    string Col_01, Col_02;
    string Palabra, codifica;
    ifstream Dic;
    ifstream Men;
    ofstream Salida;
    int Condition;


public:

    FileManager(){
    }
    void SetOut_Name(string o) {
        Out_Name = o;
        OutPut_Generator();
    }

    void SetDic_Name(string d) {
        Dic_Name = d;
        SetFile(1);
    }

    void SetMen_Name(string m) {
        Men_Name = m;
        SetFile(2);
    }

    void SetCond(int C) {
        Condition = C;
    }

    void SetFile(int C) {                            /** Abrir Archivo. */
        /** Diccionario. */
        if(C == 1) {
            Dic.open("D:\\Users\\Usuario\\Desktop\\diccionario1-1.txt", ios::in);
            if (Dic.fail()) { Error(1); }
            Get_Dic();
        }
        /** Mensaje. */
        if(C == 2) {
            Men.open("D:\\Users\\Usuario\\Desktop\\entradaEJ.txt", ios::in);
            if (Men.fail()) { Error(2); }
            Get_Men();
            }
    };

    void Get_Dic() {                            /** Obtencion por columnas del Diccionario. */
        while (!Dic.eof()) {
            Dic >> Col_01 >> Col_02;
            if (Condition == 1) { l.insertar(Col_01, Col_02); }
            if (Condition == 2) { l.insertar(Col_02, Col_01); }
        }
    };

    void Get_Men() {                                 /** Obtencion por linea del mensaje. */
        while (!Men.eof()) {
            getline(Men, Men_Line);
            Codifica();
        }
    };

    void OutPut_Generator() {
        Salida.open(Out_Name, ios::out);
        if (Salida.fail()) { Error(3); }

    };

    void Codifica() {
        for (int i = 0; i < Men_Line.length()+1; ++i) {
            if ((Men_Line[i] >= 65 && Men_Line[i] <= 90) || (Men_Line[i] >= 97 && Men_Line[i] <= 0122) ||
                (Men_Line[i] >= 128 && Men_Line[i] <= 165)) {
                Palabra = Palabra + Men_Line[i];
            } else {
                if (Palabra != " ") {
                    codifica = l.buscar( Palabra ,l.Raiz );
                    Salida << codifica << Men_Line[i];
                    Palabra = " ";
                } else {
                    Salida << Men_Line[i];
                }

            }
        }
        codifica = l.buscar(Palabra , l.Raiz);

        Salida << codifica << endl;

    };

    void Error(int B) {
        if (B == 1){cout<<"Error Diccionario"<<endl;};
        if (B == 2){cout<<"Error Mensaje"<<endl;}
        if (B == 3){cout<<"Error Salida"<<endl;}
    };


};



#endif //NUEVOOOOO_FILEMANAGER_H
