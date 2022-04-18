/*Escriba un programa que lea por teclado diez numeros enteros distintos de cero y a continuacion lea una secuencia de
valores enteros indicando si estan entre los diez valores leıdos. Cuando se lea el valor cero, el programa finalizara.*/

#include <stdio.h>
#define LIST_SIZE 10

void listGen(int *numList);
void isInTheList(const int *numList);

int main() {
	int numList[LIST_SIZE];

	printf("Ingrese 10 valores distintos de 0:\n");
	listGen(numList);
	printf("\nIngrese numeros aleatorios y se informara si los mismos se encuentran en la lista.\nIngrese 0 para "
           "finalizar.\n");
	isInTheList(numList);
	return 0;
}
/**
 * Funcion para generar la lista de numeros.
 * @param numList: array de (LIST_SIZE) numeros el cual, sera completado mediante esta funcion.
 */
void listGen(int *numList) {
    //Pido al user (LIST_SIZE) numeros distintos de 0.
	for (int i = 0; i < LIST_SIZE; i++) {
		printf("> ");
		scanf("%d", &numList[i]);
        //Al ingresar un 0, se le pedira otro numero hasta que el mismo sea distinto de 0.
		while(numList[i] == 0) {
			printf("Por favor, ingrese un valor distinto de 0: ");
			scanf("%d", &numList[i]);
		}
	}
}
/**
 * Funcion para comparar si los numeros que se ingresan, se encuentran en la lista previamente armada en la funcion
 * listGen(). \n El user ingresara numeros hasta que el mismo sea igual a 0. \n Al ingresar 0, finaliza el programa.
 *
 * @param numList: array de (LIST_SIZE) numeros.
 */
void isInTheList(const int *numList) {
	int selectedNum = 1;
	while(selectedNum != 0) {
		printf("> ");
		scanf("%d", &selectedNum);
        //Comparo el numero ingresado con cada posicion de la lista.
		for(int i = 0; i < LIST_SIZE; i++) {
            //Si encuentra una coincidencia, se informa en pantalla.
			if(selectedNum == numList[i]) {
				printf("El numero %d se encuentra en la lista.\n", selectedNum);
				break;
			}
		}
	}
}
