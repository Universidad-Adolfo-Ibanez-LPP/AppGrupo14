#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Escribir(FILE *fp, inv *bobi){
    for(int i = 0; i < contador_gral; i++){
        if(bobi[i].logic == 0){
            fprintf(fp, "%s, %s, %s, %s, %s, %s, %s, %s", bobi[i].titulo, bobi[i].autor, bobi[i].anio,
                    bobi[i].estante_numero, bobi[i].estante_seccion, bobi[i].piso, bobi[i].edificio, bobi[i].sede);
        }
    }
}

int buscar_libro(char *name, inv *bobi){
    for(int i = 0; i < contador_gral; i++){
        if(strcmp(name, bobi[i].titulo)==0){
            return i;
        }
    }
    return 0;
}

void datos_libro(inv *bobi){
    char salto[300];
    fgets(salto, 300, stdin);
    char *nombre, *nombre2, algo[300];
    nombre = (char*)malloc(300*sizeof(char));
    printf("\nIngrese nombre de libro a buscar: ");
    fgets(nombre, 300, stdin);
    nombre = reemplazo_salto(nombre);
    printf("\n El libro tiene la siguiente informacion: ");
    printf("\nTitulo: %s", bobi[buscar_libro(nombre, bobi)].titulo);
    printf("\nAutor: %s", bobi[buscar_libro(nombre, bobi)].autor);
    printf("\nAño: %s", bobi[buscar_libro(nombre, bobi)].anio);
    printf("\nNumero de estante: %s", bobi[buscar_libro(nombre, bobi)].estante_numero);
    printf("\nSeccion de estante: %s", bobi[buscar_libro(nombre, bobi)].estante_seccion);
    printf("\nPiso: %s", bobi[buscar_libro(nombre, bobi)].piso);
    printf("\nEdificio: %s", bobi[buscar_libro(nombre, bobi)].edificio);
    printf("\nSede: %s", bobi[buscar_libro(nombre, bobi)].sede);
}


