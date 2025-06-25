#include <iostream>
using namespace std;

#define MAX_VERTICES 10

class Grafo {
private:
    int matriz[MAX_VERTICES][MAX_VERTICES];
    char vertices[MAX_VERTICES];
    int cantidad;

public:
    Grafo() {
        cantidad = 0;
        for (int i = 0; i < MAX_VERTICES; ++i)
            for (int j = 0; j < MAX_VERTICES; ++j)
                matriz[i][j] = 0;
    }

    void agregarVertice(char nombre) {
        if (cantidad < MAX_VERTICES) {
            vertices[cantidad++] = nombre;
        }
    }

    int indiceVertice(char nombre) {
        for (int i = 0; i < cantidad; ++i) {
            if (vertices[i] == nombre)
                return i;
        }
        return -1;
    }

    void agregarArista(char origen, char destino) {
        int i = indiceVertice(origen);
        int j = indiceVertice(destino);
        if (i != -1 && j != -1) {
            matriz[i][j] = 1;
            matriz[j][i] = 1; // Grafo no dirigido
        }
    }

    void mostrarGrafo() {
        cout << "Matriz de adyacencia:\n  ";
        for (int i = 0; i < cantidad; ++i)
            cout << vertices[i] << " ";
        cout << endl;

        for (int i = 0; i < cantidad; ++i) {
            cout << vertices[i] << " ";
            for (int j = 0; j < cantidad; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Grafo g;
    g.agregarVertice('A');
    g.agregarVertice('B');
    g.agregarVertice('C');

    g.agregarArista('A', 'B');
    g.agregarArista('A', 'C');
    g.agregarArista('B', 'C');

    g.mostrarGrafo();

    return 0;
}