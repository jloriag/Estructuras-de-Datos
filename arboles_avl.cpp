#include <iostream>
using namespace std;

struct NodoAVL {
    int valor;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    NodoAVL(int val): valor(val),izquierdo(nullptr),derecho(nullptr),altura(1) {}
};

class ArbolAVL {
private: 
    NodoAVL* raiz;
       
    int altura(NodoAVL* nodo){
        return nodo?nodo->altura:0;
    }

    int obtenerBalance(NodoAVL* nodo){
        return nodo?altura(nodo->izquierdo) - altura(nodo->derecho):0;
    }

    int mayor (int a, int b){
        return (a>b)?a:b;
    }

    NodoAVL* rotarDerecha(NodoAVL* y) {
        NodoAVL* x = y->izquierdo;
        NodoAVL* T2 = x->derecho;

        x->derecho = y;
        y->izquierdo = T2;

        y->altura = 1 + mayor(altura(y->izquierdo), altura(y->derecho));
        x->altura = 1 + mayor(altura(x->izquierdo), altura(x->derecho));

        return x;
    }

    NodoAVL* rotarIzquierda(NodoAVL* x) {
        NodoAVL* y = x->derecho;
        NodoAVL* T2 = y->izquierdo;

        y->izquierdo = x;
        x->derecho = T2;

        x->altura = 1 + mayor(altura(x->izquierdo), altura(x->derecho));
        y->altura = 1 + mayor(altura(y->izquierdo), altura(y->derecho));

        return y;
    }

    NodoAVL* insertarRec(NodoAVL* nodo, int valor) {
        if (!nodo)
            return new NodoAVL(valor);

        if (valor < nodo->valor)
            nodo->izquierdo = insertarRec(nodo->izquierdo, valor);
        else if (valor > nodo->valor)
            nodo->derecho = insertarRec(nodo->derecho, valor);
        else
            return nodo; // No se permiten duplicados

        nodo->altura = 1 + mayor(altura(nodo->izquierdo), altura(nodo->derecho));
        int balance = obtenerBalance(nodo);

        if (balance > 1 && valor < nodo->izquierdo->valor)
            return rotarDerecha(nodo);

        if (balance < -1 && valor > nodo->derecho->valor)
            return rotarIzquierda(nodo);

        if (balance > 1 && valor > nodo->izquierdo->valor) {
            nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
            return rotarDerecha(nodo);
        }

        if (balance < -1 && valor < nodo->derecho->valor) {
            nodo->derecho = rotarDerecha(nodo->derecho);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    void inordenRec(NodoAVL* nodo) {
        if (nodo) {
            inordenRec(nodo->izquierdo);
            cout << nodo->valor << " ";
            inordenRec(nodo->derecho);
        }
    }
public:
    ArbolAVL() : raiz(nullptr) {}

    void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }

    void inorden() {
        inordenRec(raiz);
        cout << endl;
    }

};

int main() {
    ArbolAVL arbol;
    int valores[] = {10, 20, 30, 40, 50, 25};

    for (int v : valores)
        arbol.insertar(v);

    cout << "Recorrido Inorden: ";
    arbol.inorden();

    return 0;
}