/*En una librería, al no tener más lugar en los estantes, se van acomodando los libros en pilas de hasta 30
libros como máximo. Escribir un programa que permita:
▪ ingresar los ISBN, título y editorial de los libros
▪ listar los últimos 5 libros apilados
▪ eliminar de la pila los libros a medida que se solicitan
▪ detectar cuál es el libro que está en el TOPE*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30


/* Declaracion de tipos de datos personalizados */

typedef char tString[30];

typedef struct {
    int isbn;
    tString titulo;
    tString editorial;
}tLibro;

typedef struct {
    tLibro libros[MAX];
    int tope;
}tPilaLibros;

/* Declaracion de prototipos */

void inicializarPila();
bool pilaVacia(tPilaLibros);
bool pilaLlena(tPilaLibros);
void apilar(tLibro);
void desapilar();
tLibro elemCima(tPilaLibros);
void mostrarPila(tPilaLibros);
void menu();
void agregarLibros();

/* Declaracion de variables globales */

tPilaLibros pila;

/*Bloque Principal*/

int main(){
    menu();    
    return 0;   
}

/* Declaracion de Funciones */

void inicializarPila(){
    pila.tope = -1;
    printf("\nPila inicializada!\n");
}

bool pilaVacia(tPilaLibros pPila){
    return (pPila.tope == -1);
}

bool pilaLlena(tPilaLibros pPila){
    return (pPila.tope == MAX - 1);
}

void apilar(tLibro pLibro){
    
    if (!pilaLlena(pila))
    {
        pila.tope++;
        pila.libros[pila.tope] = pLibro;
        pila.libros[pila.tope].isbn = pLibro.isbn;
        strcpy(pila.libros[pila.tope].titulo, pLibro.titulo);
        strcpy(pila.libros[pila.tope].editorial, pLibro.editorial);
        printf("\nLibro apilado!\n");
    }
    else
    {
        printf("\nPila llena!\n");
    }
    
}

void desapilar(){

    if (!pilaVacia(pila))
    {
        pila.libros[pila.tope].isbn = 0;
        strcpy(pila.libros[pila.tope].titulo, " ");
        strcpy(pila.libros[pila.tope].editorial, " ");
        pila.tope = pila.tope - 1;
        printf("\nLibro desapilado!\n");
    }
    else
    {
        printf("\nPila vacia!\n");
    }
}

tLibro elemCima(tPilaLibros pPila){
    if (!pilaVacia(pPila))
    {
        return pPila.libros[pPila.tope];
    }
    else
    {
        tLibro libro;
        libro.isbn = 0;
        strcpy(libro.titulo, " ");
        strcpy(libro.editorial, " ");
        return libro;
    }
    
}

void mostrarPila(tPilaLibros pPila){
    int i;
    if (!pilaVacia(pila))
    {
        printf("\n\t\t\t\t\t|\t\t\tPila     \t\t\t|\n");
        printf("\t\t\t\t\t|-------------------------------------------------------|\n");

        for (i = 0; i <= pila.tope; i++)
        {
            printf("\t\t\t\t\t|ISBN: %d\t|Titulo: %s\t|Editorial: %s  \t\t|\n", pila.libros[i].isbn, pila.libros[i].titulo, pila.libros[i].editorial);
        }
    }
    else
    {
        printf("\nPila vacia!\n");
    }
}

void menu(){
    int opcion;
    do{
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\tMENU\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t1. Inicializar pila\t\t|\n");
        printf("\t\t\t\t\t|\t2. Agregar Libros\t\t|\n");
        printf("\t\t\t\t\t|\t3. Eliminar Libro\t\t|\n");
        printf("\t\t\t\t\t|\t4. Mostrar Libros\t\t|\n");
        printf("\t\t\t\t\t|\t5. Libro en la cima\t\t|\n");
        printf("\t\t\t\t\t|\t6. Ultimos 5 libros listados\t|\n");
        printf("\t\t\t\t\t|\t0. Salir\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\tIngrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                inicializarPila();
                system("pause");
                system("cls");
                break;
            case 2:
                agregarLibros();
                break;
            case 3:
                desapilar();
                system("pause");
                system("cls");
                break;
            case 4:
                mostrarPila(pila);
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\nLibro en la cima:\t isbn: %d | Titulo: %s | editorial: %s \n", elemCima(pila).isbn, elemCima(pila).titulo, elemCima(pila).editorial);
                system("pause");
                system("cls");
                break;
            case 6:
                listarUltimosLibros();
                system("pause");
                system("cls");
                break;
            case 0:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\n\n\t\t\t\t\t|Opcion no valida!|\n");
                break;
        }
    }while(opcion != 0);
}

void agregarLibros(){
    int i,opcion;
    tLibro libro;

    do
    {
        if (!pilaLlena(pila))
        {
            printf("\nIngrese el ISBN: ");
            scanf("%d", &libro.isbn);
            printf("\nIngrese el titulo: ");
            fflush(stdin);
            scanf("%s", libro.titulo);
            printf("\nIngrese la editorial: ");
            scanf("%s", libro.editorial);
            apilar(libro);
        }else{
            printf("\nPila llena!\n");
        }
        for (i = 0; i <= pila.tope; i++)
        {
            printf("\nISBN: %d\nTitulo: %s\nEditorial: %s\n", pila.libros[i].isbn, pila.libros[i].titulo, pila.libros[i].editorial);
        }
        printf("\nDesea agregar otro libro? (1. Si / 2. No): ");
        fflush(stdin);
        scanf("%d", &opcion);

    } while (opcion == 1);
    system("cls");
    
}


void listarUltimosLibros(){
    int i;
    if (!pilaVacia(pila))
    {
    /*▪ listar los últimos 5 libros apilados*/
        if (pila.tope >= 5)
        {
            printf("\n\t\t\t\t\t|\t\t\tPila     \t\t\t|\n");
            printf("\t\t\t\t\t|-------------------------------------------------------|\n");

            for (i = pila.tope; i >= pila.tope - 4; i--)
            {
                printf("\t\t\t\t\t|ISBN: %d\t|Titulo: %s\t|Editorial: %s  |\n", pila.libros[i].isbn, pila.libros[i].titulo, pila.libros[i].editorial);
            }
        }
        else
        {
            printf("\n\t\t\t\t\t|\t\t\tPila     \t\t\t|\n");
            printf("\t\t\t\t\t|-------------------------------------------------------|\n");
            
            for (i = 0; i <= pila.tope; i++)
            {
                printf("\t\t\t\t\t|ISBN: %d\t|Titulo: %s\t|Editorial: %s  |\n", pila.libros[i].isbn, pila.libros[i].titulo, pila.libros[i].editorial);
            }
        }       
    }
    else
    {
        printf("\nPila vacia!\n");    
    }
    
}
