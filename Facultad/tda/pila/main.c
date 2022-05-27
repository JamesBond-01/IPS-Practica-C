#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int number;
    struct Node *next;
} node;

void push(int number);
void pop();
void showList();
int size();
bool isEmpty();
int last();

node *topNode = NULL;

int main() {

    return 0;
}

void push(int number) {
    printf("Agregando nuevo elemento...\n");
    node *newNode = (node *)malloc(sizeof(node));
    newNode->number = number;
    newNode->next = topNode;
    topNode = newNode;
}
void pop() {
    printf("Eliminando el ultimo elemento...\n");
    if(topNode == NULL) {
        node *tmpNode = topNode;
        topNode = topNode->next;
        free(tmpNode);
    }
}
void showList() {
    node *tmpNode = topNode;
    while(tmpNode != NULL) {
        printf("\t%d\n", tmpNode->number);
        tmpNode = tmpNode->next;
    }
}
int size() {
    int counter = 0;
    if(topNode == NULL)
}