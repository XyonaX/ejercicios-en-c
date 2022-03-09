// En  un  depósito  se  ubican  las  cajas  de  televisores  LED  en  pilas  de  hasta  20  como  máximo,  no  se  puede 
// apilar una caja grande sobre otra más chica. Escribir un programa que permita: 
// ▪ ingresar y almacenar el dato referido a las pulgadas de los distintos televisores, según se van apilando.  
// ▪ obtener un listado de todos los televisores apilados 
// ▪ una consulta que a partir del ingreso de un valor x de pulgadas retorne la cantidad de televisores con 
// más de x pulgadas que se encuentran apilados 
// ▪ conforme se vayan retirando las cajas, detectar las pulgadas del televisor que queda en el tope.  
#include <stdio.h>
#include <stdbool.h>
#define MAX 5
/* Declaraci�n de tipos de datos personalizados */

typedef  int tPilasTv[MAX];

typedef struct 
{
    tPilasTv pilaTv;
    int tope;
}tTvPila;


/* Declaraci�n de prototipos */
void inicializarPila();
bool pilaVacia(tTvPila);
bool pilaLlena(tTvPila);
void apilarTv(int);
void desapilarTv();
int elemCima(tTvPila);
void visualizarPila(tTvPila);
void menu();
void agregarCaja();

/* Declaraci�n de variables */
tTvPila pila;


/* Bloque principal */
int main (){

    menu();

}


/* Implementaci�n de funciones */

void inicializarPila(){
    pila.tope = -1;
    printf("\nSe Inicializo la pila...\n\n");
}
bool pilaVacia(tTvPila pTv){
    return (pTv.tope == -1);
    
}
bool pilaLlena(tTvPila pTv){
    return(pTv.tope == MAX-1);
}
void apilarTv(int pElem){
    if (!pilaLlena(pila))
    {
        pila.tope = pila.tope + 1; 
        pila.pilaTv[pila.tope] = pElem;
        printf("\nEl elemento insertado\n\n");
    }
    else
    {
        printf("\nLa pila esta llena!\n\n");
    }
}
void desapilarTv(){
    int elemAEliminar;
    if (!pilaVacia(pila))
    {
        elemAEliminar = elemCima(pila);
        pila.pilaTv[pila.tope] = 0;
        pila.tope = pila.tope -1;
        printf("\nSe retiro de la pila la TV de %ipulgadas\n\n", elemAEliminar);
        printf("\nEl elemento en la cima es la TV de %ipulgadas\n\n", elemCima(pila));
    }
    else
    {
        printf("\nNo hay TV para retirar de la pila");
    }
    
    
}
void agregarCaja(){
    int pulgadas, opcion;
    do
    {
        printf("\nIngrese las pulgadas de la TV: ");
        fflush(stdin);
        scanf("%d",&pulgadas);
        apilarTv(pulgadas);

        printf("\nDesea seguir ingresando TV ?    1=[SI] 0=[NO]\n");
        printf("Su Opcion es: ");
        fflush(stdin);
        scanf("%d",&opcion);
    } while (opcion == 1);
    fflush(stdin);
    
}

int elemCima(tTvPila pTv){
    return pTv.pilaTv[pTv.tope];
}

void visualizarPila(tTvPila pTv){
    if (!pilaVacia(pila))
    {
        for (int i = 0; i <= pTv.tope; i++)
        {
            printf("%dpulgadas | ", pTv.pilaTv[i]);
        }
        
    }else
    {
        printf("\nNo existen elementos para visualizar...\n\n");
    }
    
}

void menu (){
    int opcion;
    do
    {
        printf("\n*** Opciones disponibles ***\n");	
        printf("1- Inicializar la pila de TV\n");
        printf("2- Ingresar una caja\n");
        printf("3- Sacar una caja\n");
        printf("4- Mostrar cantidad de elementos\n");	
        printf("5- Mostrar elemento de la cima\n");	
        printf("0- Salir\n");        
        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%i",&opcion);
        switch (opcion)
        {
        case 1:
            inicializarPila(); 
            break;
        case 2:
            agregarCaja(); 
            break;
        case 3:
            desapilarTv(); 
            break;
        case 4:
            visualizarPila(pila); 
            break;
        case 5:
            elemCima(pila); 
            break;
        
        default:
            printf("\nHasta la Proxima");
            break;
        }
    } while (opcion !=  0);
    
}