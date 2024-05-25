#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

// utilizaremos mergesort, primero implementemos merge.
// merge recibe el vector (arreglo) y los índices para manejar el subarreglo que se va
// a ordenar.
// los índices serán el inicio, medio y final del arreglo (respectivamente).
void merge(vector<pair<long long, int>>& v, int v_0, int v_m, int v_f) {
    // tamaño del primer subarreglo:
    int n_1 = v_m - v_0 + 1;
    // tamaño del segundo subarreglo:
    int n_2 = v_f - v_m; 

    // vamos a crear dos arreglos para almacenar
    // el primer subarreglo, p, y el segundo subarreglo, q.
    vector<pair<long long, int>> p(n_1), q(n_2);

    // copiamos los elementos del arreglo v a estos subarreglos
    // que hemos creado:
    for (int i = 0; i < n_1; i++)
        p[i] = v[v_0 + i];
    for (int j = 0; j < n_2; j++)
        q[j] = v[v_m + 1 + j];

    // inicializamos los indices del primer y segundo subarreglo
    // vamos a iterar sobre p y q respectivamente
    int i = 0, j = 0;
    // inicializamos el índice para mantener la posición actual
    // en el vector v donde se insertará el elemento ordenado
    int k = v_0;

    // en este bucle se comparan los elementos de p y q, el elemento
    // más pequeño se coloca en v[k], se incrementa i o j según de que
    // subarreglo se tomó el elemento y k siempre se incrementa
    while (i < n_1 && j < n_2) {
        if (p[i].first <= q[j].first) {
            v[k] = p[i];
            i++;
        } else {
            v[k] = q[j];
            j++;
        }
        k++;
    }
    // si quedan elementos en p o q después de terminar, estos dos bucles
    // se aseguran que se copien al arreglo (vector) v. 
    while (i < n_1) {
        v[k] = p[i];
        i++;
        k++;
    }
    while (j < n_2) {
        v[k] = q[j];
        j++;
        k++;
    }
}

// vamos a implementar la función mergeSort: recibe un vector (arreglo) v, 
// y dos indices v_0 (inicio del rango a ordenar) y v_f (final del rango a ordenar).
void mergeSort(vector<pair<long long, int>>& v, int v_0, int v_f) {
    if (v_0 < v_f) {
        // si el rango tiene más de un elemento se calcula el punto medio, v_m
        int v_m = v_0 + (v_f - v_0) / 2;
        // luego, aplicamos mergeSort recursivamente a los dos subarreglos:
        mergeSort(v, v_0, v_m);
        mergeSort(v, v_m + 1, v_f);
        // llamamos a merge para combinar estos dos subarreglos ordenados
        // en un único arreglo (vector) ordenado
        merge(v, v_0, v_m, v_f);
    }
}



int main() {
    // declaramos dos variables: una para el número de casos de prueba: t,
    // y n para el número de elementos en cada caso de prueba.
    int t, n;
    cin >> t;
  
    while (t--) {
        cin >> n;
        // declaramos el vector (arreglo) v y un vector de enteros
        // que almacena la respuestas para cada caso de prueba.
        vector<pair<long long, int>> v(n);
        vector<int> ans(n);

        // bucle que intera n veces y leemos los elementos del arreglo
        // desde la entrada estandar y se almacenan en v[j].first.
        // Además, se establece al índice actual j, manteniendo un registro
        // del orden originl de los datos para su posterior uso.
        for (int j = 0; j < n; j++) {
            cin >> v[j].first;
            v[j].second = j;
        }
        
        // ordenamos el arreglo con mergeSort que acabamos de implementar:
        mergeSort(v, 0, n - 1);

        // inicializamos ac para acumular valores y k para controlar el índice
        // del siguiente elemento a considerar
        long long ac = 0;
        int k = 0; 
        
        // se recorre el vector v con el indice i, si i=k se suma v[i].first a ac,
        // y se incrementa k.
        for (int i = 0; i < n; i++) {
            if (i == k) {
                ac += v[i].first;
                k++;
            }
            // intentar sumar más elementos a ac mientras k sea menor que n, 
            // y ac sea suficiente para incluir el siguiente valor v[k].first
            while (k < n && ac >= v[k].first) {
                ac += v[k].first;
                k++;
            }
            // se asigna el valor indicando cuántos elementos pueden ser efecti-
            // vamente acumulados después de incluir el elemento en la posición i.
            ans[v[i].second] = k - 1; 
        }
        // se imprime cada valor almacenado en el vector ans, correspondiente
        // a cada posición original de los elementos en el vector de entrada.
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
