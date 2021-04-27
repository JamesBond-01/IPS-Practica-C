#include <stdio.h>

int main ()
{
    char c;
    int nchar = 0;   /*Contador de numeros de caracteres*/
    
    printf ("\nIngrese caracteres <Enter> para finalizar:");

    /*Si el caracter es distinto a newline y c es igual a getchar, suma uno al contador de caracteres y vuelve a contar otro caracter*/
 
    while ((c = getchar ()) != '\n')  /*El getchar devuelve el char convertido a integer */  
    {
        nchar ++; /*n = n+ 1*/
    }

    printf ("\nSe ingresaron %d caracteres", nchar);

    return 0;
}