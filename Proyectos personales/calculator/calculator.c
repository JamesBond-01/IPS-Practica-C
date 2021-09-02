#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double raiz (double num1)
{
    double result;

    result = sqrt (num1);       /*Realiza la raiz cuadrada de X numero.*/
               
    printf ("\nEl resultado de la raiz cuadrada de %lf = %lf \n", num1, result);

}

double potencia (double num1)
{
    double result, n;

    printf ("\nIngrese el exponente: ");        /*Pide al usuario el exponente para realizar la potencia.*/
    scanf ("%lf", &n);

    result = pow (num1, n);     /*Realiza la potencia de X numero elevado a N potencia.*/
                
    printf ("\nEl resultado de %lf ^ %lf = %lf \n", num1, n, result);  
}

int factorial (int num1)
{
    unsigned long long result;
    
    result = 1;
    
    while (num1 > 1)
    {
        result *= num1;     /*Multiplica el valor de result por el numero y lo guarda en la variable result.*/

        printf (" %d x ", num1);    /*Imprime en pantalla los numeros que se multiplican.*/

        num1 --;    /*Le resta 1 al numero para realizar la multiplicacion por el anterior.*/
    }
    printf (" 1 = %llu", result);     /*Imprime el 1 sin el 'x' y el resultado.*/
    
}

double suma (double num1, double num2)
{
    int result;
    
    result = num1 + num2;      /*Realiza la suma entre dos numeros X.*/
    
    printf ("\nEl resultado de %lf + %lf = %d\n", num1, num2, result);
}

double resta (double num1, double num2)
{
    double result;
    
    result = num1 - num2;       /*Realiza la resta entre dos numeros X.*/
    
    printf ("\nEl resultado de %lf - %lf = %lf\n", num1, num2, result);
}

double multiplicacion (double num1, double num2)
{
    double result;
    
    result = num1 * num2;       /*Realiza la multiplicacion entre dos numeros X.*/
    
    printf ("\nEl resultado de %lf * %lf = %lf\n", num1, num2, result);
}

double division (double num1, double num2)
{
    double result;
    
    result = num1 / num2;       /*Realiza la division entera entre dos numeros X.*/
    
    printf ("\nEl resultado de %lf / %lf = %lf\n", num1, num2, result);
}


int main ()
{
    char r;     /*Variable para reiniciar el programa.*/
    int operacion;
    double num1, num2;

    do
    {
        printf ("\n*Tabla de referencia*\n");
        printf ("\n\t1. Raiz cuadrada\n");
        printf ("\n\t2. Potencia\n");
        printf ("\n\t3. Factorial\n");
        printf ("\n\t4. Suma\n");
        printf ("\n\t5. Resta\n");
        printf ("\n\t6. Multiplicación\n");
        printf ("\n\t7. División entera\n");

        printf ("\nIngrese el primer número: ");
        scanf ("%lf" , &num1);

        printf ("\nIngrese la operación que desee realizar. (Ver tabla de referencia): \n"); 
        scanf ("%d" , &operacion);

        if (operacion > 3)      /*Si no es ni raiz ni potencia, pide otro número.*/
        {
            printf ("\nIngrese el segundo numero: ");
            scanf ("%lf", &num2);
        }       

        switch (operacion)      /*En base a la tabla de referencia, llamo a las funciones para realizar las operaciones.*/
        {
        case 1:
            raiz (num1); 
            break;
        
        case 2:
            potencia (num1);
            break;
        
        case 3:
            factorial (num1);
            break;
        
        case 4:
            suma (num1, num2);
            break;
        
        case 5:
            resta (num1, num2);
            break;
        
        case 6:
            multiplicacion (num1, num2);
            break;

        case 7:
            division (num1, num2);
            break;
        }

        if (operacion > 6)      /*Si la operación no está definida entre 1 a 6, envía un mensaje de error.*/
        {
            printf ("Invalid operation \n"); 
        }

        printf ("\nDesea reintentar? y/n \n");
        scanf (" %c", &r);  

        printf ("\n===============================================================\n");     /*Subrayado para dividir los reinicios del programa.*/
    } 
    
    while (r == 'y' );

    return 0;
    
}

    
      