#include <stdio.h>
#include <malloc.h>

#define MAX_DECIMAL_SIZE 4
#define MAX_OCTAL_SIZE 6
#define MAX_HEXA_SIZE 6
#define MAX_BINARY_SIZE 6


char *decimalRep(int num);
char *octalRep(int num);
char *hexaRep(int num);
char *binaryRep(int num);

int main() {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("Representacion decimal de %d: %s\n", num, decimalRep(num));
    printf("Representacion octal de %d: %s\n", num, octalRep(num));

    return 0;
}
char *decimalRep(int num) {
    char *numString = (char *)malloc(MAX_DECIMAL_SIZE * sizeof(char));
    sprintf(numString, "%d", num);

    return numString;
}
char *octalRep(int num) {
    char *numString = (char *) malloc(MAX_OCTAL_SIZE * sizeof(char ));
    int *rest = (int *)malloc(MAX_OCTAL_SIZE * sizeof(int));
    int *pRest = rest;
    int i = 0;

    while(num >= 8) {
        *rest = num % 8;
        num = num / 8;
        rest++;
        i++;
    }
    *rest = num;
    for(int j = i; j >= 0; j--) {
        sprintf(numString, "%d", *rest);
        rest--;
    }
    return numString;
}
char *hexaRep(int num) {
    char *numString = (char *)malloc(MAX_HEXA_SIZE * sizeof(char));

}
