#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    int E = 10;         //Aristas
    int V = 6;          //Vertices
    int from, to, wt;   //Origen, destino y costo de la arista.

    dsuf = malloc(V * sizeof(struct node)); //Array donde se hacen las uniones de aristas.
    for(int i = 0; i < V; i++) {
        dsuf[i].parent = -1;    //Inicializo todos los padres en -1 para indicar que su padre es si mismo.
        dsuf[i].rank = 0;       //Inicializo todos los rangos en 0 para indicar que se encuentran vacios.
    }
    struct edge *edge_List;    //Lista de adyacencia.
    struct edge temp;
    //Guardo los costos de cada arista y los agrego a una cola de prioridad para ordenarlos segun sus costos.
    for(from = 1; from <= V; from++) {
        for(to = from + 1; to <= V; to++) {
            printf("Ingrese el costo de la arista entre %d y %d: ", from, to);
            scanf("%d", &wt);
            temp.src = from;
            temp.dst = to;
            temp.wt = wt;
            temp.link = NULL;
            edge_List = enqueue(&temp);
        }
    }
    kruskal(edge_List, V, E);
    print(mst);

    return 0;
}
