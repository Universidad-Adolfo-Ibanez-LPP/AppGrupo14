void Modificar(FILE *fp, inv *bobi){
    char salto[300];
    fgets(salto, 300, stdin);
    char *nombre, *nombre2, algo[300];
    nombre = (char*)malloc(300*sizeof(char));
    nombre2 = (char*)malloc(300*sizeof(char));
    printf("\nInserte el titulo del libro que desea modificar: ");
    fgets(nombre, 300, stdin);
    nombre = reemplazo_salto(nombre);
    printf("\nIngrese si desea cambiar la sede, seccion o el piso: ");
    scanf("%s", algo);
    if(strcmp(algo, "sede")==0) {
        fgets(salto, 300, stdin);
        printf("\nInserte el nombre de la nueva sede: ");
        fgets(nombre2, 300, stdin);
        nombre2 = reemplazo_salto(nombre2);
        //scanf("%s", nombre2);
        strcpy(bobi[buscar_libro(nombre, bobi)].sede, nombre2);
    }
    else if (strcmp(algo, "seccion")==0) {
        fgets(salto, 300, stdin);
        printf("\nInserte el nombre de la nueva seccion: ");
        fgets(nombre2, 300, stdin);
        nombre2 = reemplazo_salto(nombre2);
        //scanf("%s", nombre2);
        strcpy(bobi[buscar_libro(nombre, bobi)].estante_seccion, nombre2);
    }
    else if (strcmp(algo, "piso")==0) {
        fgets(salto, 300, stdin);
        printf("\nInserte el nombre del nuevo piso: ");
        fgets(nombre2, 300, stdin);
        nombre2 = reemplazo_salto(nombre2);
        //scanf("%s", nombre2);
        strcpy(bobi[buscar_libro(nombre, bobi)].piso, nombre2);
    }
    Escribir(fp, bobi);
}