#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo {
	char *nombre;
	struct nodo *sig;
} Libro;

Libro *listaLibros(Libro *lista) {
	lista = NULL;
	return lista;
}

Libro *agregarLibro(Libro *lista, char *nombre) {
	Libro *nuevoLibro;
	Libro *aux;

	nuevoLibro = (Libro *)malloc(sizeof(Libro));
	nuevoLibro->nombre = nombre;
	nuevoLibro->sig = NULL;

	if(lista == NULL) {
		lista = nuevoLibro;
	} else {
		aux = lista;
		while(aux->sig != NULL) {
			aux = aux->sig;  
		}
		aux->sig = nuevoLibro;
	}

	return lista; 
}



int main() {
	Libro *lista = listaLibros(lista);
	lista = agregarLibro(lista, "Brighton");
	lista = agregarLibro(lista, "Londres");
	lista = agregarLibro(lista, "Edimburgh");
	
	while(lista != NULL) {
		printf("%s\n", lista->nombre);
		lista = lista->sig;
	}
	return 0;
}