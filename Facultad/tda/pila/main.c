#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int number;
    struct Node *next;
} node;

void push(int number);
void pop();
void print();
int size();
bool isEmpty();
int last();

node *superior = NULL;

int main() {

    return 0;
}

void push(int number) {
    print("Agregando nuevo elemento...\n");
    node *newNode = (node *)malloc(sizeof(node));

}