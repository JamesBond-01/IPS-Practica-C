#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

int first = -1;
int stack[STACK_SIZE];
void push(int data) {
    if(!isFull()) {
        first = first + 1;
        for(int i = first; i > 0; i--) {
            stack[i] = stack[i - 1];
        }
        stack[0] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}
int pop(int data) {
    if(!isEmpty()) {
        data = stack[0];
        for(int i = 0; i < first; i++) {
            stack[i] = stack[i + 1];
        }
        first = first - 1;
        printf("Elemento %d eliminado con exito.\n", data);
        return data;
    } else {
        printf("Error al eliminar un elemento. Stack vacio.\n");
        return EXIT_FAILURE;
    }
}
bool isEmpty() {
    if(first == -1) {
        return true;
    } else {
        return false;
    }
}
bool isFull() {
    if(first == STACK_SIZE -1) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    if(!isEmpty()) {
        return stack[0];
    } else {
        printf("El stack se encuentra vacio.\n");
        return 0;
    }
}
int size() {
    return first + 1;
}
void printStack() {
    if(isEmpty()) {
        printf("El stack se encuentra vacio.");
    }
    for(int i = 0; i <= first; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
