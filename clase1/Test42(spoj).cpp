#include <iostream>

using namespace std;

int main() {
    // declaramos una variable number para almacenar los números
    // que se leen de la entrada.
    int number;
    // bucle que lee los números desde la entrada estándar.
    // se detiene si no hay más números para leer o si se encuentra
    // un error de entrada.
    while (cin >> number) {
        // Si el número es 42, termina el bucle.
        if (number == 42) {
            break;
        }
        // Imprime los números si no es 42.
        cout << number << endl; 
    }
    return 0; 
}
