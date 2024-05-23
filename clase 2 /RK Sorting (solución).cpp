#include <iostream>
#include <vector>

using namespace std;

// Utilizamos insertionSort para ordenar los números
// de mayor a menor, en caso de empate por el orden de
// aparición de menor a mayor. 
void insertionSort(vector<vector<int>>& frecuencias) {
    for (int i = 1; i < frecuencias.size(); i++) {
        vector<int> key = frecuencias[i];
        int j = i - 1;
        // movemos elementos que no cumplen con el criterio de ordenamiento
        while (j >= 0 && (frecuencias[j][1] < key[1] || (frecuencias[j][1] == key[1] && frecuencias[j][2] > key[2]))) {
            frecuencias[j + 1] = frecuencias[j];
            j--;
        }
        // insertamos el elemento en la posición correcta
        frecuencias[j + 1] = key; 
    }
}

int main() {
    // n es el número de elementos a leer.
    // c es el máximo valor posible de un número.
    int n, c;
    cin >> n >> c;

    //  vector que contiene el número, su frecuencia y su primera posición de 
    // aparición:
    vector<vector<int>> frecuencias;

    // se lee cada número
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool num_registrado = false;

        // verifica si el número ya existe y de ser así
        // aumenta su frecuencia en 1 
        for (auto& item : frecuencias) {
            if (item[0] == num) {
                item[1]++;
                num_registrado = true;
                break;
            }
        }

        // si el número no estaba registrado, añadirlo a frecuencias
        if (!num_registrado) {
            frecuencias.push_back({num, 1, i});
        }
    }

    // se llama a insertionSort para ordenar el vector
    insertionSort(frecuencias);

    // imprimimos los números ordenados por frecuencia y orden de aparición
    for (const auto& item : frecuencias) {
        for (int count = 0; count < item[1]; count++) {
            cout << item[0] << " ";
        }
    }
    cout << endl;

    return 0;
}
