#include <iostream>
using namespace std;

struct nodo {
    string info;
    nodo* sig;
};

void insertar(nodo*& lista, string x) {
    nodo* nuevo = new nodo;
    nuevo->info = x;
    nuevo->sig = lista;
    lista = nuevo;
}

void eliminar(nodo*& lista, string x) {
    nodo* aux = lista;
    nodo* ant = NULL;
    while (aux != NULL && aux->info != x) {
        ant = aux;
        aux = aux->sig;
    }
    if (aux != NULL) {
        if (ant == NULL) {
            lista = lista->sig;
        } else {
            ant->sig = aux->sig;
        }
        delete aux;
    }
}

void modificar(nodo*& lista, string x, string y) {
    nodo* aux = lista;
    while (aux != NULL && aux->info != x) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        aux->info = y;
    }
}

void mostrar(nodo* lista) {
    if (lista != NULL) {
        mostrar(lista->sig);
        cout << lista->info << endl;
    }
}

int main() {

    nodo* lista = NULL;
    string input;

    for (int i = 0; i < 5; i++) {
        cout<<"Ingrese un nombre: ";
        cin>>input;
        insertar(lista, input);
    }

    cout<<"Lista: "<<endl;
    mostrar(lista);

    return 0;
}