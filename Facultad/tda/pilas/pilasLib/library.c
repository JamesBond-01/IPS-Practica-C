#include "library.h"

#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(int data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}
int pop(int data) {
    if(!isEmpty()) {top = -1;

        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Error al eliminar un elemento. Stack vacio.\n");
        return EXIT_FAILURE;
    }
}
bool isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}
bool isFull() {
    if(top == STACK_SIZE) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    return stack[top];
}
int size() {
    return top + 1;
}