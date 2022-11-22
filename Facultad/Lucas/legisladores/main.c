#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void inserta(char mandato, char *nombre);
char *suprime_principio(char mandato);
//char *suprime_miembro(char mandato, char *nombre);
char *suprime_ultimo(char mandato);
bool miembro(char mandato, const char *nombre);
bool isEmpty(char mandato);
void mostrar(char mandato);
struct node {
    char mandato;
    char *nombre;
    struct node *link;
};
struct node *headBuenos = NULL;
struct node *headMalos = NULL;

int main() {
    char mandato, input;
    int menu;
    char *nombre = malloc(10 * sizeof(char));
    do {
//        system("cls");
        printf("Por favor, ingrese una opcion.\n");
        printf("\t1.Agregar un legislador.\n");
        printf("\t2.Suprimir un legislador.\n");
        printf("\t3.Buscar un legislador.\n");
        printf("\t4.Mostrar legisladores.\n");
        printf("\t >>> ");
        scanf("%d", &menu);
        getchar();
        switch (menu) {
            case 1:
                do {
                    printf("\t\tNombre del legislador (Max. 10 letras): ");
                    fgets(nombre, 10, stdin);
                    do {
                        printf("\t\tMandato[F/D]: ");
                        scanf(" %c", &mandato);
                        getchar();
                        mandato = tolower(mandato);
                    } while (mandato != 'f' && mandato != 'd');
                    inserta(mandato, nombre);
                    printf("\t\tDesea agregar legislador a la lista? [Y/N]: ");
                    scanf(" %c", &input);
                    getchar();
                    input = tolower(input);
                } while (input != 'n');
                break;
            case 2:
                do {
                    printf("\t\tEn que conjunto se encuentra su legislador? [F/D]: ");
                    scanf(" %c", &mandato);
                    getchar();
                } while (mandato != 'f' && mandato != 'd');
                printf("\t\tSeleccione una opcion.\n");
                printf("\t\t\t1.Eliminar el primer legislador de la lista.\n");
                printf("\t\t\t2.Eliminar un legislador especifico.\n");
                printf("\t\t\t3.Eliminar el ultimo legislador de la lista.\n");
                printf("\t\t\t >>> ");
                scanf("%d", &menu);
                getchar();
                switch (menu) {
                    case 1:
                        printf("\t\t\tLegislador %s eliminado con exito.\n", suprime_principio(mandato));
                        break;
                    case 2:
                        printf("\t\t\tIngrese el nombre del legislador que desee eliminar: ");
                        fgets(nombre, 10, stdin);
//                    printf("Legislador %s eliminado con exito.\n", suprime_miembro(mandato, nombre));
                        break;
                    case 3:
                        printf("\t\t\tLegislador %s eliminado con exito.\n", suprime_ultimo(mandato));
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                do {
                    printf("\t\tEn que conjunto se encuentra su legislador? [F/D]: ");
                    scanf(" %c", &mandato);
                    getchar();
                    mandato = tolower(mandato);
                } while (mandato != 'f' && mandato != 'd');
                printf("\tIngrese el nombre del legislador que desee buscar: ");
                fgets(nombre, 10, stdin);
                if(miembro(mandato, nombre)) {
                    printf("%s es un miembro del conjunto ", nombre);

                } else {
                    printf("%s no es un miembro del conjunto", nombre);
                }
                if(mandato == 'f') {
                    printf(" chicos buenos.\n");
                } else {
                    printf(" chicos malos.\n");
                }
                break;
            case 4:
                do {
                    printf("\t\tSeleccione la lista de legisladores a mostrar [F/D]: ");
                    scanf(" %c", &mandato);
                    getchar();
                    mandato = tolower(mandato);
                } while (mandato != 'f' && mandato != 'd');
                mostrar(mandato);
                break;
            default:
                break;
        }
        printf("Desea realizar otra operacion? ('e' para salir): ");
        scanf(" %c", &input);
        getchar();
        input = tolower(input);
    } while(input != 'e');
    return 0;
}
void inserta(char mandato, char *nombre) {
    if(mandato == 'f') {
        struct node *newBuenos = malloc(sizeof(struct node));
        newBuenos->nombre = malloc(strlen(nombre) * sizeof(char));
        struct node *ptrBuenos = headBuenos;
        if(newBuenos == NULL) {
            printf("Error al agregar un miembro a la lista.\n");
            return;
        }
        newBuenos->mandato = mandato;
        newBuenos->nombre = nombre;
        newBuenos->link = NULL;
        if(isEmpty(mandato)) {
            headBuenos = newBuenos;
            return;
        }
        while(ptrBuenos->link != NULL) {
            ptrBuenos = ptrBuenos->link;
        }
        ptrBuenos->link = newBuenos;
    } else {
        struct node *newMalos = malloc(sizeof(struct node));
        newMalos->nombre = malloc(strlen(nombre) * sizeof(char));
        struct node *ptrMalos = headMalos;
        if (newMalos == NULL) {
            printf("Error al agregar un miembro a la lista.\n");
            return;
        }
        newMalos->mandato = mandato;
        newMalos->nombre = nombre;
        newMalos->link = NULL;
        if (isEmpty(mandato)) {
            headBuenos = newMalos;
            return;
        }
        while (ptrMalos->link != NULL) {
            ptrMalos = ptrMalos->link;
        }
        ptrMalos->link = newMalos;
    }
}

char *suprime_principio(char mandato) {
    if(mandato == 'f') {
        if(isEmpty(mandato)) {
            printf("Error al eliminar un miembro. Lista vacia.\n");
            exit(1);
        }
        struct node *tmp = headBuenos;
        char *name = headBuenos->nombre;
        headBuenos = headBuenos->link;
        free(tmp);
        tmp = NULL;
        return name;
    } else {
        if(isEmpty(mandato)) {
            printf("Error al eliminar un miembro. Lista vacia.\n");
            exit(1);
        }
        struct node *tmp = headMalos;
        char *name = headMalos->nombre;
        headMalos = headMalos->link;
        free(tmp);
        tmp = NULL;
        return name;
    }
}
//char *suprime_miembro(char mandato, char *nombre) {
//    if(mandato == 'f') {
//        struct node *ptr = headBuenos;
//        if (isEmpty(mandato)) {
//            printf("Error al eliminar un elemento. Lista vacia.\n");
//            exit(1);
//        }
//        while (ptr->nombre != nombre) {
//            if (ptr->link->link == NULL) {
//                if (ptr->link == NULL) {
//                    headBuenos = NULL;
//                }
//                char *name = ptr->link->nombre;
//                ptr->link = NULL;
//                free(ptr->link);
//                return name;
//            }
//            ptr = ptr->link;
//        }
//        char *name = ptr->link->nombre;
//        struct node *tmp = ptr->link;
//        ptr->link = ptr->link->link;
//        free(tmp);
//        tmp = NULL;
//        return name;
//    } else {
//        struct node *ptr = headMalos;
//        if(isEmpty(mandato)) {
//            printf("Error al eliminar un elemento. Lista vacia.\n");
//            exit(1);
//        }
//        while (ptr->nombre != nombre) {
//            if (ptr->link->link == NULL) {
//                if (ptr->link == NULL) {
//                    headMalos = NULL;
//                }
//                char *name = ptr->link->nombre;
//                ptr->link = NULL;
//                free(ptr->link);
//                return name;
//            }
//            ptr = ptr->link;
//        }
//        char *name = ptr->link->nombre;
//        struct node *tmp = ptr->link;
//        ptr->link = ptr->link->link;
//        free(tmp);
//        tmp = NULL;
//        return name;
//    }
//}
char *suprime_ultimo(char mandato) {
    if(mandato == 'f') {
        struct node *ptrBuenos = headBuenos;
        if(isEmpty(mandato)) {
            printf("Error al eliminar un miembro. Lista vacia.\n");
            exit(1);
        }
        while(ptrBuenos->link->link != NULL) {
            ptrBuenos = ptrBuenos->link;
        }
        char *name = headBuenos->nombre;
        free(ptrBuenos->link);
        ptrBuenos->link = NULL;
        return name;
    } else {
        struct node *ptrMalos = headMalos;
        if(isEmpty(mandato)) {
            printf("Error al eliminar un miembro. Lista vacia.\n");
            exit(1);
        }
        while(ptrMalos->link->link != NULL) {
            ptrMalos = ptrMalos->link;
        }
        char *name = headMalos->nombre;
        free(ptrMalos->link);
        ptrMalos->link = NULL;
        return name;
    }
}
bool miembro(char mandato, const char *nombre) {
    if(mandato == 'f') {
        struct node *tmp = headBuenos;
        if (isEmpty(mandato)) {
            printf("La lista esta vacia.\n");
            return false;
        }
        while(tmp->nombre != nombre) {
            tmp = tmp->link;
            if(tmp == NULL) {
                return false;
            }
        }
        return true;
    } else {
        struct node *tmp = headMalos;
        if (isEmpty(mandato)) {
            printf("La lista esta vacia.\n");
            return false;
        }
        while(tmp->nombre != nombre) {
            tmp = tmp->link;
            if(tmp == NULL) {
                return false;
            }
        }
        return true;
    }
}

bool isEmpty(char mandato) {
    if(mandato == 'f') {
        if(headBuenos == NULL) {
            return true;
        }
        return false;
    } else {
        if(headMalos == NULL) {
            return true;
        }
        return false;
    }
}
void mostrar(char mandato) {
    if(mandato == 'f') {
        struct node *tmp = headBuenos;
        if (isEmpty(mandato)) {
            printf("La lista esta vacia.\n");
            return;
        }
        while(tmp) {
            printf("%c - %s\n", tmp->mandato, tmp->nombre);
            tmp = tmp->link;
        }
    } else {
        struct node *tmp = headMalos;
        if(isEmpty(mandato)) {
            printf("La lista esta vacia.\n");
            return;
        }
        while(tmp) {
            printf("%c - %s\n", tmp->mandato, tmp->nombre);
            tmp = tmp->link;
        }
    }
}
