/*El departamento de alumnado necesita trabajar con los datos de los alumnos de la materia AEDII, para
ello implementa una lista simplemente enlazada, donde cada nodo guarda el número de libreta
universitaria y el nombre del alumno. Se pide crear las funciones necesarias para:
a) Generar la lista.
b) Insertar el primer alumno (nodo) de la lista.
c) Insertar alumnos al principio de la lista.
d) Eliminar el primer alumno de la lista.
e) Insertar un alumno en una determinada posición dentro de la lista.
f) Eliminar un alumno de una determinada posición de la lista.
g) Visualizar todos los datos de los alumnos que están en la lista.
Además, crear una función que retorne la cantidad de alumnos que contiene la lista e implementar un
menú principal que contenga todos los ítems anteriormente solicitados.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef char tString[40];

typedef struct 
{
    tString nombreApellido;
    int LU;
}tAlumno;

typedef struct nodo{
    tAlumno alumno;
    struct nodo * siguiente;
}tListaAlumnos;

void inicializarLista();
bool listaVacia(tListaAlumnos *);
void insertarAlumno(tAlumno);
void insertarAdelante(tAlumno);
void visualizarAlumnos(tListaAlumnos *);
void ingresarAlumno();
void ingresarAlumnoPos();
void eliminarAlumno();
void eliminarPrimerAlumno(tAlumno);
void insertarAlumnoPos(tAlumno, int);
void eliminarAlumnoPos(int);
int cantAlumnos(tListaAlumnos *);
void menu();

tListaAlumnos *lista;
tAlumno alumno;
int pos;

int main (){
    menu();
    return 0;
}

void inicializarLista(){
    lista = NULL;
    printf("\nLista inicializada...!\n");
}

bool listaVacia(tListaAlumnos *pListaAlumnos){
    return pListaAlumnos == NULL;
}

void insertarAlumno(tAlumno pAlumno) {
    int opc;
    if (listaVacia(lista))
    {
        insertarAdelante(pAlumno);
    }else{
        insertarAdelante(pAlumno);
    }
    
}

void insertarAdelante(tAlumno pAlumno){
    tListaAlumnos * nuevoNodo;

    nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));

    nuevoNodo->alumno = pAlumno;

    if(listaVacia(lista)){
        nuevoNodo->siguiente = NULL;

    }else{
        nuevoNodo->siguiente = lista;

    }

    lista= nuevoNodo;

    printf("\nAlumno Insertado");
}

void insertarAlumnoPos(tAlumno pAlumno, int pos){
    tListaAlumnos *aux, * nuevoNodo;
    aux = lista;

    for (int i = 1; i < pos-1; i++)
    {
        aux = aux->siguiente;
    }

    nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));

    nuevoNodo->alumno = pAlumno;

    nuevoNodo->siguiente = aux->siguiente;

    aux->siguiente =  nuevoNodo;

    printf("\nSe ingreso un alumno en la posicion: %d", pos);
    
}

void visualizarAlumnos(tListaAlumnos *pListaAlumnos){
    tListaAlumnos * aux;
    aux = pListaAlumnos;

    if (!listaVacia(aux))
    {
        printf("\t\t\t\tLU\t\t\tAlumno\n");
        while (aux != NULL)
        {
            printf("\t\t\t\t%d\t\t%s\n", aux->alumno.LU, aux->alumno.nombreApellido);
            aux = aux->siguiente;
        }
        
    }else{
        printf("\nNo hay Alumnos para visualizar");
    }
    
}

void eliminarPrimerAlumno(tAlumno pAlumno){
    if (!listaVacia(lista))
    {
        tListaAlumnos * nodoSuprimir = lista;
        lista = lista->siguiente;
        printf("\nSe dio de baja al alumno: %d\t\t%s\n", nodoSuprimir->alumno.LU, nodoSuprimir->alumno.nombreApellido);
        free(nodoSuprimir);
        nodoSuprimir = NULL;
    }
    else{
        printf("\nNo hay alumnos para dar de baja");
    }
    
}

void eliminarAlumnoPos(int pos){

    if (!listaVacia(lista))
    {   
    
        tListaAlumnos *aux, *nodoSuprimir;
        aux = lista;
        int cantNodos = cantAlumnos(lista);

        if (pos <= cantNodos && pos > 0)
        {
            if (pos == 1)
            {
                eliminarPrimerAlumno(alumno);
            }else{

                for (int i = 1; i < pos-1; i++)
                {
                    aux = aux->siguiente;
                }
                
                nodoSuprimir = aux->siguiente;

                aux->siguiente = nodoSuprimir->siguiente;

                printf("\nSe dio de baja al alumno: %d\t\t%s\n", nodoSuprimir->alumno.LU, nodoSuprimir->alumno.nombreApellido);
                free(nodoSuprimir);
                nodoSuprimir = NULL;
            }
            
        }else{
            printf("\nValor ingresado no valido");
            ingresarAlumnoPos();
        }
    }else{
        printf("\nNo hay alumnos para dar de baja");
    }
    
}

void eliminarAlumno(){
    printf("\nIngrese una posicion no mayor a %d: ", cantAlumnos(lista));
    scanf("%d", &pos);
    eliminarAlumnoPos(pos);
}

void ingresarAlumno(){
    int opc;
    do
    {
        printf("\nIngrese LU: ");
        scanf("%d", &alumno.LU);
        printf("\nIngrese apellido y nombre del alumno: ");
        fflush(stdin);
        gets(alumno.nombreApellido);
        insertarAlumno(alumno);
        printf("\nDesea ingresar otro alumno? 1.Si 0.No: ");
        scanf("%d",&opc);
    } while (opc == 1);       
}

void ingresarAlumnoPos(){
    int opc;
    do
    {
        printf("\nIngrese LU: ");
        scanf("%d", &alumno.LU);
        printf("\nIngrese apellido y nombre del alumno: ");
        fflush(stdin);
        gets(alumno.nombreApellido);
        printf("\nIngrese posicion en la que desea insertar: ");
        scanf("%d", &pos);
        insertarAlumnoPos(alumno, pos);
        printf("\nDesea ingresar otro alumno? 1.Si 0.No: ");
        scanf("%d",&opc);
    } while (opc == 1);       
}

int cantAlumnos(tListaAlumnos * pListaAlumnos){
    tListaAlumnos * aux;
    aux = pListaAlumnos;
    int cont = 0;
    if (!listaVacia(aux))
    {
        while (aux != NULL)
        {
            cont++;
            aux = aux->siguiente;
        }
        
    }

    return cont;
}

void menu(){
    int opcion;
    do{
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\t MENU\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t1. Inicializar lista\t\t|\n");
        printf("\t\t\t\t\t|\t2. Agregar Alumno\t\t|\n");
        printf("\t\t\t\t\t|\t3. Agregar Alumno en pos\t|\n");
        printf("\t\t\t\t\t|\t4. Visualizar Lista de alumnos\t|\n");
        printf("\t\t\t\t\t|\t5. Eliminar Primer Alumno\t|\n");
        printf("\t\t\t\t\t|\t6. Eliminar Alumno en pos\t|\n");
        printf("\t\t\t\t\t|\t7. Cantidad de alumnos\t\t|\n");
        printf("\t\t\t\t\t|\t0. Salir\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\tIngrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                inicializarLista();
                system("pause");
                system("cls");
                break;
            case 2:
                ingresarAlumno();
                system("pause");
                system("cls");
                break;
            case 3:
                ingresarAlumnoPos();
                system("pause");
                system("cls");
                break;
            case 4:
                visualizarAlumnos(lista);
                system("pause");
                system("cls");
                break;
            case 5:
                eliminarPrimerAlumno(alumno);
                system("pause");
                system("cls");
                break;
            case 6:
                eliminarAlumno(); 
                system("pause");
                system("cls");
                break;
            case 7:
                printf("\nCantidad de alumnos: %d\n", cantAlumnos(lista));
                system("pause");
                system("cls");
                break;
            case 0:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\n\n\t\t\t\t\t|Opcion no valida!|\n");
                system("cls");
                menu();
                break;
        }
    }while(opcion > 0 && opcion < 8);
}