#include <stdio.h>
#include <stdlib.h>

#define ASC_ORDER 0
#define DESC_ORDER 1
#define MAX_INDEX 50
#define ARRAY_SIZE 100

/**
 * ======================================Consigna=========================================
 * Programa que rellene un array con los numeros pares y otro con los impares 
 * comprendidos entre 1 y 100 y los muestre en pantalla en orden ascendente y descendente.
 * =======================================================================================
 */

/**
 * Funcion que llena un array de numeros del 1 al 100.
 * @param numbers array vacio de 100 posiciones.
 * @return Array completados con numeros del 1 al 100.
 */ 
int *generateArray(int *numbers) {
    for(int i = 0; i < 100; i++){
        numbers[i]=i+1;
    }
    return numbers;
}

/**
 * 
 * 
 */ 
int *getEvenOdd(int *numbers, int *evenNum, int *oddNum, div_t division) {
    int x = 0, y = 0;
    for(int i = 0; i < 100; i++) {
        division = div(numbers[i] , 2);
        if (division.rem == 0) {
            evenNum[x] = numbers[i];
            x++;
        }
        else{
            oddNum[y] = numbers[i];
            y++;
        }
    }
    return evenNum, oddNum;
}




void showArray (int order, int max, int *arrayNum, div_t division){
    if (order == 0) {
        printf("\t\t");
        for(int i = 0; i < max; i++) {    
            division = div(i + 1, 10);
            printf("%d", arrayNum[i]);
            if (i < 49) {
                printf(" , ");
                if (division.rem == 0) {
                    printf("\n\t\t");    
                }
            }
            else {
                printf(".\n");
            }
        }
    }
    else if (order == 1) {
        printf("\t\t");
        for(int i = max - 1; i >= 0; i--) {
            division = div(i, 10);    
            printf("%d", arrayNum[i]);
            if (i > 0) {
                printf(" , ");
                if (division.rem == 0) {
                printf("\n\t\t");    
                }
            }
            else {
                printf(".\n");
            }
        }
    } 
}

int main() { 

    int numbers[ARRAY_SIZE];

    //Array de numeros pares.
    int evenNum[ARRAY_SIZE];

    //Array de numeros impares.
    int oddNum[ARRAY_SIZE];

    //Estructura que se utilizara para la division.
    div_t division;

    generateArray(numbers);
    getEvenOdd(numbers, evenNum, oddNum, division);
    
    printf("\nNumeros pares:");
    printf("\n\tOrden ascendente:\n");
    showArray(ASC_ORDER, MAX_INDEX, evenNum, division);
    printf("\n\tOrden descendente:\n");
    showArray(DESC_ORDER, MAX_INDEX, evenNum, division);

    printf("\nNumeros impares:");
    printf("\n\tOrden ascendente:\n");
    showArray(ASC_ORDER, MAX_INDEX, oddNum, division);
    printf("\n\tOrden descendente:\n");
    showArray(DESC_ORDER, MAX_INDEX, oddNum, division);


    printf(".........................................................................................\n");
    return 0;
}