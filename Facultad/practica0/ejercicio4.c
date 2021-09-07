#include <stdio.h>
#include <stdlib.h>

/**
 * ======================================Consigna=========================================
 * Programa que rellene un array con los numeros pares y otro con los impares 
 * comprendidos entre 1 y 100 y los muestre en pantalla en orden ascendente y descendente.
 * =======================================================================================
 */

/**
 * Llena un array de 50 posiciones con numeros pares desde el 1 al 100. Para ello, se lleva a cabo 
 * una division por 2, cuyo resto determinara si es par. Cuando el resto de la division sea 0, sabremos
 * que se trata de un numero par y, por ende, se guarda dentro del array de los numeros pares. 
 * @param evenNum Array vacio de 50 posiciones.
 * @param division Estructura de division.
 * @return Array con numeros pares del 1 al 100.
 */ 
int *getEvenNum(int *evenNum, div_t division) {
    //Contador
    int x = 0;

    for(int i = 1; i <= 100; i++) {
        division = div(i , 2);
        if (division.rem == 0) {
            evenNum[x] = i;
            x++;
        }
    }
    return evenNum;
}

/**
 * Llena un array de 50 posiciones con numeros impares desde el 1 al 100. Para ello, se lleva a cabo 
 * una division por 2, cuyo resto determinara si es impar. Cuando el resto de la division sea distinto de 
 * 0, sabremos que se trata de un numero impar y, por ende, se guarda dentro del array de los numeros impares.
 * @param oddNum Array vacio de 50 posiciones.
 * @param division Estructura de division.
 * @return Array con numeros impares del 1 al 100.
 */ 
int *getOddNum(int *oddNum, div_t division) {
    int y = 0;

    for(int i = 1; i <= 100; i++){
        division = div(i , 2);
        if (division.rem != 0) {
            oddNum[y] = i;
            y++;
        }
    }
    return oddNum;
}

int main() {
    const int MAX_ARRAY_SIZE = 50; 
    
    //Array de numeros pares.
    int evenNum[MAX_ARRAY_SIZE];

    //Array de numeros impares.
    int oddNum[MAX_ARRAY_SIZE];

    //Estructura que se utilizara para la division.
    div_t division;

    getEvenNum(evenNum, division);
    getOddNum(oddNum,division);

    printf("\nLos numeros pares son: ");
    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        printf("%d", evenNum[i]);
        if (i < 49) {
            printf(" , ");
        }
        else {
            printf(".\n");
        }
    } 

    printf("\nLos numeros impares son: ");
    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        printf("%d", oddNum[i]);
        if (i < 49) {
            printf(" , ");
        }
        else {
            printf(".\n");
        }
    }

    return 0;
}