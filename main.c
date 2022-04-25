#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ "r"
#define ESC "w"
#define SOBRE_ESC "a"

struct Invent{
    int logic;
    char *titulo;
    char *autor;
    char *anio;
    char *estante_numero;
    char *estante_seccion;
    char *piso;
    char *edificio;
    char *sede;
};

typedef struct Invent inv;

int contador_gral = 0;

FILE * openingFile(char *filename, char *modo){
    FILE *fp;
    fp = fopen(filename,modo);
    if(fp==NULL){
        printf("Problem\n");
        exit(-1);
    }
    return fp;
}

void guardar_csv(FILE *fp, int contador, inv *bobi);
void condicional(int k, char *tok, int i, inv *bobi);
int contar_lineas(FILE *fp);
void Insertar_Libro(FILE *fp, inv *bobi);
//void Printeannding(inv *bob); #Funcion para visualizar como se comporta el csv
void Escribir(FILE *fp, inv *bobi);
int buscar_libro(char *name, inv *bobi);
void Eliminar_Libro(FILE *fp, inv *bobi);
int regulador(int li,int ls);
void ignoreRestOfLine(FILE* fp);
void Modificar(FILE *fp, inv *bobi);
char *reemplazo_salto(char *name);
void datos_libro(inv *bobi);



int main(int argc, char *argv[]){
    //Lee el csv y guarda los datos en arreglo inv bobi
    FILE *fp = openingFile(argv[1], READ);
    int contador = contar_lineas(fp);
    contador_gral = contador;
    inv *bobi;
    bobi = (inv*)malloc((contador+100)*sizeof(inv));
    guardar_csv(fp, contador, bobi);
    fclose(fp);
    //=================
    fp = openingFile(argv[1], SOBRE_ESC);
    int salir = 0;
    int conta = 0;
    int olib = 1;

    const char *csv = argv[1];  //NOMBRE DEL ARCHIVO

    printf("\nBienvenidos");

    while (salir == 0)/*Menu*/{
        printf("\n\nPágina principal\n\n->Libros[1]\n->Biblioteca[2]\n->Salir[3]\n\nINGRESE UN COMANDO: ");
        conta =regulador(1,3);

        if (conta == 1)/*Libros*/{
            printf("\nLIBROS\n\n->Agregar[1]\n->Quitar[2]\n->Buscar libro[3]\n->Editar[4]\n\nINGRESE UN COMANDO: ");
            conta = regulador(1,4);

            if (conta == 1)/*Insertar libro*/{
                fp = openingFile(argv[1], ESC);
                Insertar_Libro(fp, bobi);
                Escribir(fp, bobi);
                //Printeannding(bobi);
                fclose(fp);
                printf("\n*Se ha agregado un libro\n");
            }
            if (conta == 2)/*Quitar libro*/{
                fp = openingFile(argv[1], ESC);
                Eliminar_Libro(fp, bobi);
                //Printeannding(bobi);
                fclose(fp);
                printf("\n*Se ha quitado un libro\n");
            }
            if (conta== 3)/*Buscar libro*/{
                fp = openingFile(argv[1], ESC);
                datos_libro(bobi);
                //Printeannding(bobi);
                fclose(fp);

            }
            if (conta== 4)/*Editar libro*/{
                fp = openingFile(argv[1], ESC);
                Modificar(fp, bobi);
                //Printeannding(bobi);
                fclose(fp);
                printf("\n*Se ha editado el libro\n");

            }
            conta = 0;
        }
        if (conta == 2)/*BIBLIOTECA*/{
            printf("\n Error 404 ");
            printf("\nIngrese un 1 para volver: ");
            conta = regulador(1,3);
            conta = 0;
        }

        if (conta == 3)/*SALIR*/{
            printf("\nFin del programa\n");
            salir = 1;
        }
    }
    return 0;
    printf("%d", contador_gral);
    return 0;


}
