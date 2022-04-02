/*En una clínica la secretaria hace un listado con los nombres y apellidos de los pacientes que van llegando
para luego ser atendidos en ese orden. El médico atiende un máximo de 20 pacientes por día. Se solicita:
generar un listado de todos los pacientes que van a ser atendidos en el día, conocer si hay turnos
disponibles, y realizar una función para borrar de la lista los pacientes a medida que son atendidos (utilizar
la implementación con frente móvil).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20
typedef char tString[50];

typedef tString tPacientes[MAX];

typedef struct {
    tPacientes pacientes;
    int frente,final;
} tCola;

void inicializar();
bool colaVacia( tCola );
bool colaLlena( tCola );
void agregar( tString );
void eliminarElementoFF(); //eleminar frente fijo
void eliminarElementoFM(); //eleminar frente movil
void mostrarPrimerPaciente( tCola );
void visualizarCola( tCola );
void turnosDisponibles( tCola );
void menu();


tCola cola;


int main(){
    menu();    
    return 0;
}

void inicializar(){
    cola.frente = -1;
    cola.final = -1;
    printf("\nSe inicializo la cola\n");
}

bool colaVacia( tCola pCola ){
    return ( pCola.frente == -1 && pCola.final == -1 );
}   //devuelve true si la cola está vacía

bool colaLlena( tCola pCola){
    return ( pCola.final == ( MAX - 1) );
}   //devuelve true si la cola está llena   

void agregar( tString pPaciente ){
    if( !colaLlena( cola ) ){
        
        cola.final++; //actualiza final
        strcpy( cola.pacientes[ cola.final ], pPaciente ); //agrega el elemento al final
        if( cola.final == 0 ){
            cola.frente = 0;
        }
        printf("\nSe agrego el paciente: %s", pPaciente ); //muestra el paciente agregado   
    }else
    {
        printf( "La cola está llena\n" );
    }

    int turnosDisponibles = MAX - ( cola.final - cola.frente ) - 1 ;
    printf("\nHay %d turnos disponibles\n", turnosDisponibles );
}

void eliminarElementoFM(){
    tString elemento = " ";
    if( colaVacia( cola ) ){
        printf("La cola está vacía\n");
    }else{

        //resguardar el elemento por eliminar
        strcpy( elemento, cola.pacientes[ cola.frente ] );

        //Borrar el elemento que se encuentra en el frente
        strcpy( cola.pacientes[ cola.frente ], " " );

        //Verificar si la cola tiene un solo elemento y actualizar indices
        if( cola.frente == cola.final ){
            cola.frente = -1;
            cola.final = -1;

        }else{
            cola.frente++;
        }   
    printf("\nSe elimino el paciente: %s", elemento );
    }
}
void mostrarPrimerPaciente( tCola pPaciente ){
    if( colaVacia( pPaciente ) ){
        printf("\nLa cola está vacía\n");
    }else{
        printf("\nEl primer paciente es: %s\n", pPaciente.pacientes[ pPaciente.frente ] );
    }
}
void visualizarCola( tCola pPaciente ){
    int i;
    if( colaVacia( pPaciente ) ){
        printf("\nLa cola está vacía\n");
    }else{
        printf("\nLos pacientes son:\n");
        for( i = pPaciente.frente; i <= pPaciente.final; i++ ){
            printf("%s\n", pPaciente.pacientes[ i ] );
        }
    }
}

void ingresarPacientes(){
    tString paciente;
    int rts;
    do {
        printf("\nIngrese el nombre del paciente: ");
        fflush(stdin);
        scanf("%s", paciente);
        agregar( paciente );


        printf("\nDesea ingresar otro paciente?\n1.Si 2.No :  ");
        scanf("%d",&rts);
    }while(rts == 1);
}

void turnosDisponibles( tCola pCola){
    //conocer si hay turnos disponibles
    int turnosDisponibles = MAX - ( pCola.final - pCola.frente ) - 1 ;
    printf("\nHay %d turnos disponibles\n", turnosDisponibles );
}

void eliminarElementoFF(){
    tString elemento = " ";
    int i;
    if( colaVacia( cola ) ){
        printf("La cola está vacía\n");
    }
    else
    {
        //resguardar el elemento por eliminar
        strcpy( elemento, cola.pacientes[ cola.frente ] );

        //Borrar el elemento que se encuentra en el frente
        strcpy( cola.pacientes[ cola.frente ], " " );

        //reacomodar la lista
        for( i = cola.frente; i < cola.final; i++ ){
            strcpy(cola.pacientes[i] , cola.pacientes[i+1]);
        }
        //borrar el valor duplicado del final
        strcpy( cola.pacientes[ cola.final ], " " );

        //Verificar si la cola tiene un solo elemento y actualizar indices
        if( cola.frente == cola.final ){
            inicializar();

        }else{
            cola.final--;
        }   
        printf("\nSe elimino el paciente: %s", elemento );
    }
}

void menu(){
    int opc;
    do{
        printf("\n\n\t\tMENU\n");
        printf("1. Inicializar cola\n");
        printf("2. Ingresar pacientes\n");
        printf("3. Eliminar pacientes\n");
        printf("4. Mostrar primer paciente\n");
        printf("5. Visualizar cola\n");
        printf("6. Turnos disponibles\n");
        printf("7. Eliminar paciente frente fijo\n");
        printf("0. Salir\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opc);
        system("cls");
        switch(opc){
            case 1:
                inicializar();
                break;
            case 2:
                ingresarPacientes();
                break;
            case 3:
                eliminarElementoFM();
                break;
            case 4:
                mostrarPrimerPaciente( cola );
                break;
            case 5:
                visualizarCola( cola );
                break;
            case 6: 
                turnosDisponibles( cola );
                break;
            case 7: 
                eliminarElementoFF();
                break;
            case 0:
                printf("\nSaliendo del programa\n");
                break;
            default:
                printf("\nOpcion no valida\n");
                break;
        }
    }while(opc != 0);
}