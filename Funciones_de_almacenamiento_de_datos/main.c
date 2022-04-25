#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void condicional(int k, char *tok, int i, inv *bobi);
void guardar_csv(FILE *fp, int contador, inv *bobi);
int regulador(int li, int ls);
void ignoreRestOfLine(FILE* fp);
char *reemplazo_salto(char *name);


void condicional(int k, char *tok, int i, inv *bobi){
    if (k == 1) {
        bobi[i].autor = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].autor, tok);
    }
    else if (k == 2) {
        bobi[i].anio = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].anio, tok);
    }
    else if (k == 3) {
        bobi[i].estante_numero = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].estante_numero, tok);
    }
    else if (k == 4) {
        bobi[i].estante_seccion = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].estante_seccion, tok);
    }
    else if (k == 5) {
        bobi[i].piso = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].piso, tok);
    }
    else if (k == 6) {
        bobi[i].edificio = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].edificio, tok);
    }
    else if(k==7){
        bobi[i].sede = (char *) malloc((strlen(tok) + 1) * sizeof(char));
        strcpy(bobi[i].sede, tok);
    }
}

void guardar_csv(FILE *fp, int contador, inv *bobi){
    char *tok, aux[200], tokk[200];
    char buff[300];
    int j, k = 1;
    for(int i = 0; i < contador; i++){
        fgets(buff, 300, fp);
        bobi[i].logic = 0;
        if(buff[0] != '"') {
            tok = strtok(buff, ",");
            strcpy(tokk, tok);
            bobi[i].titulo = (char *) malloc((strlen(tokk) + 1) * sizeof(char));
            strcpy(bobi[i].titulo, tokk);
            while (tok != NULL) {
                tok = strtok(NULL, ",");
                condicional(k, tok, i, bobi);
                k = k + 1;
            }
            k = 1;
        }
        else{
            tok = strtok(buff, ",");
            strcat(strcpy(aux, tok), ",");
            strcpy(tokk, aux);
            j = 0;
            while (j < 1) {
                tok = strtok(NULL, ",");
                strcat(tokk, tok);
                j = j + 1;
            }
            bobi[i].titulo = (char *) malloc((strlen(tokk) + 1) * sizeof(char));
            strcpy(bobi[i].titulo, tokk);
            while (tok != NULL) {
                tok = strtok(NULL, ",");
                condicional(k, tok, i, bobi);
                k = k + 1;
            }
            k = 1;
        }
    }
    rewind(fp);
}
int regulador(int li,int ls){

    int conta = 0;
    scanf("%i",&conta);
    while (conta < li || conta > ls)
    {
        printf("Ingresaste mal el comando\n");
        printf("\nIngrese un comando: ");
        ignoreRestOfLine(stdin);
        scanf("%i\a",&conta);
    }
    return conta;
}
void ignoreRestOfLine(FILE* fp)
{
    int c;
    while ( (c = fgetc(fp)) != EOF && c != '\n');
}
char *reemplazo_salto(char *name){
    char *nombre;
    nombre = (char*)malloc(300*sizeof(char));
    strcpy(nombre, name);
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
    return nombre;
}