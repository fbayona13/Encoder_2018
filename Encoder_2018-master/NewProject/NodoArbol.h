#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class T>
class NodoArbol {
private:
    T dato;
    NodoArbol *izq;
    NodoArbol *der;
public:
    NodoArbol() {
        izq = nullptr;
        der = nullptr;
    }

    NodoArbol(T d) {
        izq = nullptr;
        der = nullptr;
        dato = d;
    }

    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        NodoArbol::dato = dato;
    }

    NodoArbol *getIzq() const {
        return izq;
    }

    void setIzq(NodoArbol *izq) {
        NodoArbol::izq = izq;
    }

    NodoArbol *getDer() const {
        return der;
    }

    void setDer(NodoArbol *der) {
        NodoArbol::der = der;
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