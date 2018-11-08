//
// Created by Usuario on 06/11/2018.
//
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "codifica.h"
#include <sstream>

using namespace std;

void codifica::SetDireccion() {
    cin >> Direccion;
}

void codifica::SetDic() {
    cout << "Por favor ingrese la direccion junto con el nombre del archivo de texto que contenga el diccionario " << endl;

    SetDireccion();
    Dic.open(Direccion, ios::in); //Abrir Archivo

    if (Dic.fail()) {
        Error(1);
    };
}

void codifica::Lectura(int i) {
    int G, H;
    string opcion , Mostrar;
    if(1 == i){ opcion = "diccionario"; }
    else { opcion = "mensaje"; }
    SetDic();
    cout << "Ya hemos encontrado su " << opcion << "\n ¿Que accion desea realizar? \n 1.- Verlo \n 2.- Cargarlo  \n 3.- Volver a opciones" << endl;
        while (H < 1 || H > 3) {    //Ingresar la opcion correcta
            cin >> H;
            if ( H!=3 && H != 2 && H != 1 ){
                cout << "Opcion incorrecta, por favor vuelva a intentar " << endl;
                cout << " 1.- Verlo \n 2.-Cargarlo \n 3.- Volver a opciones" << endl;
            }}
        if(H == 1){
            while (!Dic.eof()){                 //mientras no sea el final del archivo
                getline(Dic , Mostrar);
                cout << Mostrar << endl;
        }
        cout << "¿Que desea hacer ahora? \n  1.- Cargar el diccionario al codificador \n  2.- Volver al menu " <<endl;
            while (G < 1 || G > 2) {    //Ingresar la opcion correcta
                cin >> G;
                    if (G != 2 && G != 1){
                        cout << "Opcion incorrecta, por favor vuelva a intentar " << endl;
                        cout << "¿Desea volver al menu? \n  1.- Si \n  2.- No " <<endl;
                    }
            }
        if (G == 2)     Opciones();
        if (G == 1)     Obtencion();
    }

        if (H == 2)     Obtencion();

        if (H == 3)     Opciones();
};

void codifica::Opciones() {
    int B;
    cout << "Ingrese la opcion que desea: \n 1.- Ingresar Diccionario \n 2.- Ingresar Mensaje \n 3.- Salir del programa"<< endl;
    cin >> B;
        if(B < 1 || B > 3){
            cout << "La opcion ingresada es incorrecta, por favor seleccione una opcion del menu" << endl;
            Opciones();
        }
        if (B == 1 || B == 2) { Lectura(B) ; }
        if (B == 3){ exit(1) ; }
}

void codifica::Error(int K) {
    int G;
    if (K == 1 || K == 2){
        cout << "Disculpe, hubo un error al momento de cargar el archivo. Por favor vuelva a intentar desde otra ubicacion\n  1.- No existe la ruta o nombre especificado \n  2.- No tiene permiso para abrir el archivo " << endl;
        cout << "Codigo del error: "<< K<<endl;
        cout << "¿Desea volver al menu principal? \n  1.- Volver \n  2.- Salir del programa" << endl;
        while (G < 1 || G > 2) {    //Ingresar la opcion correcta
            cin >> G;
            if (G != 2 && G != 1){
                cout << "Opcion incorrecta, por favor vuelva a intentar " << endl;
                cout << " 1.- Volver \n 2.- Salir del programa" << endl;
            }}
            if (G == 1) Opciones();
            if (G == 2) exit(1);
    };
};

void codifica::Obtencion() {            //Obtiene las palabras del Dic por columna
    cout << "Cargando el diccionario al codificador, por favor espere ..." << endl;
        while (!Dic.eof()) {
            Dic >> Texto_1 >> Texto_2;
            Long_1 = strlen(Texto_1);
            Long_2 = strlen(Texto_2);
            Numeracion();
        }
    cout << "Gracias por esperar, ya hemos cargado el diccionario al programa" << endl;
    cout << "Presione ENTER para voler a opcciones " << endl;
    system("pause");
    Opciones();
};

void codifica::Numeracion() {               //Genera un numero a partir de los caracteres de la palabra
    string Codigo_1, Codigo_2;
    int Codigo_1_int , Codigo_2_int;
    int Cod;
    string Cod_String;
    cout << Texto_1 << endl;
        for (int i = 0 ; i < Long_1 ; i++){
            Cod = Texto_1[i];
            Cod_String = to_string(Cod);
            Codigo_1 = Codigo_1 + Cod_String;
            Codigo_1_int = atoi(Codigo_1.c_str());
        };
            if (Codigo_1_int < 0){
                Codigo_1_int = Codigo_1_int * (-1);
            }
    cout << Codigo_1_int << "   Codigo int 1" << endl;
    cout << Texto_2 << endl;
         for (int i = 0 ; i < Long_2 ; i++){
            Cod = Texto_2[i];
            Cod_String = to_string(Cod);
            Codigo_2 = Codigo_2 + Cod_String;
            Codigo_2_int = atoi(Codigo_2.c_str());
         };
            if (Codigo_2_int < 0){
                Codigo_2_int = Codigo_2_int * (-1);
            }
    cout << Codigo_2_int << "   Codigo int 2"<<endl;

}






