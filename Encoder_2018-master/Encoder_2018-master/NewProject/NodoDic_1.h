#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class T>
class NodoDic_1 {
private:
    T Codigo;
    T Traduccion;
    NodoDic_1 *izq;
    NodoDic_1 *der;
public:
    NodoDic_1() {
        izq = nullptr;
        der = nullptr;
    }



    NodoDic_1(T d) {
        izq = nullptr;
        der = nullptr;
        Codigo = d;
    }

    T getCodigo() const {
        return Codigo;
    }

    void setCodigo(T Codigo) {
        NodoDic_1::Codigo = Codigo;
    }

    void setTraduccion( T Traduccion){
        NodoDic_1::Traduccion = Traduccion;
    }

    NodoDic_1 getTraduccion (){
        return  Traduccion;
    }

    NodoDic_1 *getIzq() const {
        return izq;
    }

    void setIzq(NodoDic_1 *izq) {
        NodoDic_1::izq = izq;
    }

    NodoDic_1 *getDer() const {
        return der;
    }

    void setDer(NodoDic_1 *der) {
        NodoDic_1::der = der;
    }


// void actualizar(T dato){}

//    void print(bool esDerecho, string identacion) {
//        if (der != NULL) {
//            der->print(true, identacion + (esDerecho ? "     " : "|    "));
//        }
//        cout << identacion;
//        if (esDerecho) {
//            cout << " /";
//        } else {
//            cout << " \\";
//        }
//        cout << "-- ";
//        cout << dato << endl;
//        if (izq != NULL) {
//            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
//        }
//    }
};

#endif //HASHENTRY_H