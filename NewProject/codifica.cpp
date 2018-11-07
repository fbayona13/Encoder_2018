//
// Created by Usuario on 06/11/2018.
//
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "codifica.h"



void codifica::Lectura(int i) {

    int G, H;
    String D;
    String Diccionario;
    String Mensaje;
    String opcion;

    if(i == 1){
        opcion = "diccionario";
    }
    else {
        opcion = "mensaje";
    }

    ifstream  dic;
    cout << "Por favor ingrese la direccion junto con el nombre del archivo de texto que contenga el "<< opcion << endl;

    cin >> D;
    dic.open(D , ios::in); //Abrir Archivo

    if(dic.fail()){
        Error(1);
    };
    cout << "Ya hemos encontrado su " << opcion << "\n ¿Que accion desea realizar? \n 1.- Verlo \n 2.- Cargarlo  \n 3.- Volver a opciones" << endl;
    while (H < 1 || H > 3) {    //Ingresar la opcion correcta
        cin >> H;
        if ( H!=3 && H != 2 && H != 1 ){
            cout << "Opcion incorrecta, por favor vuelva a intentar " << endl;
            cout << " 1.- Verlo \n 2.-Cargarlo \n 3.- Volver a opciones" << endl;
        }}
    if(H == 1){
        while (!dic.eof()){ //mientras no sea el final del archivo
            getline(dic , Diccionario);
            cout << Diccionario << endl;
        }
        cout << "¿Que desea hacer ahora? \n  1.- Cargar el diccionario al codificador \n  2.- Volver al menu " <<endl;
        while (G < 1 || G > 2) {    //Ingresar la opcion correcta
            cin >> G;
            if (G != 2 && G != 1){
                cout << "Opcion incorrecta, por favor vuelva a intentar " << endl;
                cout << "¿Desea volver al menu? \n  1.- Si \n  2.- No " <<endl;
            }}
        if (G == 2)
            Opciones();
        if (G == 1)
            Obtencion(D);
    }

    if (H == 2)
        Obtencion(D);

    if (H == 3)
        Opciones();

};

void codifica::Opciones() {
    string DireccionDic;
    string DireccionMen;
    int B;
    cout << "Ingrese la opcion que desea: \n 1.- Ingresar Diccionario \n 2.- Ingresar Mensaje \n 3.- Salir del programa"
         << endl;
    cin >> B;
    if(B < 1 || B > 3){
        cout << "La opcion ingresada es incorrecta, por favor seleccione una opcion del menu" << endl;
        Opciones();
    }
    if (B == 1 || B == 2) {
        Lectura(B);
    }
    if (B == 3){
        exit(1);
    }
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
        if (G == 1)
            Opciones();
        if (G == 2)
            exit(1);
    };
};

void codifica::Obtencion(const string &H){
    char Texto1[15];
    char Texto2[15];
    ifstream  dic;
    cout << "Cargando el diccionario al codificador, por favor espere ..."<<endl;
    dic.open( H , ios::in);
    if (dic.is_open()){
        while ( !dic.eof() ){
            dic >> Texto1 >> Texto2;
            cout<< "obtencion funcionando"<<endl;
            if ( !dic.eof() ){
                cout<< "obtencion funcionando 1"<<endl;
                //Numeracion( Texto1 , Texto2 );
            }
        }
    }
    else{
        Error(2);
    }
}

/*int codifica:: Numeracion(char *A , char *B){
    int Codigo_1 , Codigo_2;
    while(A != /0);
}
*/

