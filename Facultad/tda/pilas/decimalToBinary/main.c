#include <stdio.h>
#include "../pilasLib/library.h"

void conversion(int num);

int main() {
    int number;
    printf("Ingrese el numero que desee convertir a binario: ");
    scanf("%d", &number);
    conversion(number);

    return 0;
}
void conversion(int num) {
    int remainder;
    while(num != 0) {
        num = num / 2;
        remainder = num % 2;
        push(remainder);
    }
    while(top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}