#include <stdio.h>
#include <malloc.h>
int main() {

	int *pnum = (int*)malloc(10 * sizeof(int));

	printf("Ingrese 10 numeros:\n");

	for(int i = 1; i <= 10; i++) {
		scanf("%d", pnum);
		pnum++;
	}

	printf("Numeros inversos:\n");
	for (int i = 10; i > 0; i--) {
		pnum--;
		printf("%d\n", *pnum);
	}

	free(pnum);
	pnum = NULL;

	return 0;
}
