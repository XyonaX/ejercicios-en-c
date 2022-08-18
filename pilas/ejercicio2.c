/*En un depósito se ubican las cajas de televisores LED en pilas de hasta 20 como máximo, no se puede
apilar una caja grande sobre otra más chica. Escribir un programa que permita:
▪ ingresar y almacenar el dato compuesto referido a las pulgadas y a la marca de los distintos televisores,
según se van apilando
▪ obtener un listado de todos los televisores apilados
▪ una consulta que a partir del ingreso de un valor x de pulgadas retorne la cantidad de televisores con
más de x pulgadas que se encuentran apilados
▪ conforme se vayan retirando las cajas, detectar las pulgadas y la marca del televisor que queda en el
tope*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

/* Declaracion de tipos de datos personalizados*/

typedef char tString[30];

typedef struct 
{
    int pulgadas;
    tString marca;
}tTelevisor;

typedef struct 
{
    tTelevisor televisores[MAX];
    int tope;

}tPilaTelevisores;



/* Declaracion de prototipos*/

void inicializarPila();
bool pilaVacia(tPilaTelevisores);
bool pilaLlena(tPilaTelevisores);
void apilarTv(tTelevisor);
void desapilarTv();
tTelevisor elemCima(tPilaTelevisores);
void visualizarPila(tPilaTelevisores);
void menu();
void agregarCaja();
void consulta();
char marcaCima(tPilaTelevisores);
/* Declaraci�n de variables */
tPilaTelevisores pila;


/* Bloque principal */
int main (){

    menu();
    return 0;
}

/* Declaracion de funciones */

void inicializarPila(){
    pila.tope = -1;
    printf("\nPila inicializada!\n");
}

bool pilaVacia(tPilaTelevisores pPila){
    return (pPila.tope == -1);
}

bool pilaLlena(tPilaTelevisores pPila){
    return (pPila.tope == MAX - 1);
}

void apilarTv(tTelevisor pTelevisor){
    if(!pilaLlena(pila)){
        pila.tope++;
        pila.televisores[pila.tope] = pTelevisor;
        pila.televisores[pila.tope].pulgadas = pTelevisor.pulgadas;
        strcpy(pila.televisores[pila.tope].marca, pTelevisor.marca);
        printf("\nCaja agregada!\n");
    }
    else{
        printf("\nPila llena!\n");
    }
}

void desapilarTv(){
    int elemEliminado;
    if(!pilaVacia(pila)){
        pila.televisores[elemEliminado].pulgadas = 0;
        strcpy(pila.televisores[elemEliminado].marca, " ");
        pila.tope--;
        printf("\nCaja retirada!\n");
        printf("\ntelevisor en el tope: %d'' %s\n", elemCima(pila).pulgadas, elemCima(pila).marca);
    }
    else{
        printf("\nPila vacia!\n");
    }

}

tTelevisor elemCima(tPilaTelevisores pPila){
    return pPila.televisores[pPila.tope];
}


void visualizarPila(tPilaTelevisores pPila){
    int i;
    if(!pilaVacia(pila)){
        printf("\n\t\t\t\t\t|\tPila     \t|\n");
        printf("\t\t\t\t\t|-----------------------|\n");
        for(i = 0; i <= pila.tope; i++){
            printf("\t\t\t\t\t|%d'' | %s\t\t|\n", pila.televisores[i].pulgadas, pila.televisores[i].marca,(i == pila.tope) ? "<--Tope" : " ");
                        
        }
    }
    else{
        printf("\nPila vacia!\n");
    }
}


void agregarCaja(){
    tTelevisor caja;
    int opcion;
    
    do
    {
        printf("\nIngrese la cantidad de pulgadas de la caja: ");
        scanf("%d", &caja.pulgadas);
        if (caja.pulgadas > elemCima(pila).pulgadas && !pilaVacia(pila))
        {
            printf("\nLa caja no puede ser agregada, porque es mayor a la caja que esta en el tope\n");
            system("pause");
        }
        else
        {
            printf("\nIngrese la marca de la caja: ");
            fflush(stdin);
            scanf("%s", caja.marca);
            apilarTv(caja);
            printf("\nDesea agregar otra caja?\n1. Si\n2. No\n");
            scanf("%d", &opcion);
        }
    
        
    } while (opcion == 1);
    
    
    
}

void consulta(){
    int pulgadas, i, contador = 0;
    printf("\nIngrese la cantidad de pulgadas: ");
    fflush(stdin);
    scanf("%d", &pulgadas);
    for(i = 0; i <= pila.tope; i++){
        if(pila.televisores[i].pulgadas > pulgadas){
            contador++;
        }
    }
    printf("\nCantidad de cajas con mas de %d pulgadas: %d\n", pulgadas, contador);
}

void menu(){
    int opcion;

    do
    {
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\t\tMENU\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t1. Inicializar pila\t\t|\n");
        printf("\t\t\t\t\t|\t2. Agregar Caja\t\t\t|\n");
        printf("\t\t\t\t\t|\t3. Eliminar Caja\t\t|\n");
        printf("\t\t\t\t\t|\t4. Mostrar Pila\t\t\t|\n");
        printf("\t\t\t\t\t|\t5. Consulta\t\t\t|\n");
        printf("\t\t\t\t\t|\t6. Elemento en la cima\t\t|\n");
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
                agregarCaja();
                break;
            
            case 3:
                desapilarTv();
                system("pause");
                break;
            
            case 4:
                visualizarPila( pila );
                system("pause");
                break;
        
            case 5:
                consulta();
                system("pause");
                break;
            case 6:
                printf("\nEl elemento en la cima es la tv de %d''\n", elemCima(pila));
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