#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    int m_Costos[VERTICES][VERTICES];
    rama *arbol = malloc(sizeof(rama));

    for(int i = 0; i < VERTICES; i++) {
        for(int j = i + 1; j < VERTICES; j++) {
            printf("Ingrese el costo de la arista entre %d y %d: ", i, j);
            scanf("%d", &m_Costos[i][j]);
        }
    }

    for(int i = 0; i < VERTICES; i++) {
        for(int j = i + 1; j < VERTICES; j++) {
            if(m_Costos[i][j] != 0) {
                inserta(i, j, m_Costos[i][j], &arbol);
            }
        }
    }
    lista();
    //kruskal(arbol);
    return 0;
}
