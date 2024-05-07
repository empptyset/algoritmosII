#include <iostream>
#include <vector>

using namespace std;

int main() {
    // declaramos la variable t que almacena el número de casos de prueba.
    int t;
    // se lee desde la entrada estándar el número de casos de prueba.
    cin >> t;
    // bucle que se ejecuta por cada t hasta llegar a t = 0.
    while (t--) {
        // declaramos cartas: número total de cartas
        // y k: número necesario de cartas para realizar una operación.
        int cartas, k;
        // se leen desde la entrada estándar.
        cin >> cartas >> k;
        // arreglo para almacenar los números en cada carta.
        vector<int> numeros(cartas);
        // arreglo para contar las frecuencias de los números de las cartas.
        vector<int> frecuencia_cartas(101, 0); 
        // bucle que recorre cada carta
        for (int i = 0; i < cartas; i++) {
            // leemos el número de cada carta y lo almacena en el arreglo numeros.
            cin >> numeros[i];
            // después incrementa la frecuencia del número.
            frecuencia_cartas[numeros[i]]++;
        }
        // declaramos e inicializamos operacion, indica si es posible
        // realizar al menos una operación. 
        bool operacion = false;
        // bucle para recorrer para número de carta desde 1 - 100.
        for (int i = 1; i <= 100; i++) {
            // verificamos si la frecuencia del número de la carta es al menos k.
            if (frecuencia_cartas[i] >= k) {
                // si es así, es posible realizar al menos una operación.
                operacion = true;
                // sale del bucle ya que no necesitamos verificar más cartas.
                break;
            }
        }
        // ahora, si es posible realizar la operación
        if (operacion) {
            // imprime k-1, siempre se puede reducir el número de cartas a k-1
            // mediante operaciones repetidas.
            cout << k - 1 << "\n"; 
        // si no es posible realizar ninguna operación
        } else {
            // imprime el número total de cartas, ya que no se puede reducir el número de cartas.
            cout << cartas << "\n"; 
        }
    }
    return 0;
}
