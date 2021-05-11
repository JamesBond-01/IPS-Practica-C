#include <stdio.h>
#include <stdlib.h>

int multiplos (int mult, int num)
{
    int i;

    for (i = 1; i <= mult; i++)
    {  
        printf ("%d", num * i);

        if (i < mult)
        {
            printf (", ");
        } 
    }

}

int main ()
{
    int multiplo, numero;

    printf ("Ingrese un numero aleatorio: ");
    scanf ("%d", &numero);

    printf ("\nIngrese la cantidad de multiplos que desee obtener: ");
    scanf ("%d", &multiplo);

    printf ("\nLos primeros %d multiplos de %d son: ",multiplo,numero); 

    multiplos (multiplo, numero);       

    return 0;
}
