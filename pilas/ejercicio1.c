/*En un gimnasio se apilan discos con pesos diferentes en forma desordenada. Los pesos de los discos varían
de 10 a 100 Kg., con un máximo de 12 discos en la pila. Se pide diseñar un programa que disponga de un
menú para invocar las funciones que permitan:
▪ cargar la pila con los pesos de los discos
▪ listar los pesos de los discos apilados
▪ a medida que cada gimnasta quita un disco, este debe ser eliminado de la pila
▪ detectar cuál es el disco que se encuentra en el tope
▪ mostrar la cantidad de discos apilados
▪ calcular el promedio de pesos de los discos que tiene la pila.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 12

/* Declaracion de tipos de datos personalizados */

typedef float tPilasPesas[MAX];

typedef struct 
{
    tPilasPesas pilaDiscos;
    int tope;
}tPilaDisco;

/* Declaracion de prototipos */

void inicializarPila();
bool pilaVacia(tPilaDisco);
bool pilaLlena(tPilaDisco);
void apilar(float);
void desapilar();
float elemCima(tPilaDisco);
void mostrarPila(tPilaDisco);
float promedioPesos(tPilaDisco);
void menu();
void agregarDiscos();

/* Declaracion de variables globales */

tPilaDisco pila;

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

bool pilaVacia(tPilaDisco pPila){
    return (pPila.tope == -1);
}

bool pilaLlena(tPilaDisco pPila){
    return (pPila.tope == MAX - 1);
}

void apilar(float pPeso){
    float peso = pPeso;
    if(!pilaLlena(pila))
    {
        pila.tope = pila.tope + 1;
        pila.pilaDiscos[pila.tope] = peso;
        printf("\nDisco de %.2fkg apilado!\n", peso);
    }
    else{
        printf("\nPila llena!\n");
    }
}

void desapilar(){
    float elemEliminado;
    if(!pilaVacia(pila)){
        elemEliminado = elemCima(pila);
        pila.pilaDiscos[pila.tope] = 0;
        pila.tope--;
        printf("\nDisco de %.2fkg desapilado!\n", elemEliminado);

    }
    else{
        printf("\nNo hay discos para desapilar!\n");
    }

}

float elemCima(tPilaDisco pPila){
    return pPila.pilaDiscos[pPila.tope];
}

void mostrarPila(tPilaDisco pPila){
    if (!pilaVacia(pila)){
        printf("\n\t\t\t\t\t|Pila     |\n");
        printf("\t\t\t\t\t|---------|\n");
        for(int i = 0; i <= pPila.tope; i++)
        {
            printf("\t\t\t\t\t|%.2fkg  | %s\n", pPila.pilaDiscos[i], (i == pPila.tope) ? "<---Tope" : "");
        }

        //invertir pila
        // for(int i = pPila.tope; i >= 0; i--)
        // {
        //     printf("\t\t\t\t\t|%.2fkg  | %s\n", pPila.pilaDiscos[i], (i == pPila.tope) ? "<---Tope" : "");
        // }

    }
    else{
        printf("\nPila vacia!\n");
    }


    system("pause");
}

float promedioPesos(tPilaDisco pPila){
    int i;
    float prom = 0;
    if(!pilaVacia(pila)){
        for(i = 0; i <= pPila.tope; i++){
            prom = prom + pPila.pilaDiscos[i];
        }
        return prom / (pPila.tope + 1);
            
    }
    else{
        printf("\nPila vacia!\n");
    }
    
}

void agregarDiscos(){
    float peso;
    int opcion;

    do
    {
        printf("\nIngrese el peso del disco: ");
        fflush(stdin);
        scanf("%f", &peso);
        apilar(peso);

        printf("\nDesea agregar otro disco?\n1. Si\n2. No\n");
        fflush(stdin);
        scanf("%d", &opcion);

    } while (opcion == 1);
    fflush(stdin);
}



void menu(){

    int opcion;

    do
    {
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\t\tMENU\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t1. Inicializar pila\t\t|\n");
        printf("\t\t\t\t\t|\t2. Agregar Discos\t\t|\n");
        printf("\t\t\t\t\t|\t3. Eliminar Disco\t\t|\n");
        printf("\t\t\t\t\t|\t4. Mostrar Pila\t\t\t|\n");
        printf("\t\t\t\t\t|\t5. Promedio Pesos\t\t|\n");
        printf("\t\t\t\t\t|\t6. Elemento en la cima\t\t|\n");
        printf("\t\t\t\t\t|\t7. Cantidad de pesas apiladas\t|\n");
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
                break;
            case 2:
                agregarDiscos();
                break;
            
            case 3:
                desapilar();
                system("pause");
                break;
            
            case 4:
                mostrarPila( pila );
                break;
        
            case 5:
                printf("\nEl promedio de pesos es: %.2fkg\n", promedioPesos(pila));
                system("pause");
                break;
            case 6:
                printf("\nEl elemento en la cima es: %.2fkg\n", elemCima(pila));
                system("pause");
                break;
            case 7:
                printf("\nCantidad de discos apilados: %d\n", (pila.tope == -1) ? 0 : pila.tope + 1);
                system("pause");
                break;
            case 0:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpcion no valida!\n");
                break;
        }
        system("cls");
    } while (opcion != 0);
    
}