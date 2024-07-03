#include <iostream>
using namespace std;

// definimos la estructura de nodo usando lista doblemente enlazada
struct Nodo {
    long long valor;
    // puntero al anterior y siguiente nodo de la lista
    Nodo* siguiente;
    Nodo* anterior;       
    // constructor que inicializa los nodos
    Nodo(long long v) : valor(v), siguiente(nullptr), anterior(nullptr) {}
};

// definimos la estructura Cola
struct Cola {
    // puntero al primer nodo de la cola
    Nodo* frente; 
    // puntero al último nodo de la cola
    Nodo* final;
    // constructor que inicializa la cola como vacía
    Cola() : frente(nullptr), final(nullptr) {} 

    // método para agregar un elemento al final de la cola
    void enqueue(long long n) {
      // creamos un nuevo nodo con el valor n
        Nodo* nuevo = new Nodo(n);
        // si la cola no está vacía, el último nodo actual apunta al nuevo nodo
        // y el nuevo nodo apunta al antiguo último nodo.
        if (final != nullptr) {     
            final->siguiente = nuevo; 
            nuevo->anterior = final;  
        // en otro caso, el nuevo nodo se convierte en el primer nodo.
        } else {                
            frente = nuevo;         
        }
        final = nuevo;
    }

    // método para eliminar el primer elemento de la cola
    void dequeue() {
      // si la cola no está vacía, guarda el primer nodo en una variable temp, el segundo
      // nodo se convierte en el primer nodo.
        if (frente != nullptr) {    
            Nodo* temp = frente;    
            frente = frente->siguiente; 
            // si hay más nodos en la cola, el nuevo primer nodo no tiene nodo superior
            if (frente != nullptr) {   
                frente->anterior = nullptr; 
            // si la cola queda vacía, el último nodo se establece a nullptr
            } else {               
                final = nullptr;    
            }
            delete temp;
        }
    }

    // método para imprimir el primer elemento de la cola
    void print() const {
        // si la cola no está vacía, imprime el valor del primer nodo.
        // si está vacía, imprime "Empty!"
        if (frente != nullptr) {   
            printf("%lld\n", frente->valor); 
        } else {                  
            printf("Empty!\n");     
        }
    }

    // destructor para limpiar la memoria
    ~Cola() {
      // mientras haya nodos en la cola, guarda el primer nodo en una variable temp, el segundo
      // nodo se convierte en el primero y elimina el antiguo primer nodo.
        while (frente != nullptr) { 
            Nodo* temp = frente;    
            frente = frente->siguiente; 
            delete temp;      
        }
    }
};
// Para el main, creamos una instancia cola y por la entrada leemos t, iteramos sobre cada operación
// Tpo 1: se agrega el valor a la cola
// Tipo 2: elimina el primer elemento de la cola
// tipo 3: imprime el valor del primer elemento de la cola.
int main() {
    int t;
    scanf("%d", &t);

    Cola cola;                   
    for (int i = 0; i < t; ++i) { 
        int tipo;
        scanf("%d", &tipo);      

        if (tipo == 1) {         
            long long n;
            scanf("%lld", &n);   
            cola.enqueue(n);     
        } else if (tipo == 2) {  
            cola.dequeue();      
        } else if (tipo == 3) {  
            cola.print();        
        }
    }

    return 0; 
}
