#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

void push(int data);
int pop(int data);
bool isFull();
bool isEmpty();
int peek();
int size();

int first = -1;
int stack[STACK_SIZE];

int main() {
    int menu, element;

    system("clear");
    printf("============================================\n");
    printf("Ingrese alguna de las siguientes opciones.\n");
    printf("============================================\n");
    while(1) {
        printf("\t1. Agregar un elemento.\n");
        printf("\t2. Eliminar un elemento.\n");
        printf("\t3. Obtener el valor del ultimo elemento.\n");
        printf("\t4. Obtener el total de elementos en la lista.\n");
        printf("\t5. Mostrar la lista.\n");
        printf("\t6. Salir.\n");
        printf("> ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Ingrese el elemento que desea agregar: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop(element);
                printf("Elemento %d eliminado con exito.\n", element);
                break;
            case 3:
                printf("El ultimo elemento en el stack es: %d.\n", peek());
                break;
            case 4:
                printf("La lista tiene un total de %d elementos.\n", size());
                break;
            case 5:
                printf("Mostrando stack en pantalla...\n");
                for (int i = 0; i <= first; i++) {
                    printf("\t%d\n", stack[i]);
                }
                printf("\n");
                break;
            case 6:
                system("clear");
                return 1;
            default:
                printf("El valor ingresado no coincide con las opciones.\n");
                break;
        }
    }
}

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
    if(first == STACK_SIZE) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    return stack[first];
}
int size() {
    return first + 1;
}