#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAXLB 132
#define MAXLIBROS 44

// ESTRUCTURAS
struct Libro {
    char autor[20];
    char titulo[20];
    int codigo;
    char fecha[20];
};

struct Librerias {
    struct Libro lib1[MAXLIBROS];
    struct Libro lib2[MAXLIBROS];
    struct Libro lib3[MAXLIBROS];
};

// PROTOTIPOS
struct Libro Ingresar() {
    struct Libro lib;
    system("cls");
    printf("Ingreso de Libros\n");
    printf("===================\n\n");
    printf("Ingrese codigo: ");
    fflush(stdin);
    scanf("%d", &lib.codigo);
    printf("Ingrese titulo: ");
    fflush(stdin);
    scanf("%s", lib.titulo);
    printf("Ingrese autor:   ");
    fflush(stdin);
    scanf("%s", lib.autor);
    printf("Ingrese fecha:   ");
    fflush(stdin);
    scanf("%s", lib.fecha);
    return lib;
}

int ValidarEspacio(int espacio) {
    return espacio >= 1 && espacio <= MAXLIBROS;
}

struct Librerias Posicionar(struct Librerias libr) {
    int opcion = 0, opcion2 = 0;
    system("cls");
    printf("¿En que libreria desea ingresarlo?\n");
    printf("1. Libreria 1\n");
    printf("2. Libreria 2\n");
    printf("3. Libreria 3\n");
    fflush(stdin);
    scanf("%d", &opcion);
    if (opcion >= 1 && opcion <= 3) {
        do {
            printf("En que espacio de la Libreria %d? (1-%d): ", opcion, MAXLIBROS);
            fflush(stdin);
            scanf("%d", &opcion2);
            if (!ValidarEspacio(opcion2)) {
                printf("Espacio no valido\n", MAXLIBROS);
            }
        } while (!ValidarEspacio(opcion2));
        switch (opcion) {
            case 1:
                libr.lib1[opcion2 - 1] = Ingresar();
                break;
            case 2:
                libr.lib2[opcion2 - 1] = Ingresar();
                break;
            case 3:
                libr.lib3[opcion2 - 1] = Ingresar();
                break;
        }
    } else {
        printf("Opcion invalida.\n");
    }
    return libr;
}
void Listar(struct Librerias libr, int numLibros) {
    int opcion;
    struct Libro lib;
    system("cls");
    printf("Listado de Libros\n");
    printf("===================\n");
    printf("De que libreria desea listar los libros?\n");
    printf("1. Libreria 1\n");
    printf("2. Libreria 2\n");
    printf("3. Libreria 3\n");
    fflush(stdin);
    scanf("%d", &opcion);
    if (opcion >= 1 && opcion <= 3) {
        int librosEncontrados = 0;
        switch (opcion) {
            case 1:
                printf("Libros en Libreria 1:\n");
                for (int i = 0; i < MAXLIBROS; i++) {
                    lib = libr.lib1[i];
                    if (lib.codigo != 0) {
                        librosEncontrados++;
                        printf("Datos del libro en posicion %d:\n", i + 1);
                        printf("Codigo: %d\n", lib.codigo);
                        printf("Autor: %s\n", lib.autor);
                        printf("Titulo: %s\n", lib.titulo);
                        printf("Fecha: %s\n", lib.fecha);
                        printf("===================\n");
                    }
                }
                break;
            case 2:
                printf("Libros en Libreria 2:\n");
                for (int i = 0; i < MAXLIBROS; i++) {
                    lib = libr.lib2[i];
                    if (lib.codigo != 0) {
                        librosEncontrados++;
                        printf("Datos del libro en posicion %d:\n", i + 1);
                        printf("Codigo: %d\n", lib.codigo);
                        printf("Autor: %s\n", lib.autor);
                        printf("Titulo: %s\n", lib.titulo);
                        printf("Fecha: %s\n", lib.fecha);
                        printf("===================\n");
                    }
                }
                break;
            case 3:
                printf("Libros en Libreria 3:\n");
                for (int i = 0; i < MAXLIBROS; i++) {
                    lib = libr.lib3[i];
                    if (lib.codigo != 0) {
                        librosEncontrados++;
                        printf("Datos del libro en posicion %d:\n", i + 1);
                        printf("Codigo: %d\n", lib.codigo);
                        printf("Autor: %s\n", lib.autor);
                        printf("Titulo: %s\n", lib.titulo);
                        printf("Fecha: %s\n", lib.fecha);
                        printf("===================\n");
                    }
                }
                break;
        }
        if (librosEncontrados == 0) {
            printf("No hay ningun libro en esta libreria.\n");
        }
    } else {
        printf("Opción invalida.\n");
    }
}
void Modificar(struct Librerias *libr, int numLibros) {
    int opcion, posicion = -1;
    struct Libro lib;
    system("cls");
    printf("Modificacion de Libros\n");
    printf("=======================\n");
    printf("En qué libreria se encuentra el libro que quiere modificar?\n");
    printf("1. Libreria 1\n");
    printf("2. Libreria 2\n");
    printf("3. Libreria 3\n");
    fflush(stdin);
    scanf("%d", &opcion);
    if (opcion >= 1 && opcion <= 3) {
        printf("En que espacio de la Libreria %d? (1-%d): ", opcion, MAXLIBROS);
        fflush(stdin);
        scanf("%d", &posicion);
        switch (opcion) {
            case 1:
                lib = (*libr).lib1[posicion - 1];
                break;
            case 2:
                lib = (*libr).lib2[posicion - 1];
                break;
            case 3:
                lib = (*libr).lib3[posicion - 1];
                break;
        }
        if (lib.codigo != 0) {
            printf("Datos del libro seleccionado:\n");
            printf("Codigo: %d\n", lib.codigo);
            printf("Autor: %s\n", lib.autor);
            printf("Titulo: %s\n", lib.titulo);
            printf("Fecha: %s\n", lib.fecha);
            printf("Ingrese nuevo titulo: ");
            fflush(stdin);
            scanf("%s", lib.titulo);
            printf("Ingrese nuevo autor:   ");
            fflush(stdin);
            scanf("%s", lib.autor);
            printf("Ingrese nueva fecha:   ");
            fflush(stdin);
            scanf("%s", lib.fecha);
            switch (opcion) {
                case 1:
                    (*libr).lib1[posicion - 1] = lib;
                    break;
                case 2:
                    (*libr).lib2[posicion - 1] = lib;
                    break;
                case 3:
                    (*libr).lib3[posicion - 1] = lib;
                    break;
            }
            printf("Libro modificado correctamente, presione cualquier tecla para volver\n");
        } else {
            printf("No hay ningun libro en la posicion seleccionada.\n");
        }
    } else {
        printf("Opcion invalida.\n");
    }
}

int main() {
    int opcion = 0, numLibros = 0;
    struct Libro lista[MAXLB];
    struct Librerias libr;
    
    for (int i = 0; i < MAXLIBROS; i++) {
        libr.lib1[i].codigo = 0;
        libr.lib2[i].codigo = 0;
        libr.lib3[i].codigo = 0;
    }

    do {
        system("cls");
        printf("------MENU-LIBRERIA------\n");
        printf("1. Ingresar libro\n");
        printf("2. Modificar libro\n");
        printf("3. Lista de los libros actuales\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numLibros < MAXLB) {
                    libr = Posicionar(libr);
                    numLibros++;
                    printf("Datos de los libros ingresados\n\n");
                } else {
                    printf("No puede ingresar más libros.\n");
                }
                break;
            case 2:
                Modificar(&libr, numLibros);
                break;
            case 3:
                Listar(libr, numLibros);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida, presione cualquier tecla para reintentar.\n");
                break;
        }
        fflush(stdin);
        getch();
    } while (opcion != 4);

    return 0;
}

