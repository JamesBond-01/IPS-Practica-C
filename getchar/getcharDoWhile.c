#include <stdio.h>

int main ()
{
    char c;
    int nchar = 0;   /*Contador de numeros de caracteres.*/

    printf ("\nIngrese caracteres <Enter> para finalizar:");

/*Si el caracter es distinto a newline y c es igual a getchar, suma uno al contador de caracteres y vuelve a contar otro caracter.*/
   do
    {
        c = getchar (); /*El getchar devuelve el char convertido a integer.*/  
        nchar ++; /*n = n+ 1*/
    } 
    while (c != '\n');

    nchar --;  /*El loop de arriba es de exceso, por ende, le restamos uno al contador para que quede con el valor correcto.*/

    printf ("\nSe ingresaron %d caracteres", nchar);

    return 0;
}