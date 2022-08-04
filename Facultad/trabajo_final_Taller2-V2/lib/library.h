#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include <stdbool.h>

struct node {
    int parent;
    int rank;
};

struct edge {
    int src;
    int dst;
    int wt;
    struct edge *link;
};

struct node *dsuf;
struct edge *mst;

int find(int v);
void union_op(int, int);
void kruskal(struct edge *, int, int);
void print(struct edge *);
struct edge * enqueue(struct edge *);

#endif //LIB_LIBRARY_H
