#include "library.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *link;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data, int priority) {
    struct node *element = malloc(sizeof(struct node));
    if(element == NULL) {
        printf("Se ha producido un error al reservar memoria para el nuevo elemento.\n");
        exit(1);
    }
    element->data = data;
    element->priority = priority;
    element->link = NULL;
    if(isEmpty()) {
        front = element;
        return;
    }
    if(element->priority > front->priority) {
        element->link = front;
        front = element;
    } else if(element->priority == front->priority) {
        element->link = front->link;
        front->link = element;
    } else {
        front->link = element;
    }
}

