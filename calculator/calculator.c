#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    char operations;
    char r;         //Variable donde se guarda el valor para reintentar. 
    double num1;
    double num2;
    double result;
    double n;       //Variable donde se guarda el valor del exponente.

    do
    {
        printf ("\nEnter the first number: ");
        scanf ("%lf" , &num1);

        printf ("\nPlease enter: '+' , '-'  , '*', '/', '^'(potencia) or '~' (raiz) : ");  //El usuario elige que operacion realizar.
        scanf (" %c" , &operations);

        printf ("\n");

        if (operations == '~' || operations == '^')  //Analiza que el usuario haya introducido un operador correcto.
        {
            if (operations == '~')
            {
                result = sqrt (num1);                //Realiza la raiz cuadrada de X numero.
               
                printf ("El resultado de la raiz cuadrada de %f = %f \n", num1, result); 
            }
            else if (operations == '^')                     
            {
                printf ("Ingrese el exponente al que desee elevar el numero: ");
                scanf ("%lf", &n);

                result = pow (num1, n);           //Realiza la potencia de X numero elevado a la N.
                
                printf ("\nEl resultado de %f %c %f = %f \n", num1, operations, n, result);  //Muestra en pantalla el resultado de la potencia.
            }
        }

        else if (operations == '+' || operations == '-' || operations == '*' || operations == '/')  //Analiza que el usuario haya introducido un operador correcto.
        {            
            printf ("Enter the second number: ");   //Si el usuario desea realizar estas operaciones, necesita otro numero. 
            scanf ("%lf" , &num2);

            if (operations == '+')
            {
                result = num1 + num2;                                 
            }

            else if (operations == '-')
            {
                result = num1 - num2;                
            }
                                             
            else if (operations == '*')            //Si el usuario introdujo un operador correcto, analiza qué tipo de operacion realizar y guarda el resultado en Result.
            {
                result = num1 * num2;                
            }

            else if (operations == '/')
            {
                result = num1 / num2;                
            }

            printf ("\nEl resultado de %f %c %f = %f\n" , num1, operations, num2, result);  //Muestra en pantalla los numeros introducidos, la operacion a realiazr y el resultado.
        }

        else 
        {
            printf ("Invalid operation \n");   //Si el operador no corresponde a ninguno de los mencionados, lanza error.
        }

        printf ("\nDesea reintentar? y/n \n");
        scanf (" %c", &r);  

        printf ("\n");
    } 
    
    while (r == 'y' );

    return 0;
    
}

    
      