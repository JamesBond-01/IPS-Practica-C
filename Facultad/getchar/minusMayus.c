#include <stdio.h>
#include <ctype.h>

#define MAXCHAR 10

int main ()
{
    char c, st [MAXCHAR];
    int i, nchar = 0;

    printf ("Ingrese caracteres <Enter> para finalizar, maximo %d caracteres: ", MAXCHAR-1);

    while (((c = getchar ()) != '\n') && (nchar < MAXCHAR - 1))
    {
        st [nchar ++] = c;
    }

    st [nchar] = '\0';      /*El '\0' se utiliza para indicar la finalizacion de una cadena de caracteres.*/

    for (i = 0; st [i]; i++)
    {
        if ((st [i] >= 'a') && (st [i] <= 'z'))
        {
            st [i] = st [i] - 32;
        }
    }

    printf ("\nSe ingresaron %d caracteres\n", nchar);
    printf ("La cadena ingresada es %s\n", st);
    printf ("\n");
    
    return 0;
}