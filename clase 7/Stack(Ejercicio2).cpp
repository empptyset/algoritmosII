#include <iostream>
using namespace std;


/* La estructura Nodo representa un nodo de la lista enlazada que contiene 
   un valor y un puntero al siguiente nodo.
*/
struct Nodo {
    // valor almacenado en el nodo:
    long long dato;
    // puntero al siguiente nodo:
    Nodo* siguiente; 
};
/* Definimos la estructura de Pila que implementa una pila usando una lista enlazada.
*/ 
struct Pila {
    // puntero al nodo superior de la pila:
    Nodo* top;
    // constructor que inicializa top como nullptr
    Pila() : top(nullptr) {}
    
    // método para añadir un nuevo nodo a la pila:
    void push(long long x) {
        // creamos un nuevo nodo
        Nodo* nuevoNodo = new Nodo();
        // asignamos un dato al nodo
        nuevoNodo->dato = x;
        // el siguiente nodo del nuevo nodo será el actual nodo superior (top)
        nuevoNodo->siguiente = top;
        // el nuevo nodo se convierte en el top:
        top = nuevoNodo; 
    }

    // método que verifica si la pila está vacía o no.
    bool estaVacia() {
        // // se retorna true si top es nullptr
        return top == nullptr;
    }
    // método para eliminar el top de la pila.
    void pop() {
        if (estaVacia()) {
            return;
        }
        // guardamos el top actual en temp y designamos como top al siguiente nodo
        Nodo* temp = top; 
        top = top->siguiente; 
        delete temp; 
    }
    
    
    // método para obtener el top sin eliminarlo de la pila.
    long long peek() {
        if (estaVacia()) { 
            return -1; 
        }
        return top->dato; 
    }
};

/* Para el main vamos a leer las entradas y salidas de manera rápida. Vamos a iterar a través de cada "t"
   Tipo 1: lee el valor n y lo añade a la pila.
   Tipo 2: elimina el elemento del top de la pila.
   Tipo 3: imprime el valor top. Si la pila está vacía imprime Empty! 
*/
int main() {
    int t;
    scanf("%d", &t); 
    Pila s; 
    
    while (t--) {
        int tipo;
        scanf("%d", &tipo);

        if (tipo == 1) {
            long long n;
            scanf("%lld", &n);
            s.push(n);
        } else if (tipo == 2) {
            s.pop();
        } else if (tipo == 3) {
            if (s.estaVacia()) {
                printf("Empty!\n");
            } else {
                printf("%lld\n", s.peek());
            }
        }
    }

    return 0;
}
