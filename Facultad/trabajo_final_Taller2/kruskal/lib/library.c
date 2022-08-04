#include <stdio.h>
#include <stdlib.h>
#include "library.h"

rama *head = NULL;
rama *tail = NULL;
rama *tmp = NULL;
rama *prevTmp = NULL;

/**
 * Esta funcion inicializa las variables para que A sea el nombre de un componente que pertenece a C,
 * y que inicialmente contiene el vertice v.
 * @param A Nombre componente
 * @param v Vertice
 * @param C Conjunto formado por combina() y encuentra().
 */
void inicial(tipo_nombre A, tipo_elemento v, conjunto_CE * C) {
    C->nombres[v].nombreConjunto = A;
    C->nombres[v].sigElemento = 0;
    C->encabezamientosConjunto[A].cuenta = 1;
    C->encabezamientosConjunto[A].primerElemento = v;
}
void combina(tipo_nombre A, tipo_nombre B, conjunto_CE * C) {
    int i;
    if(C->encabezamientosConjunto[A].cuenta > C->encabezamientosConjunto[B].cuenta) {
        i = C->encabezamientosConjunto[B].primerElemento;
        do {
            C->nombres[i].nombreConjunto = A;
            i = C->nombres[i].sigElemento;
        } while(C->nombres[i].sigElemento != 0);
        C->nombres[i].nombreConjunto = A;
        C->nombres[i].sigElemento = C->encabezamientosConjunto[A].primerElemento;
        C->encabezamientosConjunto[A].cuenta = C->encabezamientosConjunto[A].cuenta + C->encabezamientosConjunto[B].cuenta;
    } else {
        i = C->encabezamientosConjunto[A].primerElemento;
        do {
            C->nombres[i].nombreConjunto = B;
            i = C->nombres[i].sigElemento;
        } while(C->nombres[i].sigElemento != 0);
        C->nombres[i].nombreConjunto = B;
        C->nombres[i].sigElemento = C->encabezamientosConjunto[B].primerElemento;
        C->encabezamientosConjunto[B].cuenta = C->encabezamientosConjunto[B].cuenta + C->encabezamientosConjunto[A].cuenta;
    }
}
int encuentra(int v, conjunto_CE * C) {
    return C->nombres[v].nombreConjunto;
}
//void kruskal(rama *arbol) {
//    rama *T;
//    arista *aristas, a;
//    conjunto_CE componentes;
//    int comp_n, comp_sig, comp_u, comp_v;
//    vertice U, V;
//
//    T = NULL;
//    aristas = NULL;
//    comp_sig = 0;
//    comp_n = V;
//    for(int v = 0; v < V; v++) {
//        comp_sig = comp_sig + 1;
//        inicial(comp_sig, v, &componentes);
//    }
//    for(int i = 0; i < V; i++) {
//        inserta(a.u, a.v, a.costo, &T);
//    }
//    while(comp_n > 1) {
//        a = *sacar_min();
//        comp_u = encuentra(a.u, &componentes);
//        comp_v = encuentra(a.v, &componentes);
//        if(comp_u != comp_v) {
//            combina(comp_u, comp_v, &componentes);
//            comp_n = comp_n - 1;
//            inserta(a.u, a.v, a.costo, &arbol);
//        }
//    }
//    lista();
//}
void inserta(int vertice_a, int vertice_b, int costo, rama **arbol) {
    (*arbol)->a.u = vertice_a;
    (*arbol)->a.v = vertice_b;
    (*arbol)->a.costo = costo;
    (*arbol)->sig = NULL;
    if(head == NULL) {
        head = *arbol;
        tail = *arbol;
        return;
    }
    if((*arbol)->a.costo <= head->a.costo) {
        (*arbol)->sig = head;
        head = (*arbol);
        return;
    } else if((*arbol)->a.costo > head->a.costo) {
        tail->sig = (*arbol);
        tail = (*arbol);
        return;
    }
    tmp = head->sig;
    prevTmp = head;
    while(prevTmp->sig != NULL) {
        if(((*arbol)->a.costo > prevTmp->a.costo) && ((*arbol)->a.costo <= tmp->a.costo)) {
            (*arbol)->sig = tmp;
            prevTmp->sig = (*arbol);
            return;
        }
        prevTmp = tmp;
        tmp = tmp->sig;
    }
}
arista sacar_min() {
    if(head == NULL) {
        printf("La cola se encuentra vacia.\n");
        exit(1);
    }
    tmp = head;
    arista aristaSelec = head->a;
    head = head->sig;
    free(tmp);
    tmp = NULL;
    return aristaSelec;
}
void lista() {
    if(head == NULL) {
        printf("La cola se encuentra vacia.\n");
        return;
    }
    arista cola;
    tmp = head;
    while(tmp) {
        cola = sacar_min();
        printf("(%d, %d) - %d\n", cola.u, cola.v, cola.costo);
        tmp = tmp->sig;
    }
}
