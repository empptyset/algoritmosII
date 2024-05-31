#include <iostream>
#include <vector>

using namespace std;

/* Vamos a utilizar el algoritmo de HeapSort, para ello necesitamos primero HEAPIFY: */

// Función para ajustar el subárbol con raíz en i en un heap:
void heapify(vector<vector<int>>& frecuencias, int n, int i) {
    // Inicializamos el más grande como nodo raíz:
    int largest = i; 
    // hijo izquierdo
    int left = 2 * i + 1;
    // hijo derecho
    int right = 2 * i + 2; 

    // Si el hijo izquierdo es más grande que el nodo raíz (o padre)
    if (left < n && (frecuencias[left][1] > frecuencias[largest][1] || 
        (frecuencias[left][1] == frecuencias[largest][1] && frecuencias[left][2] < frecuencias[largest][2]))) {
        largest = left;
    }

    // Si el hijo derecho es más grande que el más grande hasta ahora (bien sea la raíz o el hijo izquierdo)
    if (right < n && (frecuencias[right][1] > frecuencias[largest][1] || 
        (frecuencias[right][1] == frecuencias[largest][1] && frecuencias[right][2] < frecuencias[largest][2]))) {
        largest = right;
    }

    // Si el más grande no es el nodo raíz (o padre) intercambiar
    if (largest != i) {
        swap(frecuencias[i], frecuencias[largest]);

        // Hacemos este proceso recursiva para no afectar el resto del subarbol
        heapify(frecuencias, n, largest);
    }
}

// Ahora sí, definimos la función HeapSort:
void HeapSort(vector<vector<int>>& frecuencias) {
    int n = frecuencias.size();

    // Construimos el heap (reordenamos el vector frecuencias)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(frecuencias, n, i);
    }

    // Extraemos uno por uno los elementos del heap
    for (int i = n - 1; i > 0; i--) {
        // Movemos la raíz actual al final (intercambio con una hoja)
        swap(frecuencias[0], frecuencias[i]);

        // Llamamos a heapify en el heap reducido
        heapify(frecuencias, i, 0);
    }
}

// Vamos a usar esta función para revertir el orden de un vector y que el output sea el deseado
void invertir_vector(vector<vector<int>>& V) {
    int n = V.size();
    for (int i = 0; i < n / 2; i++) {
        swap(V[i], V[n - 1 - i]);
    }
}

int main() {
    // n es el número de elementos a leer.
    // c es el máximo valor posible de un número.
    int n, c;
    cin >> n >> c;

    // Vector que contiene el número, su frecuencia y su primera posición de aparición:
    vector<vector<int>> frecuencias;

    // se lee cada número
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool num_registrado = false;

        // Verifica si el número ya existe y de ser así
        // aumenta su frecuencia en 1 
        for (auto& item : frecuencias) {
            if (item[0] == num) {
                item[1]++;
                num_registrado = true;
                break;
            }
        }

        // Si el número no estaba registrado, añadirlo a frecuencias
        if (!num_registrado) {
            frecuencias.push_back({num, 1, i});
        }
    }

    // se llama a HeapSort para ordenar el vector
    HeapSort(frecuencias);

    // Revertimos el vector para obtener el orden correcto
    invertir_vector(frecuencias);

    // Imprimimos los números ordenados por frecuencia y orden de aparición
    for (const auto& item : frecuencias) {
        for (int count = 0; count < item[1]; count++) {
            cout << item[0] << " ";
        }
    }
    cout << endl;

    return 0;
}
