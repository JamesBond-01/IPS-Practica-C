#include <stdio.h>

int main ()
{
    int nchar = 0, ndigi = 0, nminusc = 0, nmayusc = 0, notros = 0; 
    char c;


    printf ("Ingrese caracteres <enter> para finalizar: ");

    while ((c = getchar ()) != '\n')
    {
        nchar ++;

        if (c >= '0' && c <= '9')
        {
            ndigi ++;
        }

        else if (c >= 'a' && c <= 'z')
        {
            nminusc ++;
        }
        
        else if (c >= 'A' && c <= 'Z')
        {
            nmayusc ++;
        }
        
        else 
        {
            notros ++;
        }
    } 
    printf ("Se ingresaron los siguientes caracteres:\n");
    printf (" %5d digitos 0 a 9\n", ndigi);
    printf (" %5d letras minusculas\n", nminusc);
    printf (" %5d letras mayusculas\n", nmayusc);
    printf (" %5d otros caracteres\n", notros);
    printf ("En total se ingresaron %5d caracteres", nchar);

    return 0;
}
