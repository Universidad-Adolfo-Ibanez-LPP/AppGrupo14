


    void Eliminar_Libro(FILE *fp, inv *bobi){
        char *nombre;
        nombre = (char*)malloc(300*sizeof(char));
        printf("\nInserte el titulo del libro que desea eliminar: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        if(buscar_libro(nombre, bobi) == 0){
            printf("\nNo existe un libro con ese nombre\n");
        }
        else{
            bobi[buscar_libro(nombre, bobi)].logic = 1;
        }
        Escribir(fp, bobi);
    }


    void Insertar_Libro(FILE *fp, inv *bobi){
        char *nombre;
        char *nombre1;
        nombre = (char*)malloc(300*sizeof(char));
        bobi[contador_gral].logic = 0;
        //Pide el titulo
        printf("Inserte el titulo del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].titulo = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].titulo, nombre);
        //Pide el autor
        printf("Inserte el autor del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].autor = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].autor, nombre);
        //Pide el año
        printf("Inserte el anio del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].anio = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].anio, nombre);
        //Pide en numero de estante
        printf("Inserte el numero de estante del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].estante_numero = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].estante_numero, nombre);
        //Pide seccion de estante
        printf("Inserte la seccion del estante del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].estante_seccion = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].estante_seccion, nombre);
        //Pide piso
        printf("Inserte el piso del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].piso = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].piso, nombre);
        //Pide edificio
        printf("Inserte el edificio del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].edificio = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].edificio, nombre);
        //Pide sede
        printf("Inserte la sede del libro que desea agregar a la biblioteca: ");
        fgets(nombre, 300, stdin);
        nombre = reemplazo_salto(nombre);
        bobi[contador_gral].sede = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(bobi[contador_gral].sede, nombre);
        contador_gral += 1;
    }
}
