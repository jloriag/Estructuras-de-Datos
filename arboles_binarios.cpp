#include <iostream>
using namespace std;

// Clase Nodo
class Nodo {
public:
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Clase del Árbol Binario de Búsqueda
class ArbolBinario {
private:
    Nodo* raiz;

    Nodo* insertarRecursivo(Nodo* nodo, int val) {
        if (nodo == nullptr)
            return new Nodo(val);

        if (val < nodo->valor)
            nodo->izquierdo = insertarRecursivo(nodo->izquierdo, val);
        else if (val > nodo->valor)
            nodo->derecho = insertarRecursivo(nodo->derecho, val);
        // Si es igual, no se inserta (evita duplicados)
        return nodo;
    }

    bool buscarRecursivo(Nodo* nodo, int val) {
        if (nodo == nullptr)
            return false;

        if (val == nodo->valor)
            return true;
        else if (val < nodo->valor)
            return buscarRecursivo(nodo->izquierdo, val);
        else
            return buscarRecursivo(nodo->derecho, val);
    }

    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            cout << nodo->valor << " ";
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            cout << nodo->valor << " ";
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            cout << nodo->valor << " ";
        }
    }

    Nodo* encontrarMinimo(Nodo* nodo) {
        while (nodo->izquierdo != nullptr)
            nodo = nodo->izquierdo;
        return nodo;
    }

    Nodo* eliminarRecursivo(Nodo* nodo, int val) {
        if (nodo == nullptr)
            return nullptr;

        if (val < nodo->valor) {
            nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, val);
        } else if (val > nodo->valor) {
            nodo->derecho = eliminarRecursivo(nodo->derecho, val);
        } else {
            // Nodo con un solo hijo o sin hijos
            if (nodo->izquierdo == nullptr) {
                Nodo* temp = nodo->derecho;
                delete nodo;
                return temp;
            } else if (nodo->derecho == nullptr) {
                Nodo* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }

            // Nodo con dos hijos
            Nodo* sucesor = encontrarMinimo(nodo->derecho);
            nodo->valor = sucesor->valor;
            nodo->derecho = eliminarRecursivo(nodo->derecho, sucesor->valor);
        }

        return nodo;
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(int val) {
        raiz = insertarRecursivo(raiz, val);
    }

    bool buscar(int val) {
        return buscarRecursivo(raiz, val);
    }

    void eliminar(int val) {
        raiz = eliminarRecursivo(raiz, val);
    }

    void mostrarInorden() {
        cout << "Inorden: ";
        inorden(raiz);
        cout << endl;
    }

    void mostrarPreorden() {
        cout << "Preorden: ";
        preorden(raiz);
        cout << endl;
    }

    void mostrarPostorden() {
        cout << "Postorden: ";
        postorden(raiz);
        cout << endl;
    }
};

// Función principal
int main() {
    ArbolBinario arbol;

    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(18);

    cout << "Recorridos del árbol:" << endl;
    arbol.mostrarInorden();
    arbol.mostrarPreorden();
    arbol.mostrarPostorden();

    int valorBuscar = 7;
    cout << "¿El valor " << valorBuscar << " está en el árbol? "
         << (arbol.buscar(valorBuscar) ? "Sí" : "No") << endl;

    cout << "\nEliminando 10 (raíz con dos hijos)..." << endl;
    arbol.eliminar(10);
    arbol.mostrarInorden();

    return 0;
}
