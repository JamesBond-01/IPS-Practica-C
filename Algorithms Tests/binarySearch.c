/*
 * El algoritmo de busqueda binaria consiste en la busqueda de un elemento dentro de un array ordenado.
 *
 * Lo que hace este algoritmo es comparar el valor del elemento que queremos encontrar, con el de la mitad del array.
 * Si estos son desiguales, el algoritmo sigue comparando con la mitad de posiciones donde dicho elemento se podria
 * encontrar. Es decir, si nuestro numero es mayor al de la mitad del array, comparamos de la mitad en adelante.
 * De lo contrario, si es menor, evaluamos del comienzo hasta la mitad.
 *
 * Luego, nuevamente se comparan el valor de nuestro elemento junto a la mitad de la parte restante del array.
 * Esto se repite hasta encontrar dicho valor.
 *
 * En caso de no encontrarlo, se llega a la conclusion de que lo que queremos buscar no se encuentra en el array.
 */

#include <stdio.h>
#include <stdbool.h>

bool binarySearchAlgorithm(const int *array, int target, int arrayLengh);

int main() {
    int target;
    int array[] = {1,3,6,9,11,23,34,54,76};

    //Con esta division obtengo el total de elementos en el array.
    int arrayLengh = sizeof(array) / sizeof(int);

    printf("Ingrese el numero que desee saber si se encuentra en el array: ");
    scanf("%d", &target);

    binarySearchAlgorithm(array, target, arrayLengh);

    return 0;
}

bool binarySearchAlgorithm(const int *array, int target, int arrayLengh) {
    int lowerLimit = 0;                 //Variable donde se almacena el limite minimo a tomar dentro del array.
    int upperLimit = arrayLengh - 1;    //Variable donde se almacena el limite maximo a tomar dentro del array.
    int middleNumber;                   //Variable donde se establece la mitad del array.

    //Mientras el limite maximo sea mayor o igual al minimo, se compara nuestro numero con el de la mitad.
    while(upperLimit >= lowerLimit) {
        middleNumber = (lowerLimit + upperLimit) / 2;

        //Si el valor de nuestro numero coincide con algun elemento de la lista, se termina el algoritmo
        //de forma exitosa.
        if(array[middleNumber] == target) {
            printf("El numero %d se encuentra en el array, en la posicion %d.\n", target, middleNumber);
            return true;
        }
        //Si nuestro objetivo es mayor al del elemento que se esta comparando en el array, evaluamos solo la parte
        //donde se pueda encontrar nuestro numero. En este caso, se puede hallar de la mitad en adelante.
        //Por esta razon, decimos que el limite minimo es un numero mayor al que se esta tomando como mitad.
        else if (array[middleNumber] < target) {
            lowerLimit = middleNumber + 1;
        }
        //Si por el contrario, el numero que elegimos es menor al del punto de comparacion, tomamos desde el inicio
        //hasta la mitad.
        //Es por esto que establecemos que el limite maximo es un numero menor al que se esta tomando como mitad.
        else if (array[middleNumber] > target) {
            upperLimit = middleNumber - 1;
        }
    }
    //Si no se encuentra el numero en el array, devuelve falso.
    printf("El numero %d no se encuentra en el array\n", target);
    return false;
}
