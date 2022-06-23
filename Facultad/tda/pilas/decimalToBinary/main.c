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
    int remainder, spaceCounter;
    spaceCounter = 0;
    while(num != 0) {
        remainder = num % 2;
        push(remainder);
        num = num / 2;
        spaceCounter ++;
    }
    spaceCounter = 0;
    while(top != -1) {
        printf("%d", pop());
        if(spaceCounter == 4) {
            printf(" ");
        }
    }
    printf("\n");
}