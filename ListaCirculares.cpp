#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

// Estructura base para una Lista Circular
class ListaCircular{
    private:
        Nodo* ultimo;

    public:
        //Inicializamos la lista Circular
        ListaCircular(){
            ultimo=nullptr;
        }

        // Insertamos un nuevo elemento en lista cirular
        // return -> void
        // Parametros: int valor (El nuevo valor que recibira el nuevo nodo) 
        void insertar(int valor){
            Nodo* nuevo=new Nodo();
            nuevo->dato=valor;

            if(ultimo==nullptr){
                nuevo->siguiente=nuevo;
                ultimo=nuevo;
            }else{
                nuevo->siguiente=ultimo->siguiente;
                ultimo->siguiente=nuevo;
                ultimo=nuevo;
            }

        }

        // Mostrar todos los elementos de la lista Circular
        // return -> void
        void mostrar(){
            if(ultimo==nullptr){
                cout<<"Lista Vacia"<<endl;
            }
            Nodo* actual= ultimo->siguiente;// primer nodo
            while(actual!=ultimo->siguiente){
                cout<<actual->dato<<" ";
                actual=actual->siguiente;
            }
            cout<<endl;
        }
};