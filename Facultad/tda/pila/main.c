#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 5

void push(int *stack, int data);
int pop(const int *stack, int data);
bool isFull();
bool isEmpty();
int peek(const int *stack);

int top = -1;

int main() {
    int *stack = (int *)malloc(STACK_SIZE * sizeof(int));
    int menu, element;
    char option;

    do {
        printf("============================================\n");
        printf("Ingrese alguna de las siguientes opciones.\n");
        printf("============================================\n");
        printf("\t1. Agregar un elemento.\n");
        printf("\t2. Eliminar un elemento.\n");
        printf("\t3. Obtener el valor del ultimo elemento.\n");
        printf("> ");
        scanf("%d", &menu);
        switch(menu) {
            case 1:
                printf("Ingrese el elemento que desea agregar: ");
                scanf("%d", &element);
                push(stack, element);
                break;
            case 2:
                printf("Eliminando elemento...\n");
                element = pop(stack, element);
                break;
            case 3:
                printf("El ultimo elemento en el stack es: %d", peek(stack));
                break;
            default:
                printf("El valor ingresado no coincide con las opciones.\n");
                break;
        }
        printf("Desea reintentar? [Y/N]: ");
        scanf(" %c", &option);
    } while(option == 'y' || option == 'Y');

    printf("Elementos del stack:\n");
    while(!isEmpty()) {
        printf("\t%d\n", element);
        element = pop(stack, element);
    }

    return 0;
}

void push(int *stack, int data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}
int pop(const int *stack, int data) {
    if(!isEmpty()) {
        top = top - 1;
        data = stack[top];
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
int peek(const int *stack) {
    return stack[top];
}