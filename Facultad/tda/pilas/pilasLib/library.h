#ifndef PILASLIB_LIBRARY_H
#define PILASLIB_LIBRARY_H

#include <stdbool.h>
#define STACK_SIZE 100

extern int top;
int stack[STACK_SIZE];

void push(int data);
int pop();
bool isFull();
bool isEmpty();
int peek();
int size();

#endif //PILASLIB_LIBRARY_H
