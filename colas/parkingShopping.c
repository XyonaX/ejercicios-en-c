/*En el estacionamiento de un shopping, existe solo un carril en el que entran hasta 20 automóviles. Los
vehículos llegan por el extremo sur del estacionamiento y salen por el extremo norte del mismo. El
empleado de la cochera registra las matrículas que están en el carril. Se solicita escribir un programa que
permita al usuario ingresar las matrículas de los automóviles en una cola hasta que la misma se llene o el
usuario haya decidido no ingresar más elementos (vehículos). Además, se pide generar un listado de todos
los automóviles que están en el carril y se desea saber cuánta disponibilidad hay en ese carril. Utilizar
implementación con frente fijo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20
typedef char tString[9];

typedef tString tMatricula[MAX];

typedef struct {
    tMatricula carril;
    int frente,final;
} tCochera;

void inicializar();
bool cocheraVacia( tCochera );
bool cocheraLlena( tCochera );
void agregar ( tString );
void eliminarElementoFF(); //eleminar frente fijo
void visualizarCochera( tCochera );
void ingresarMatricula();
int carrilesDisponibles ( tCochera );
void menu();


tCochera cochera;


int main () {
    menu();
    return 0;
}

void inicializar(){
    cochera.frente = -1;
    cochera.final = -1;
    printf("\nSe inicializo la cochera\n");
}

bool cocheraVacia( tCochera pCochera ){
    return ( pCochera.frente == -1 && pCochera.final == -1 );
}   //devuelve true si la cola está vacía

bool cocheraLlena( tCochera pCochera){
    return ( pCochera.final == ( MAX - 1) );
}   //devuelve true si la cola está llena

void agregar ( tString pMatricula ){
    if( !cocheraLlena( cochera ) ){
        
        cochera.final++; //actualiza final
        strcpy( cochera.carril[ cochera.final ], pMatricula ); //agrega el elemento al final
        if( cochera.final == 0 ){
            cochera.frente = 0;
        }
    } else {
        printf("\nLa cochera esta llena\n");
    }

    int carrilDisponibles;
    carrilDisponibles = MAX - cochera.final - 1;
    printf("\nCantidad de carriles disponibles: %d\n", carrilDisponibles);    
}
void eliminarElementoFF(){
    tString matricula = " ";
    int i;
    if( !cocheraVacia( cochera ) ){
        strcpy( matricula, cochera.carril[ cochera.frente ] );

        strcpy( cochera.carril[ cochera.frente ], " " );
        
        for( i = cochera.frente; i < cochera.final; i++ ){
            strcpy( cochera.carril[ i ], cochera.carril[ i + 1 ] );
        }
        strcpy( cochera.carril[ cochera.final ], " " );

        
        if( cochera.frente == cochera.final ){
            inicializar();
        }else{
            
            cochera.final--;

        }
        printf("\nSe elimino el vehiculo con la matricula: %s\n", matricula );
    } else {
        printf("\nLa cochera esta vacia\n");
    }
}

void visualizarCochera( tCochera pCochera ){
    int i;
    if( !cocheraVacia( pCochera ) ){
        printf("\nCochera:\n");
        for( i = pCochera.frente; i <= pCochera.final; i++ ){
            printf(" %s |", pCochera.carril[ i ] );
        }
    } else {
        printf("\nLa cochera esta vacia\n");
    }
}

void ingresarMatricula(){
    tString matricula = " ";
    int rts;
    do {
        printf("\nIngrese la matricula: ");
        fflush(stdin);
        scanf("%s", matricula);
        agregar( matricula );

        printf("\nDesea ingresar otra matricula?\n1. Si\n2. No\n");
        fflush(stdin);
        scanf("%d", &rts);
    }while( rts != 2 );
}

int carrilesDisponibles ( tCochera pCochera ){
    int carrilesDisponibles;
    carrilesDisponibles = MAX - ( pCochera.final - pCochera.frente )- 1;
    return printf("\nCantidad de carriles disponibles: %d\n", carrilesDisponibles);
}

void menu(){
    int opcion;
    do{
        printf("\n\t\tMENU\n");
        printf("1. Inicializar cochera\n");
        printf("2. Agregar matricula\n");
        printf("3. Eliminar vehiculo\n");
        printf("4. Visualizar cochera\n");
        printf("5. Carriles Disponibles\n");
        printf("0. Salir\n");
        printf("\nIngrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");
        switch( opcion ){
            case 1:
                inicializar();
                break;
            case 2:
                ingresarMatricula();
                break;
            case 3:
                eliminarElementoFF();
                break;
            case 4:
                visualizarCochera( cochera );
                break;
            case 5:
                carrilesDisponibles( cochera );
                break;
            case 0:
                printf("\nSaliendo del programa\n");
                break;
            default:
                printf("\nOpcion no valida\n");
                break;
        }
    }while ( opcion != 0 );
}