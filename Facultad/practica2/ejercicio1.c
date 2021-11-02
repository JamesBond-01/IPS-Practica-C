#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

typedef struct tiempo{
	int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {
	char *nombre;
	Tiempo ultima_mod;
} Archivo;

void dateCreator(Tiempo *t1, Tiempo *t2);

int compara_tiempos(Tiempo *t1, Tiempo * t2);

void listGen(Archivo *lista, int i, int n);

void showList(Archivo *lista, int i);

void swap(char **string1, char **string2);

void ordena_alfa(Archivo * lista, int n);

void ordena_temporal(Archivo * lista, int n);


int main() {
	Tiempo t1, t2;
	Archivo *lista;
	Archivo *pArchivo;
	int n, menu, orden;
	char restart;

	srand(time(0));

	do {

		printf("\nIngrese:\n\t1- Para realizar una comparacion entre 2 fechas.\n\t2- Para ordenar una lista de archivos.\n\t> ");
		scanf("%d", &menu);

		if(menu == 1) {
			printf("\nA continuacion se le pediran varios datos basados en el tiempo.\nGracias por su paciencia.\n");
			printf("\nPor favor, introduzca la siguiente informacion:\n");

			dateCreator(&t1, &t2);

			printf("El resultado es %d.\n", compara_tiempos(&t1, &t2));

		} else if (menu == 2) {
			printf("\nIngrese la cantidad de archivos que desee cargar en la lista: ");
			scanf("%d", &n);
			getchar();

			lista = (Archivo *)malloc(n * sizeof(Archivo));
			pArchivo = lista;

			for(int i = 1; i <= n; i++) {
				listGen(lista, i, n);
				*lista ++;
			}

			lista = pArchivo;

			printf("\nIngrese:\n\t1- Para mostrar los archivos en orden default.\n\t2- Para ordenar los archivos en orden alfabetico.\n\t3- Para ordenar los archivos segun su ultima fecha de modificacion.\n\t> ");
			scanf("%d", &orden);

			if(orden == 1) {
				printf("\nArchivos en orden default:\n");
				for(int i = 1; i <= n; i++) {
					showList(lista, i);
					*lista ++;
				}

			} else if(orden == 2) {
				ordena_alfa(lista, n);

			} else if(orden == 3) {
				ordena_temporal(lista, n);

			} else {
				exit(EXIT_FAILURE);
			}

			lista = pArchivo;

			free(lista);
			lista = NULL;

		} else {
			printf("\nValor incorrecto. Vuelva a ejecutar el programa.\n");
			exit(EXIT_FAILURE);
		}

	printf("\nDesea reintentar? [y/n] : ");
	scanf(" %c", &restart);
	getchar();

	} while (restart == 'y' || restart == 'Y');

	return 0;
}

/**
 * Esta funcion toma datos detallados sobre una fecha ingresados por el usuario.
 * También se verificará de que el usaurio haya ingresado los datos de manera correcta.
 *
 * Luego de que el usuario carga todos los datos, se muestra con un formato especifico
 * para un mejor orden de los mismos.
 *
 * @param Tiempo *t1, Tiempo *t2: Pasaje por referencia a variables del tipo Tiempo.
 */
void dateCreator(Tiempo *t1, Tiempo *t2) {
	//Tomo los datos de la primer fecha.
	printf("\n===============================");
	printf("\n\t\tTiempo 1\n");
	printf("===============================\n");

	printf("\n\t\t\tAño: ");
	scanf("%d", &t1->anio);

	printf("\t\t\tMes: ");
	scanf("%d", &t1->mes);

	while((t1->mes < 1) || (t1->mes > 12)) {
		printf("\t\t\tIngrese un mes correcto: ");
		scanf("%d", &t1->mes);
	}

	printf("\t\t\tDia: ");
	scanf("%d", &t1->dia);

	while((t1->dia < 1) || (t1->dia > 31)) {
		printf("\t\t\tIngrese un dia correcto: ");
		scanf("%d", &t1->dia);
	}

	printf("\n\t\t\tHora (formato 24hs): ");
	scanf("%d", &t1->hora);

	while(t1->hora > 24) {
		printf("\t\t\tIngrese un horario correcto: ");
		scanf("%d", &t1->hora);
	}

	printf("\t\t\tMinuto: ");
	scanf("%d", &t1->minuto);

	while(t1->minuto > 59) {
		printf("\t\t\tIngrese minutos correctos: ");
		scanf("%d", &t1->minuto);
	}

	printf("\t\t\tSegundo: ");
	scanf("%d", &t1->segundo);

	while(t1->segundo > 59) {
		printf("\t\t\tIngrese segundos correctos: ");
		scanf("%d", &t1->segundo);
	}

	//Tomo los datos de la segunda fecha.
	printf("===============================\n");
	printf("\n\t\tTiempo 2\n");
	printf("===============================\n");

	printf("\n\t\t\tAño: ");
	scanf("%d", &t2->anio);

	printf("\t\t\tMes: ");
	scanf("%d", &t2->mes);

	while((t2->mes < 1) || (t2->mes > 12)) {
		printf("\t\t\tIngrese un mes correcto: ");
		scanf("%d", &t2->mes);
	}

	printf("\t\t\tDia: ");
	scanf("%d", &t2->dia);

	while((t2->dia < 1) || (t2->dia > 31)) {
		printf("\t\t\tIngrese un dia correcto: ");
		scanf("%d", &t2->dia);
	}

	printf("\t\t\tHora (formato 24hs): ");
	scanf("%d", &t2->hora);

	while(t2->hora > 24) {
		printf("\t\t\tIngrese un horario correcto: ");
		scanf("%d", &t2->hora);
	}

	printf("\t\t\tMinuto: ");
	scanf("%d", &t2->minuto);

	while(t2->minuto > 59) {
		printf("\t\t\tIngrese minutos correctos: ");
		scanf("%d", &t2->minuto);
	}

	printf("\t\t\tSegundo: ");
	scanf("%d", &t2->segundo);

	while(t2->segundo > 59) {
		printf("\t\t\tIngrese segundos correctos: ");
		scanf("%d", &t2->segundo);
	}

	// Muestro las dos fechas ingresadas de forma ordenada para que pueda ser leída fácilmente.
	printf("\n========================================================");
	printf("\nFecha 1 (YY/MM/DD):  %d/%d/%d - %d:%d:%d\n", t1->anio, t1->mes, t1->dia, t1->hora, t1->minuto, t1->segundo);
	printf("\nFecha 2 (YY/MM/DD):  %d/%d/%d - %d:%d:%d\n", t2->anio, t2->mes, t2->dia, t2->hora, t2->minuto, t2->segundo);
	printf("\n========================================================");
}

/**
 * Esta funcion compara las 2 fechas ingresadas por el usuario.
 *
 * @param Tiempo *t1, Tiempo *t2: Pasaje por referencia a variables del tipo Tiempo.
 *
 * @return 1 si *t1 es anterior a *t2
 * @return 0 si *t1 es igual a *t2
 * @return -1 si *t1 es posterior a *t2
 */

int compara_tiempos(Tiempo *t1, Tiempo *t2) {
	if(t1->anio == t2->anio) {
		if(t1->mes == t2->mes) {
			if(t1->dia == t2->dia) {
				if(t1->hora == t2->hora) {
					if(t1->minuto == t2->minuto) {
						if(t1->segundo == t2->segundo) {
							printf("\nFecha 1 es igual a fecha 2.\n");
							return 0;
						}
						else if(t1->segundo > t2->segundo) {
							printf("\nFecha 1 es posterior a Fecha 2.\n");
							return -1;
						}
						else if(t1->segundo < t2->segundo) {
							printf("\nFecha 1 es anterior a Fecha 2.\n");
							return 1;
						}
					}
					else if(t1->minuto > t2->minuto) {
						printf("\nFecha 1 es posterior a Fecha 2.\n");
						return -1;
					}
					else if(t1->minuto < t2->minuto) {
						printf("\nFecha 1 es anterior a Fecha 2.\n");
						return 1;
					}
				}
				else if(t1->hora > t2->hora) {
					printf("\nFecha 1 es posterior a Fecha 2.\n");
					return -1;
				}
				else if(t1->hora < t2->hora) {
					printf("\nFecha 1 es anterior a Fecha 2.\n");
					return 1;
				}
			}
			else if(t1->dia > t2->dia) {
				printf("\nFecha 1 es posterior a Fecha 2.\n");
				return -1;
			}
			else if(t1->dia < t2->dia) {
				printf("\nFecha 1 es anterior a Fecha 2.\n");
				return 1;
			}
		}
		else if(t1->mes > t2->mes) {
			printf("\nFecha 1 es posterior a Fecha 2.\n");
			return -1;
		}
		else if(t1->mes < t2->mes) {
			printf("\nFecha 1 es anterior a Fecha 2.\n");
			return 1;
		}
	}
	else if(t1->anio > t2->anio) {
		printf("\nFecha 1 es posterior a Fecha 2.\n");
		return -1;
	}
	else if(t1->anio < t2->anio) {
		printf("\nFecha 1 es anterior a Fecha 2.\n");
		return 1;
	}

}


void listGen(Archivo *lista, int i, int n) {

	lista->nombre = (char *)malloc((n * 10) * sizeof(char));

	printf("Ingrese nombre del archivo %d: ", i);
	fgets(lista->nombre,10,stdin);

	lista->ultima_mod.anio = 2000 + (rand() % 22);
	lista->ultima_mod.mes = 1 + (rand() % 12);
	lista->ultima_mod.dia = 1 + (rand() % 30);
	lista->ultima_mod.hora = rand() % 24;
	lista->ultima_mod.minuto = rand() % 60;
	lista->ultima_mod.segundo = rand() % 60;

}

void showList(Archivo *lista, int i) {
	printf("\nNombre del archivo %d: %s - Ultima modificacion: (YY/MM/DD): %d/%d/%d - %d:%d:%d\n", i, lista->nombre, lista->ultima_mod.anio, lista->ultima_mod.mes,
	lista->ultima_mod.dia, lista->ultima_mod.hora, lista->ultima_mod.minuto, lista->ultima_mod.segundo);
}


void swap(char **string1, char **string2) {
	char *tmp;

	tmp = *string2;
	*string2 = *string1;
	*string1 = tmp;
}


void ordena_alfa(Archivo *lista, int n) {
	int compare, disorder;
	char *string1;
	char *string2;
	char *tmp;
	Archivo *pA_Lista;

	pA_Lista = lista;

	do {
		disorder = 0;

		for(int i = 1; i < n; i++) {

			string1 = lista->nombre;
			*lista ++;
			string2 = lista->nombre;

			compare = strcmp(string1, string2);

			if(compare > 0) {
				//swap(&string1, &string2);

				tmp = string2;
				string2 = string1;
				string1 = tmp;

				disorder = 1;
			}
		}

		lista = pA_Lista;

	} while(disorder == 1);

	printf("\nLista ordenada:\n");

	lista = pA_Lista;

	for(int i = 1; i <= n; i++) {
		showList(lista, i);
		*lista ++;
	}
}

void ordena_temporal(Archivo *lista, int n) {

}
