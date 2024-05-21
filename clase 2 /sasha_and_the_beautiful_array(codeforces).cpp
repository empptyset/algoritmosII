#include <iostream>
#include <vector>
using namespace std;

// declaramos la función bubbleSort, recibe como entrada un vector.
void bubbleSort(vector<long long>& array) {
  // el tamaño del vector se almacena en n.
  int n = array.size();
  // variable para rastrear si se hicieron
  // intercambios en la pasada actual del bucle.
  bool intercambio; 
  // bucle externo que controla el total de pasadas que se hacen
  // a través del vector.
  for (int i = 0; i < n-1; i++) {
    intercambio = false; 
    // realizamos n-i-1 comparaciones en la i-ésima pasada.
    for (int j = 0; j < n-i-1; j++) {
      if (array[j] > array[j+1]) {
        // si están en el orden incorrecto, se intercambian.
        swap(array[j], array[j+1]);
        intercambio = true;
      }
    }
    // si no se realizó ningún intercambio, el vector 
    // ya está ordenado:
    if (!intercambio)
        break;
  }
}

// resolvemos con ayuda de bubblesort el problema planteado en codeforces.
int main() {
    // declaramos la variable t para almacenar el número de casos de prueba
    // que se van a procesar.
    int t;
    cin >> t;
    // decrementamos t 
    while (t--) {
        // declaramos la variable n, que va a almacenar el número de elementos
        // en el arreglo para el caso de prueba actual
        int n;
        cin >> n;
        // declaramos el vector de tipo "long long" para poder llegar hasta 10^9.
        vector<long long> a(n);
        // iteramos desde 0 hasta n-1 para llenar el vector a con los elementos
        // del array.
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // ordenamos los elementos del vector con el algoritmo bubblesort que hemos
        // creado previamente:
        bubbleSort(a);
        // después de ordenado es claro que a[0] contiene el elemento más pequeño y
        // a[n-1] contiene el elemento más grande, así que calculamos su diferencia
        // que es la máxima belleza según la def del problema:
        cout << (a[n-1] - a[0]) << "\n";
    }
    return 0;
}
