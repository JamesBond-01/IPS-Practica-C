#include <stdio.h>
#include <malloc.h>
#include "../linkedListsLib/library.h"

struct node {
    int data;
    struct node *link;
} *top = NULL;

int main() {
    struct node *stack = malloc(sizeof(struct node));
    struct node *tmpStack1 = malloc(sizeof(struct node));
    struct node *tmpStack2 = malloc(sizeof(struct node));
    int num;

    printf("Ingrese los numeros que desee agregar al stack. Presione 0 para salir.\n");
    do {
        printf("\t>>> ");
        scanf("%d", &num);
        push(num);
    } while(num != 0);
    system("clear");

    return 0;
}
