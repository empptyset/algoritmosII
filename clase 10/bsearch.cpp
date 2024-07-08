#include <iostream>
using namespace std;

// enumeración para definir los colores de los nodos
enum Color { RED, BLACK };

// definición de la estructura de un nodo en el árbol rojo negro
struct Nodo {
    // valor del nodo
    int datos;
    // posición del nodo en el array original
    int pos;
    // color del nodo
    bool color;
    // punteros a los hijos izquierdo, derecho y al padre
    Nodo *izquierda, *derecha, *parent;
    // constructor para inicializar un nodo con un valor y un pos específicos
    Nodo(int datos, int pos) : datos(datos), pos(pos) {
        parent = izquierda = derecha = nullptr;
        // nuevo nodo siempre se inserta como rojo
        color = RED;
    }
};

// definimos la estructura de arbol rojo negro
struct ArbolRojoNegro {
    // puntero a la raíz del arbol 
    Nodo *raiz;

    ArbolRojoNegro() { raiz = nullptr; }
    
    // declaramos las funciones para rotaciones y arreglos
    // de inserción.
    void rotateLeft(Nodo *&, Nodo *&);
    void rotateRight(Nodo *&, Nodo *&);
    void fixInsertion(Nodo *&);
    // inserción y busqueda en el árbol BB.
    Nodo* insertarenBST(Nodo* raiz, Nodo *pt);
    Nodo* buscarNodo(Nodo* raiz, int datos);
    // declaramos las funciones para insertar y buscar en el arbole
    void insert(int datos, int pos);
    int buscar(int datos);
};

// rotación a la izquierda para mantener las propiedades del ArbolRojoNegro.
// ajustamos los punteros para que el subarbol se mantenga balanceado
// y las relaciones de padre e hijo sean correctas.
void ArbolRojoNegro::rotateLeft(Nodo *&raiz, Nodo *&pt) {
    Nodo *pt_derecha = pt->derecha;

    pt->derecha = pt_derecha->izquierda;
    if (pt->derecha != nullptr) pt->derecha->parent = pt;

    pt_derecha->parent = pt->parent;
    if (pt->parent == nullptr)
        raiz = pt_derecha;
    else if (pt == pt->parent->izquierda)
        pt->parent->izquierda = pt_derecha;
    else
        pt->parent->derecha = pt_derecha;

    pt_derecha->izquierda = pt;
    pt->parent = pt_derecha;
}

// rotación a la derecha para mantener las propiedades del ArbolRojoNegro
// ajustamos los punteros de manera similar a la rotación izquierda,
// pero en la dirección opuesta.
void ArbolRojoNegro::rotateRight(Nodo *&raiz, Nodo *&pt) {
    Nodo *pt_izquierda = pt->izquierda;

    pt->izquierda = pt_izquierda->derecha;
    if (pt->izquierda != nullptr) pt->izquierda->parent = pt;

    pt_izquierda->parent = pt->parent;
    if (pt->parent == nullptr)
        raiz = pt_izquierda;
    else if (pt == pt->parent->izquierda)
        pt->parent->izquierda = pt_izquierda;
    else
        pt->parent->derecha = pt_izquierda;

    pt_izquierda->derecha = pt;
    pt->parent = pt_izquierda;
}

// arreglar la inserción y mantener las propiedades del ArbolRojoNegro
// realizamos rotaciones y cambios de color según sea necesario para
// asegurar que el árbol siga siendo balanceado y cumplas con las propiedades.
void ArbolRojoNegro::fixInsertion(Nodo *&pt) {
    Nodo *parent_pt = nullptr;
    Nodo *grandparent_pt = nullptr;

    while ((pt != raiz) && (pt->color != BLACK) &&
           (pt->parent != nullptr && pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grandparent_pt = pt->parent->parent;

        if (parent_pt == grandparent_pt->izquierda) {
            Nodo *uncle_pt = grandparent_pt->derecha;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grandparent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandparent_pt;
            } else {
                if (pt == parent_pt->derecha) {
                    rotateLeft(raiz, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(raiz, grandparent_pt);
                swap(parent_pt->color, grandparent_pt->color);
                pt = parent_pt;
            }
        } else {
            Nodo *uncle_pt = grandparent_pt->izquierda;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grandparent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandparent_pt;
            } else {
                if (pt == parent_pt->izquierda) {
                    rotateRight(raiz, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(raiz, grandparent_pt);
                swap(parent_pt->color, grandparent_pt->color);
                pt = parent_pt;
            }
        }
    }
    // la raíz siempre debe ser negra
    raiz->color = BLACK; 
}

// funcion pr ainsertar un nodo en el árbol binario de busqueda 
// colocamos el nodo en la posición correcta basándonos en su
// valor, y ajustamos los punteros de los nodos padres e hijos
Nodo* ArbolRojoNegro::insertarenBST(Nodo* raiz, Nodo *pt) {
    if (raiz == nullptr) return pt;

    if (pt->datos < raiz->datos) {
        raiz->izquierda = insertarenBST(raiz->izquierda, pt);
        raiz->izquierda->parent = raiz;
    } else if (pt->datos > raiz->datos) {
        raiz->derecha = insertarenBST(raiz->derecha, pt);
        raiz->derecha->parent = raiz;
    }

    return raiz;
}

// función para insertar un nuevo nodo y arreglar el ArbolRojoNegro
void ArbolRojoNegro::insert(int datos, int pos) {
    Nodo *pt = new Nodo(datos, pos);
    raiz = insertarenBST(raiz, pt);
    fixInsertion(pt);
}

// funcion para buscar un nodo en el ArbolRojoNegro (auxiliar)
Nodo* ArbolRojoNegro::buscarNodo(Nodo* raiz, int datos) {
    if (raiz == nullptr || raiz->datos == datos) return raiz;
    if (datos < raiz->datos) return buscarNodo(raiz->izquierda, datos);
    return buscarNodo(raiz->derecha, datos);
}

// función pra buscar un nodo y devolver su posición
int ArbolRojoNegro::buscar(int datos) {
    Nodo* resultado = buscarNodo(raiz, datos);
    // retornamos la posición, si el nodo no se encuentra devolvemos -1.
    return (resultado != nullptr) ? resultado->pos : -1;
}

// aquí en el main: insertamos los elementos en el arbol, procesa y busca en el ArbolRojoNegro
// mostramos los resultados.
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    ArbolRojoNegro tree;
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        tree.insert(num, i);
    }

    for (int i = 0; i < Q; ++i) {
        int query;
        scanf("%d", &query);
        int resultado = tree.buscar(query);
        if (resultado != -1) {
            printf("%d\n", resultado);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
