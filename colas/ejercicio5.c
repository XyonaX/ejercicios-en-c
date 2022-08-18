/*En una clínica la secretaria hace un listado con los nombres y apellidos de los pacientes que van llegando
para luego ser atendidos en ese orden, también agenda el tipo de cobertura (1-obra social 2-pre-paga 3-
particular). El médico atiende un máximo de 20 pacientes por día. Se solicita: generar un listado de todos
los pacientes que van a ser atendidos en el día, conocer si hay turnos disponibles, y realizar una función
para borrar de la lista los pacientes a medida que son atendidos (utilizar la implementación con frente
móvil).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

/* Declaracion de tipos de datos personalizados*/

typedef char tString[30];

typedef struct {
    tString nombre;
    tString apellido;
    int cobertura;
}tPaciente;

typedef struct {
    tPaciente paciente[MAX];
    int frente, final;
}tColaPacientes;

/* Declaracion de prototipos*/

void inicializarCola();
bool colaVacia(tColaPacientes);
bool colaLlena(tColaPacientes);
void agregarPaciente(tPaciente);
void eliminarPaciente();
tPaciente pacienteFinal(tColaPacientes);
void visualizarCola(tColaPacientes);
void borrarCola();
void ingresarPaciente();
void menu();
tPaciente pacienteFinal(tColaPacientes);
void turnosDisponibles(tColaPacientes);

/* Declaracion de variables globales */
tColaPacientes cola;

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

bool colaVacia(tColaPacientes pCola){
    return (pCola.frente == -1);
}

bool colaLlena(tColaPacientes pCola){
    return (pCola.final == MAX - 1);
}

tPaciente pacienteFinal(tColaPacientes pCola){
    return pCola.paciente[cola.final];
}

void agregarPaciente(tPaciente pPaciente){
    if (!colaLlena(cola))
    {
        cola.final++;
        cola.paciente[cola.final] = pPaciente;
        // cola.paciente[cola.final].cobertura = pPaciente.cobertura;
        // strcpy(cola.paciente[cola.final].nombre, pPaciente.nombre);
        // strcpy(cola.paciente[cola.final].apellido, pPaciente.apellido);
        if (cola.final == 0)
        {
            cola.frente = 0;
        }
        
        printf("\nPaciente agregado!\n");
        printf("\nPaciente agregado: %s %s %d\n", pacienteFinal(cola).nombre, pacienteFinal(cola).apellido, pacienteFinal(cola).cobertura);
    }else{
        printf("\nCola llena!\n");
    }
}

void eliminarPaciente(){
    //frente movil
    
    if(!colaVacia(cola)){
        borrarCola();
        if (cola.frente == cola.final)
        {
            cola.frente = -1;
            cola.final = -1;
        }
        else
        {
            cola.frente++;
        }
        printf("\nPaciente eliminado!\n");
    }
}

void borrarCola(){
    tString paciente;
    strcpy(paciente, cola.paciente[cola.frente].nombre);
    strcat(paciente, " ");
    strcat(paciente, cola.paciente[cola.frente].apellido);
    strcpy(cola.paciente[cola.frente].nombre, "");
    strcpy(cola.paciente[cola.frente].apellido, "");
}

void visualizarCola(tColaPacientes pCola){
    int i;
    if (!colaVacia(pCola))
    {
        printf("\n\t\t\t\t|Pacientes en la cola   |\n");
        printf("\t\t\t\t|-----------------------|\n");
        for (i = pCola.frente; i <= pCola.final; i++)
        {
            printf("\t\t\t\t|%s %s %d \t|\n", pCola.paciente[i].nombre, pCola.paciente[i].apellido, pCola.paciente[i].cobertura);
        }
        
        
    }
}

void ingresarPaciente(){
    tPaciente paciente;
    int opcion;

    do
    {
        printf("\nIngrese el Apellido del paciente: ");
        fflush(stdin);
        gets(paciente.apellido);
        printf("\nIngrese el Nombre del paciente: ");
        fflush(stdin);
        gets(paciente.nombre);
        printf("\nIngrese la cobertura del paciente (1-obra social 2-pre-paga 3-particular): ");
        scanf("%d", &paciente.cobertura);
        agregarPaciente(paciente);
        printf("\nDesea ingresar otro paciente? (1-si 2-no): ");
        scanf("%d", &opcion);
    } while (opcion == 1);
    
}

void turnosDisponibles(tColaPacientes pCola){

    int turnosDisponibles = MAX - (pCola.final - pCola.frente) - 1;
    printf("\nTurnos disponibles: %d\n", turnosDisponibles);
}

void menu(){
    int opcion;

    do
    {
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\t  MENU\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t1. Inicializar cola\t\t|\n");
        printf("\t\t\t\t\t|\t2. Agregar Paciente\t\t|\n");
        printf("\t\t\t\t\t|\t3. Eliminar Paciente\t\t|\n");
        printf("\t\t\t\t\t|\t4. Visualizar Cola\t\t|\n");
        printf("\t\t\t\t\t|\t5. Consultar turnos disponibles\t|\n");
        printf("\t\t\t\t\t|\t0. Salir\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\tIngrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch (opcion)
                       
        {   
            case 1:
                inicializarCola();
                system("pause");
                break;
            case 2:
                ingresarPaciente();
                break;
            case 3:
                eliminarPaciente();
                system("pause");
                break;
            case 4:
                visualizarCola( cola );
                system("pause");
                break;
            case 5:
                turnosDisponibles(cola);
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


