#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define STRING_LENGH 30

void push(int data);
int pop();
bool isFull();
bool isEmpty();
int peek();
int size();

int top = -1;
int stack[STRING_LENGH];

int main() {
    char *tmpString = malloc(STRING_LENGH * sizeof(char));
    char *string = malloc(STRING_LENGH * sizeof(char));
    char *invString = malloc(STRING_LENGH * sizeof(char));

    printf("Ingrese una palabra: ");
    fgets(tmpString, STRING_LENGH, stdin);
    string[strcspn(tmpString, "\n")] = 0;
    for(int i = 0; i < (strlen(string)); i++) {

    }
    return 0;
}
void push(int data, ) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}
int pop() {
    int data;
    if(!isEmpty()) {
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