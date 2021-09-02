#include <stdio.h>

/**
 * ==================================Consigna=========================================
 * Escriba un programa que lea por teclado diez numeros enteros distintos de
 * cero y a continuacion lea una secuencia de valores enteros indicando si estan
 * entre los diez valores leıdos. Cuando se lea el valor cero, el programa finalizara.
 * ===================================================================================
 */ 

//Array para guardar los 10 numeros.
int listNum[10];
//Contador.
int i;

/**
 * Input de los numeros de la lista.
 * Devuelve mensaje de error si se ingresa el numero 0 a la lista.
 */
void getList() {
    printf("Ingrese una lista de 10 numeros distintos de 0:\n");
    for(i = 0; i < 10; i++) {
        printf("\t*> ");
        scanf("%d", &listNum[i]); 
        while(listNum[i] == 0) {
            printf("\tValor incorrecto. Intente nuevamente.\n"); 
            printf("\t*> ");
            scanf("%d", &listNum[i]);
        }
    }
}

/**
 * Muestra la lista de numeros que ingreso el usuario.
 */ 
void showList(int *listNum) {
    printf("\nLa lista de numeros ingresados es: ");
    for(i = 0; i < 10; i++) {
        printf("%d", listNum[i]);
        //Luego de mostrar el ultimo numero del array, se ingresa un NewLine.
        //Sino, se escribe una coma entre numero y numero.
        if(i < 9) {
            printf(" , ");
        }
        else {
            printf("\n");
        }
    }
}

/**
 * Compara el numero que ingrese el usuario con la lista e imprime en pantalla
 * un mensaje indicando si el mismo se encuentra dentro de la lista.
 */
void isInTheList(int introducedNum){
    for(i = 0; i < 10; i++) {
        if(introducedNum == listNum[i]) {
            printf("%d esta en la lista.\n", introducedNum);
        }
    }
}

int main() {
    
    //Numero aleatorio que escribe el usaurio luego de la creacion de la list.
    int userNum; 

    getList();
    showList(listNum);

    printf("Ingrese numeros aleatorios.\n");
    printf("\t0 = Exit.\n");
    do {
        printf("\t*> ");        
        scanf("%d", &userNum);
        isInTheList(userNum);
    } while(userNum != 0);

    return 0;
}



