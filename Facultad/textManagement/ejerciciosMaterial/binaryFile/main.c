#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 150

typedef struct record {
    char *name, *surname;
} Record;

void separateName(const char *singleLine, char *name, int lineLength);
void separateSurname(const char *singleLine, char *surname, int lineLength);
int main() {
    FILE *fPointer = fopen("familia.txt", "r");
    FILE *fPointer2 = fopen("copia_familia.bin", "wb");
    Record *dataRecord = (Record *)malloc(10 * sizeof(Record));
    Record *pDataRecord = dataRecord;
    char *singleLine = (char *)malloc(BUF_SIZE * sizeof(char));
    int totalLines = 0, writeCheck, readCheck;

    if((fPointer == NULL) || (fPointer2 == NULL)) {
        printf("Error al abrir el/los archivos\n");
        exit(-1);
    }
    while(!feof(fPointer)) {
        dataRecord->name = (char *)malloc(BUF_SIZE * sizeof(char));
        dataRecord->surname = (char *)malloc(BUF_SIZE * sizeof(char));

        fgets(singleLine, BUF_SIZE, fPointer);
        separateName(singleLine, dataRecord->name, (int)strlen(singleLine));
        separateSurname(singleLine, dataRecord->surname, (int) strlen(singleLine));
        writeCheck = (int)fwrite(dataRecord, sizeof(Record), 1, fPointer2);
        if(writeCheck != 1) {
            printf("Error al escribir en el archivo binario.\n");
            exit(-1);
        }
        totalLines ++;
        dataRecord ++;
    }
    dataRecord = pDataRecord;
    fclose(fPointer2);
    fPointer2 = fopen("copia_familia.bin", "rb");

    for(int i = 0; i < totalLines; i++) {
        readCheck = (int)fread(dataRecord, sizeof(Record), 1, fPointer2);
        if(readCheck != 1) {
            printf("Error al leer en el archivo binario.\n");
            exit(-1);
        }
        printf("%s %s\n", dataRecord->name, dataRecord->surname);
        dataRecord ++;
    }
    free(singleLine);
    fclose(fPointer);
    fclose(fPointer2);

    return 0;
}

void separateName(const char *singleLine, char *name, int lineLength) {
    for(int i = 0; i < lineLength; i++) {
        if(singleLine[i] == ' ') {
            for(int k = 0; k < i; k++) {
                name[k] = singleLine[k];
            }
            break;
        }
    }
}
void separateSurname(const char *singleLine, char *surname, int lineLength) {
    for(int i = lineLength - 1; i >= 0; i--) {
        if(singleLine[i] == ' ') {
            int j = 0;
            if(singleLine[lineLength] == '\n') {
                for(int k = i + 1; k < lineLength; k++) {
                    surname[j] = singleLine[k];
                    j++;
                }
            } else {
                for(int k = i + 1; k <= lineLength; k++) {
                    surname[j] = singleLine[k];
                    j++;
                }
            }
            break;
        }
    }
}