#include "library.h"

#include <stdio.h>
#include <stdlib.h>

struct edge *head = NULL;
struct edge *tmp = NULL;
struct edge *prevTmp = NULL;
struct edge *tail = NULL;

int find(int v) {
    if(dsuf[v].parent == -1) {
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);
}
void union_op(int fromP, int toP) {
    if(dsuf[fromP].rank > dsuf[toP].rank) {
        dsuf[toP].parent = fromP;
    } else if(dsuf[fromP].rank < dsuf[toP].rank) {
        dsuf[fromP].parent = toP;
    } else {
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1;
    }
}
void kruskal(struct edge *edge_list, int V, int E) {
    int i = 0;
    int j = 0;
    while(i < V-1 && j < E) {
        int fromP = find(edge_list[j].src);
        int toP = find(edge_list[j].dst);
        if(fromP == toP) {
            j++;
            continue;
        }
        union_op(fromP, toP);
        mst = enqueue(&edge_list[j]);
        i++;
    }
}
struct edge *enqueue(struct edge *edge_List) {
    struct edge *newEdge = malloc(sizeof(struct edge));
    if(newEdge == NULL) {
        printf("Error al reservar memoria.\n");
        exit(1);
    }
    newEdge->src = edge_List->src;
    newEdge->dst = edge_List->dst;
    newEdge->wt = edge_List->wt;
    newEdge->link = NULL;
    if(head == NULL) {
        head = newEdge;
        tail = newEdge;
        return head;
    }
    if(newEdge->wt <= head->wt) {
        newEdge->link = head;
        head = newEdge;
        return head;
    } else if(newEdge->wt > tail->wt) {
        tail->link = newEdge;
        tail = newEdge;
        return head;
    }
    tmp = head->link;
    prevTmp = head;
    while(prevTmp->link != NULL) {
        if((newEdge->wt > prevTmp->wt) && (newEdge->wt <= tmp->wt)) {
            newEdge->link = tmp;
            prevTmp->link = newEdge;
            return head;
        }
        prevTmp = tmp;
        tmp = tmp->link;
    }
    return head;
}
void print(struct edge *edge) {
    struct edge *ptr = edge;
    while(ptr) {
        printf("Src: %d\tDst: %d\tWt: %d\n", ptr->src, ptr->dst, ptr->wt);
        ptr = ptr->link;
   }
}