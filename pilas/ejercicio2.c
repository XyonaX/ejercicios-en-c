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

typedef int tPilasTv[MAX];
typedef char tPilasMarca[MAX];

typedef struct 
{
    tPilasTv pilaTv;
    tPilasMarca pilaMarca;
    int tope;

}tPilaTv;

/* Declaracion de prototipos*/

void inicializarPila();
bool pilaVacia(tPilaTv);
bool pilaLlena(tPilaTv);
void apilarTv(int, char);
void desapilarTv();
int elemCima(tPilaTv);
void visualizarPila(tPilaTv);
void menu();
void agregarCaja();
void consulta();
char marcaCima(tPilaTv);
/* Declaraci�n de variables */
tPilaTv pila;


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

bool pilaVacia(tPilaTv pPila){
    return (pPila.tope == -1);
}

bool pilaLlena(tPilaTv pPila){
    return (pPila.tope == MAX - 1);
}

void apilarTv(int pPulgadas, char pMarca){
    if(!pilaLlena(pila)){
        pila.tope++;
        pila.pilaTv[pila.tope] = pPulgadas;
        printf("\nCaja agregada!\n");
    }
    else{
        printf("\nPila llena!\n");
    }
}

void desapilarTv(){
    int elemEliminado;
    char marcaEliminado;
    if(!pilaVacia(pila)){
        elemEliminado = elemCima(pila);
        pila.pilaTv[pila.tope] = 0;
        pila.tope--;
        printf("\nCaja retirada!\n");
        printf("\ntelevisor del tope: %d'' \n", elemCima(pila));
    }
    else{
        printf("\nPila vacia!\n");
    }

}

int elemCima(tPilaTv pPila){
    return pPila.pilaTv[pPila.tope];
    
}

char marcaCima(tPilaTv pPila){
    return pPila.pilaMarca[pPila.tope];
}

void visualizarPila(tPilaTv pPila){
    int i;
    if(!pilaVacia(pila)){
        for(i = 0; i <= pila.tope; i++){
            printf("\t\t\t\t\t|%d''  | %s\n", pila.pilaTv[i], (i == pila.tope) ? "<--Tope" : " ");
        }
    }
    else{
        printf("\nPila vacia!\n");
    }
}


void agregarCaja(){
    int pulgadas, opcion, aux = 0;
    char marca[20];
        
    do
    {
        printf("\nIngrese la cantidad de pulgadas: ");
        fflush(stdin);
        scanf("%d", &pulgadas);
        printf("\nIngrese la marca: ");
        fflush(stdin);
        gets(marca);
        fflush(stdin);
        apilarTv(pulgadas, marca);
        aux = pulgadas;
        printf("\nDesea agregar otra caja?\n1. Si\n2. No\n");
        fflush(stdin);
        scanf("%d", &opcion);   
    }while(opcion != 2);    
    
}

void consulta(){
    int pulgadas, i, contador = 0;
    printf("\nIngrese la cantidad de pulgadas: ");
    fflush(stdin);
    scanf("%d", &pulgadas);
    for(i = 0; i <= pila.tope; i++){
        if(pila.pilaTv[i] > pulgadas){
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

