#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};
void push(int data, struct node **top);
struct node * pop(struct node **top);
bool isEmpty(struct node *top);
void print(struct node *top);
int main() {
    struct node *stack = NULL;
    struct node *tmpStack1 = NULL;
    struct node *tmpStack2 = NULL;
    struct node *tmp = NULL;
    int input;
    char option;
    system("clear");
    printf("Ingrese los numeros que desee agregar al stack.\n");
    do {
        printf("\t>>> ");
        scanf("%d", &input);
        push(input, &stack);
        printf("Desea agregar otro numero? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');
    system("clear");
    printf("Stack Original:\n");
    print(stack);
    while(stack != NULL) {
        tmp = pop(&stack);
        push(tmp->data, &tmpStack1);
    }
    printf("Stack temporal 1:\n");
    print(tmpStack1);
    return 0;
}
void push(int data, struct node **top) {
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Error. No se pudo reservar memoria para el nuevo nodo.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = *top;
    *top = newNode;
}
struct node * pop(struct node **top) {
    struct node *tmp;
    int value;
    if(isEmpty(*top)) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    tmp = *top;
    value = tmp->data;
    *top = top->link;

    return tmp;
}
bool isEmpty(struct node *top) {
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}
void print(struct node *top) {
    struct node *tmp = top;
    if(isEmpty(top)) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    while(tmp) {
        printf("\t\t");
        printf("%d", tmp->data);
        printf("\n");
        tmp = tmp->link;
    }
}