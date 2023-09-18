#include <iostream>
using namespace std;

struct nodo {
    int info;
    nodo* sig;
};

void insertar(nodo*& lista, int x) {
    nodo* nuevo = new nodo;
    nuevo->info = x;
    nuevo->sig = lista;
    lista = nuevo;
}

void eliminar(nodo*& lista, int x) {
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

void modificar(nodo*& lista, int x, int y) {
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
    int option, x, y;

    do {
        cout<<"1. insertar"<<endl;
        cout<<"2. Eliminar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"4. Mostrar"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"=> ";
        cin>>option;
        switch (option) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> x;
                insertar(lista, x);
                break;
            case 2:
                cout << "Ingrese un numero: ";
                cin >> x;
                eliminar(lista, x);
                break;
            case 3:
                cout << "Ingrese un numero: ";
                cin >> x;
                cout << "Ingrese otro numero: ";
                cin >> y;
                modificar(lista, x, y);
                break;
            case 4:
                mostrar(lista);
                break;
            case 5:
                break;
        }
    } while (option != 5);

    return 0;
}