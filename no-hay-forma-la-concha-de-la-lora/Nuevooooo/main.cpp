#include <iostream>
#include "FileManager.h"

int main(int argc , char *argv[]) {
    string DName, MName , OName;
    FileManager F;
    int A;
    /**
            for (int i = 1; i < argc; ++i) {
            if (argv[i] == "-c"){ A = 1; }
            if (argv[i] == "-d"){ A = 2; }
            if (argv[i] == "-l"){ DName = argv[i+1]; }
            if (argv[i] == "-i"){ MName = argv[i+1]; }
            if (argv[i] == "-o"){ OName = argv[i+1]; }
        }*/

    cout<<"Ingrese 1 si codifica y 2 si decodifica"<<endl;
    cin>>A;
    /**cout<<"ingrese el nombre del diccionario"<<endl;
    cin>>DName;
    cout<<"Ingrese el nombre del mensaje de entrada"<<endl;
    cin>>MName;
    */
    cout<<"ingrese el nombre del archivo de salida"<<endl;
    cin>>OName;

    F.SetCond(A);
    F.SetOut_Name(OName);
    F.SetFile(1);
    F.SetFile(2);
    //F.SetDic_Name(DName);
    //F.SetMen_Name(MName);
    return 0;
}