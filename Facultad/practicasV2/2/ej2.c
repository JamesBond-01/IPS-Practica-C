/*Que representa a un polinomio de orden n, cuyos n+1 coeficientes c0, c1,…, cn,
almacenados en el vector apuntado por coeficientes, corresponden a las potencias x0,
x1, …, xn*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct {
    int n;
    double *coeficiente;
} Polinomio;

Polinomio * creaPolinomio(int orden);
void setCoef(int n, double c, Polinomio * P);
double getCoef(int n, Polinomio * P);
double especializa( double x, Polinomio * P );
Polinomio * sum( Polinomio *p1, Polinomio *p2);
Polinomio * mult( Polinomio *p1, Polinomio *p2);
Polinomio * deriv( Polinomio *p );
void destruyePolinomio( Polinomio *p );
double ceropol( Polinomio *p, double a, double b, double epsilon);

int main() {
    int orden;
    Polinomio *polinomio;

    printf("Ingrese el orden que desee que tenga el polinomio: ");
    scanf("%d", &orden);

    polinomio = creaPolinomio(orden);
    setCoef(polinomio->n, *polinomio->coeficiente, polinomio);
    for(int i = 0; i <= orden; i++) {
        polinomio->coeficiente[i] = getCoef(polinomio->n, polinomio);
        printf("Coeficiente %f", polinomio->coeficiente[i]);
    }
}

Polinomio *creaPolinomio(int orden) {
    Polinomio *polinomio;

    polinomio->n = orden;
    polinomio->coeficiente = (double *) malloc((orden + 1) * sizeof(double));

    return polinomio;
}

void setCoef(int n, double c, Polinomio * P) {
    c = n + 1;
    for(int i = 0; i < c; i++) {
        P->coeficiente[i] = pow(n, i);
    }
}

double getCoef(int n, Polinomio * P) {
    return *P->coeficiente;
}

