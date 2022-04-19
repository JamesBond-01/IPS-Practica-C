/*Hacer una estructura que registre los datos de cinco personas como: Nombre, apellido, edad, sexo y teléfono.*/

#include <stdio.h>
#include <malloc.h>

#define TOTAL_PEOPLE 3
#define MAX_CHARACTERS 10

typedef struct person {
    char *name;
    char *surname;
    char sex;
    int age;
    long telNumber;
} Person;

Person *getData();

int main() {
    Person *people;

    printf("Por favor ingrese los datos de las siguientes %i personas.\n", TOTAL_PEOPLE);
    people = getData();


    printf("====================================\n");
    printf("Datos ingresados\n");

    for(int i = 0; i < TOTAL_PEOPLE; i++) {
        printf("Persona %i\n", i + 1);
        printf("\tNombre: %s", people->name);
        printf("\tApellido: %s", people->surname);
        printf("\tEdad: %d\n", people->age);
        printf("\tSexo: %c\n", people->sex);
        printf("\tNumero de telefono: %ld\n", people->telNumber);

        people ++;
    }
    free(people);

    return 0;
}

Person *getData() {
    int c;
    Person *people = (Person *)malloc(TOTAL_PEOPLE * sizeof(Person));
    Person *pPeople = people;

    for(int i = 0; i < TOTAL_PEOPLE; i++) {
        people->name = calloc(MAX_CHARACTERS, sizeof(char));
        people->surname = calloc(MAX_CHARACTERS, sizeof(char));
        printf("Persona %i\n", i + 1);

        printf("\tNombre: ");
        fgets(people->name, MAX_CHARACTERS, stdin);

        printf("\tApellido: ");
        fgets(people->surname, MAX_CHARACTERS, stdin);

        printf("\tEdad: ");
        scanf("%d", &people->age);

        printf("\tSexo [M/F]: ");
        scanf(" %c", &people->sex);
        while((people->sex != 'f' && people->sex != 'F') && (people->sex != 'm' && people->sex != 'M')) {
            printf("Ingrese el sexo correctamente [M/F]: ");
            scanf(" %c", &people->sex);
        }

        printf("\tNumero de telefono: ");
        scanf("%ld", &people->telNumber);

        while ((c = getchar()) != '\n' && c != EOF) { }

        people ++;
    }

    people = pPeople;
    return people;
}