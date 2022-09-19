/*La registración a un evento de informática se realiza a través de la inscripción online mediante un
formulario web. Para ello se registran los datos de los inscriptos en una pila con los siguientes datos: DNI,
Nombre y Apellido, e-mail, Código de Categoría (01-Estudiantes 02-Profesionales 03-Público en general)
y Monto Abonado. El valor de la inscripción es de $200 para los estudiantes y $350 para profesionales y el
público en general, valor que se abona al momento de la inscripción (tener en cuenta esto al momento de
apilar inscriptos). Realizar las funciones necesarias para obtener:
a) la cantidad de Profesionales que se inscribieron al evento, y el porcentaje que representan sobre
el total de inscriptos
b) el monto recaudado de inscriptos de la categoría Estudiantes
c) el total recaudado en concepto de inscripciones*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char tString[30];

typedef struct 
{
    int DNI;
    tString nombYapellido;
    tString email;
    tString codCate;

}tDatos;

typedef struct nodo
{
    tDatos datos;
    struct nodo * siguiente;

}tPila;

void inicializarPila();
bool pilaVacia(tPila *);
void apilarInscriptos(tDatos );
void quitarInscripto();
void visualizarInscriptos(tPila *);
int cantProfesionales(tPila *);
float porcentajeProfesionales(tPila *);
float totalRecaudado(tPila *);
float montoRecaudadoEstudiantes(tPila *);
void menu();

tPila * pila;

int main(){
    tDatos inscriptos;
    inicializarPila();

    
    inscriptos.DNI = 41442040;
    strcpy(inscriptos.nombYapellido, "Vargas Jonatan");
    fflush(stdin);
    strcpy(inscriptos.email, "jonatan.vargasportillo@gmail.com");
    fflush(stdin);
    strcpy(inscriptos.codCate, "Estudiante");
    fflush(stdin);

    apilarInscriptos(inscriptos);

    visualizarInscriptos(pila);

    return 0;
}

void inicializarPila(){
    pila = NULL;
    printf("\nPila inicializada\n");
}

bool pilaVacia(tPila * pPila){
    return pPila == NULL;
}

void apilarInscriptos(tDatos pDatos){
    tPila * nuevoNodo;

    nuevoNodo = (tPila *) malloc(sizeof(tPila));

    nuevoNodo->datos = pDatos;

    nuevoNodo->siguiente = pila;

    pila = nuevoNodo;

    printf("\nInscripto inserdato en la pila");

}

void quitarInscripto(){
    tPila * nodoSuprimir = pila;

    if (!pilaVacia(pila))
    {
        pila = pila->siguiente;

        printf("\nInscripto eliminado: %s \n", nodoSuprimir->datos.nombYapellido);

        free(nodoSuprimir);

        nodoSuprimir = NULL;
    }else{
        printf("\nNo hay inscriptos para quitar de la pila");
    }
}

void visualizarInscriptos(tPila * pPila){
    tPila *aux = pPila;

    if (!pilaVacia(pPila))
    {

        printf("\n\t\t\tInscriptos");
        printf("\n\t-------------------------------------------------");
        printf("\n\tDNI \t| Nombre y Apellido \t| Email \t| codCate \t| ");
        while (aux != NULL)
        {
            printf("\n\t%d | %s | %s | %s |", aux->datos.DNI, aux->datos.nombYapellido, aux->datos.email, aux->datos.codCate);
            aux = aux->siguiente;
        }
        
    }else{
        printf("\nNo hay Inscriptos para visualizar");
    }
}