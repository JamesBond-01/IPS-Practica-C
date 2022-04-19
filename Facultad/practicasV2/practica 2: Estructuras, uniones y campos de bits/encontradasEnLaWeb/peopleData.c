/*Hacer una estructura que registre los datos de cinco personas como: Nombre, apellido, edad, sexo y teléfono.*/

#include <stdio.h>
#include <malloc.h>

#define TOTAL_PEOPLE 5
#define MAX_CHARACTERS 30

typedef struct {
    char *name;
    char *surname;
    char sex;
    int age;
    int telNumber;
} Person;

int main() {
    Person *people = (Person *)malloc(TOTAL_PEOPLE * sizeof(Person));

    people->name = (char *) malloc(MAX_CHARACTERS * sizeof(char));
    people->surname = (char *) malloc(MAX_CHARACTERS * sizeof(char));

    Person *pPeople = people;

    printf("Por favor ingrese los datos de las siguientes %i personas.\n", TOTAL_PEOPLE);
    for(int i = 0; i < TOTAL_PEOPLE; i++) {
        printf("Persona %i\n", i);
        printf("\tNombre: ");
        fgets(people->name, MAX_CHARACTERS, stdin);
        printf("\tApellido: ");
        fgets(people->surname, MAX_CHARACTERS, stdin);
        printf("\tEdad: ");
        scanf("%d", &people->age);
        printf("\tSexo [M/F]: ");
        scanf(" %c", &people->sex);
        while((people->sex != 'f' || people->sex != 'F') || (people->sex != 'm' || people->sex != 'M')) {
            printf("Ingrese el sexo correctamente [M/F]: ");
            scanf(" %c", &people->sex);
        }
        printf("\tNumero de telefono: ");
        scanf("%d", &people->telNumber);

        people++;
    }
    people = pPeople;
    printf("Datos ingresados\n");
    for(int i = 0; i < TOTAL_PEOPLE; i++) {
        printf("Persona %i\n", i);
        printf("\tNombre: %s", people->name);
        printf("\tApellido: %s", people->surname);
        printf("\tEdad: %d", people->age);
        printf("\tSexo: %c", people->sex);
        printf("\tNumero de telefono: %d", people->telNumber);

        people++;
    }
    return 0;
}