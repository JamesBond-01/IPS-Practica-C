/**
 * Este programa, a diferencia de pilaArray, almacena el ultimo elemento ingresado en la primera posicion del array.
 * Es decir, el ultimo numero se guarda en stack[0].
 */

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
        printf("\t1. Agregar un numero.\n");
        printf("\t2. Eliminar un numero.\n");
        printf("\t3. Obtener el valor del ultimo numero ingresado.\n");
        printf("\t4. Obtener el total de numeros almacenados en la lista.\n");
        printf("\t5. Mostrar la lista.\n");
        printf("\t6. Salir.\n");
        printf("> ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                if(!isFull()) {
                    printf("Ingrese el elemento que desea agregar: ");
                    scanf("%d", &element);
                    push(element);
                } else {
                    printf("No se pueden agregar mas elementos a la lista.\n");
                }
                break;
            case 2:
                if(!isEmpty()) {
                    element = pop(element);
                } else {
                    printf("Lista vacia. No se pueden eliminar mas elementos.\n");
                }
                break;
            case 3:
                printf("El ultimo elemento en el stack es el numero %d.\n", peek());
                break;
            case 4:
                printf("La lista tiene un total de %d elementos.\n", size());
                break;
            case 5:
                if(first == -1) {
                    printf("Error al mostrar el stack: se encuentra vacio.\n");
                } else {
                    printf("Mostrando stack en pantalla...\n");
                    for (int i = 0; i <= first; i++) {
                        printf("\t%d\n", stack[i]);
                    }
                    printf("\n");
                }
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