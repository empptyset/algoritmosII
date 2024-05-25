#include <iostream>
#include <vector>
using namespace std;

// merge y mergesort explicados en el código anterior:
void merge(vector<long long>& v, int v_0, int v_m, int v_f) {
    int n_1 = v_m - v_0 + 1;
    int n_2 = v_f - v_m;
    vector<long long> p(n_1), q(n_2);

    for (int i = 0; i < n_1; i++)
        p[i] = v[v_0 + i];
    for (int j = 0; j < n_2; j++)
        q[j] = v[v_m + 1 + j];

    int i = 0, j = 0, k = v_0;
    while (i < n_1 && j < n_2) {
        if (p[i] <= q[j]) {
            v[k] = p[i];
            i++;
        } else {
            v[k] = q[j];
            j++;
        }
        k++;
    }
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
void mergeSort(vector<long long>& v, int v_0, int v_f) {
    if (v_0 < v_f) {
        int v_m = v_0 + (v_f - v_0) / 2;
        mergeSort(v, v_0, v_m);
        mergeSort(v, v_m + 1, v_f);
        merge(v, v_0, v_m, v_f);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        // N = número de establos
        // C = número de vacas 
        int N, C;
        cin >> N >> C;
        // inicializamos el vector establos con tamaño N para
        // almacenar las posiciones de los establos:
        vector<long long> establos(N);
        for (int i = 0; i < N; i++) {
            cin >> establos[i];
        }
        // ordenamos el vector establos con mergeSort, es necesario
        // para aplicar la búsqueda binaria:
        mergeSort(establos, 0, N - 1);
        
        // inicialización para busqueda binaria: 
        // l(limite inferior del rango de valores que estamos examinando para
        // la distancia mínima entre las vacas), h(limite superior) se calcula 
        //como la diferencia entre la posición más lejana y la más cercana, 
        // result almacena la distancia máxima minima encontrada.
        long long l = 0, h = establos[N-1] - establos[0], resultado = 0;
        // bucle de búsqueda binaria:
        // calculamos el punto medio mid, inicializamos count = 1 porque la primera vaca
        // se coloca en el primer establo. Y la ult_pos guarda la última posición 
        // en la que se colocó una vaca. 
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            int count = 1;
            long long ult_pos = establos[0];
            bool es_posible = true;
            
            // iteramos sobre "establos", si la distancia entre establos[i] y 
            // ult_pos es al menos mid se incrementa count y se actualiza ult_pos. 
            // Si se alcanza el número requerido de C vacas, se termina el bucle.
            for (int i = 1; i < N && es_posible; i++) {
                if (establos[i] - ult_pos >= mid) {
                    count++;
                    ult_pos = establos[i];
                    if (count == C) break;
                }
            }
            // si se logró colocar todas las vacas, se actualiza resultado a mid
            // y se intenta buscar una distancia mayor ajustando "l". Sino, se reduce
            // "h" para buscar una distancia menor.
            if (count >= C) {
                resultado = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        // se imprime la distancia máxima mínima encontrada para el caso de prueba. 
        cout << resultado << endl;
    }
    return 0;
}
