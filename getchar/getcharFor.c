#include <stdio.h>

int main ()
{
    char c;
    int nchar = 0;   /*Contador de numeros de caracteres.*/
    int nnumb = 0; /*Contador de caracteres numericos.*/
    int nletras = 0;  /*Contador de caracteres alfabéticos*/

    printf ("\nIngrese caracteres <Enter> para finalizar:");

    for (nchar = 0; (c = getchar ()) != '\n'; ++ nchar)

    if (c >= '0' && c <= '9')  /*Valores del tipo char, donde van a ser transformados por valores de la tabla ASCII.*/
    {
        nnumb ++;
    }
    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        nletras ++;
    }


    printf ("\nSe ingresaron %d caracteres", nchar);
    printf ("\nSe ingresaron %d digitos numéricos", nnumb);
    printf ("\nSe ingresaron %d letras\n", nletras);

    return 0;
}