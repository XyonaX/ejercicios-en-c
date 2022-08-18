/*En el estacionamiento de un shopping, existe solo un carril en el que entran hasta 20 automóviles. Los
vehículos llegan por el extremo sur del estacionamiento y salen por el extremo norte del mismo. El
empleado de la cochera registra algunos datos de los automóviles que están en el carril. Se solicita escribir
un programa que permita al usuario ingresar matrícula, marca y modelo de los automóviles en una cola
hasta que la misma se llene o el usuario haya decidido no ingresar más datos. Además, se pide generar un
listado de todos los vehículos que están en el carril y se desea saber cuánta disponibilidad hay en ese carril.
Utilizar implementación con frente fijo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

/* Declaracion de tipos de datos personalizados*/

typedef char tString[9];

typedef struct 
{
    tString matricula;
    tString marca;
    int modelo;
}tAutos;

typedef struct 
{
    tAutos autos[MAX];
    int frente, final;
}tColaAutos;

/* Declaracion de prototipos*/

void inicializarCola();
bool colaVacia(tColaAutos);
bool colaLlena(tColaAutos);
void agregarAuto(tAutos);
void eliminarAuto();
tAutos autoFinal(tColaAutos);
void visualizarCola(tColaAutos);
void ingresarAuto();
void menu();

/* Declaracion de variables globales */
tColaAutos cola;

/* Bloque principal */

int main(){

    menu();
    return 0;
}

/* Declaracion de funciones */

void inicializarCola(){
    cola.frente = -1;
    cola.final = -1;
    printf("\nCola inicializada!\n");
}

bool colaVacia(tColaAutos cola){
    return (cola.frente == -1 && cola.final == -1);
}

bool colaLlena(tColaAutos cola){
    return (cola.final == MAX - 1);
}

void agregarAuto(tAutos pAuto){
    if(!colaLlena(cola)){
        cola.final++;
        cola.autos[cola.final] = pAuto;
        if (cola.final == 0){
            cola.frente = 0;
        }
        printf("\nAuto agregado!\n");
        
    }else{
        printf("\nCola llena!\n");
    }
}

void eliminarAuto(){
    //frente fijo
    int i;
    if (!colaVacia(cola))
    {
        strcpy(cola.autos[cola.frente].matricula, " ");
        strcpy(cola.autos[cola.frente].marca, " ");
        cola.autos[cola.frente].modelo = 0;
    }
    
}