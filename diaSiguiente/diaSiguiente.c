#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int d, m, a;
    char r;

    do
    {
        printf ("\nIngrese el dia: ");
        scanf ("%d", &d);

        printf ("\nIngrese el mes: ");
        scanf ("%d", &m);

        printf ("\nIngrese el año (ultimos dos digitos): ");
        scanf ("%d", &a);

        printf("\n");

        if ((d >= 1 && d <= 31) && (m >= 1 && m <= 31 ))
        {
            if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
            {
                if (d >= 1 && d <= 29)
                {
                    d ++;
                }
                else if (d == 30)
                {
                    d = d - (d - 1);
                    m ++;
                }
                else 
                {
                    printf ("\nFecha no existente.\n");
                }
            }

            else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10))
            {
                if (d >= 1 && d <= 30)
                {
                    d ++;
                }
                else if (d == 31)
                {
                    d = d - (d - 1);
                    m ++;
                }
                else 
                {
                    printf ("\nFecha no existente.\n");
                } 
            }

            else if (m == 2)
            {
                if (d >= 1 && d <= 27)
                {
                    d ++;
                }
                else if (d == 28)
                {
                    d = d - (d - 1);
                    m ++;
                }
                else 
                {
                    printf ("\nFecha no existente.\n");
                } 
            }
        
            else if (m == 12)
            {
                if (d >= 1 && d <= 30)
                {
                    d ++;
                }
                else if (d == 31)
                {
                    d = d - (d - 1);
                    m = m - (m - 1);
                    a ++;
                }
                else 
                {
                    printf ("\nFecha no existente.\n");
                } 
            }

            printf ("La fecha siguiente a la fecha introducida es: %d/%d/%d\n", d, m, a);
        }
        
        else 
        {
            printf ("Fecha Incorrecta.\n");
        }

        printf ("\nDesea reintentar? y/n: ", r);
        scanf (" %c", &r); 
    }

    while (r != 'n');

    return 0;
}