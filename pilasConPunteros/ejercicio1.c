/*Desarrollar un programa para la gestión de las ventas de un supermercado mediante la implementación
de una pila. Cada nodo deberá contener los siguientes datos asociados a un producto: código del producto,
código de rubro, cantidad, precio unitario y descripción. Además de programar todas las operaciones
básicas, se solicita:
a) Escribir una función que calcule y retorne el monto total recaudado.
b) Implementar un menú principal que contenga todas las operaciones disponibles.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef char tString [20];

typedef struct 
{
    int codProducto, cantidadProducto;
    tString descripcion, rubro;
    float precioUnitario;
}tProducto;

typedef struct nodo
{
    tProducto producto;
    struct nodo * siguiente;
}tPila;

void inicializarPila();
bool pilaVacia(tPila *);
void insertarProducto(tProducto );
void quitarProducto();
void visualizarProductos(tPila *);
void menu();
float totalRecaudado(tPila *);
void ingresarProductos();
tProducto productoCima(tPila *);

tPila * pila;
tProducto producto;

int main (){
    menu();
    return 0;
}

void inicializarPila(){
    pila = NULL;
    printf("\nSe inicializo la pila\n");
}

bool pilaVacia(tPila * pPila){

    return pPila == NULL;
}

void insertarProducto(tProducto pProducto){
    tPila * nuevoNodo;

    nuevoNodo = (tPila *) malloc(sizeof(tPila));

    nuevoNodo->producto = pProducto;

    nuevoNodo->siguiente = pila;

    pila = nuevoNodo;

    printf("\nNuevo producto insertado");
}

void quitarProducto(){
    if (!pilaVacia(pila))
    {
        tPila * nodoSuprimir = pila;

        pila = pila->siguiente;

        printf("\nProducto eliminado: %s\n", nodoSuprimir->producto.descripcion);

        free(nodoSuprimir);

        nodoSuprimir = NULL;

    }else{
        printf("\nNo hay productos para quitar");
    }
    
}

void visualizarProductos(tPila * pPila){
    tPila * aux = pPila;

    if (!pilaVacia(pPila))
    {
        printf("\n\t\t*****Informacion****\n");
        printf("\t\tCod.Producto|\tRubro|\tCantidad|\tDescripcion|\tPrecio Unitario\n");
        while (aux != NULL)
        {
            printf("\t\t%d|\t%s|\t%d|\t%s|\t%.2f\n", aux->producto.codProducto,aux->producto.rubro,aux->producto.cantidadProducto,aux->producto.descripcion,aux->producto.precioUnitario);
            aux = aux->siguiente;
        }
        
    }else{
        printf("\nNo hay productos en la pila");
    }
}

tProducto productoCima(tPila * pPila){
    tProducto producto;
    producto.cantidadProducto = 0;
    producto.codProducto = 0;
    producto.precioUnitario = 0.0;
    strcpy(producto.rubro, " ");
    strcpy(producto.descripcion, " ");

    return pilaVacia(pPila) == true ? producto : pPila->producto;
}

float totalRecaudado(tPila * pPila){
    tPila * aux = pPila;
    float total = 0.0;
    if (!pilaVacia(pPila))
    {
        while (aux != NULL)
        {
            total = total + (float)(aux->producto.cantidadProducto * aux->producto.precioUnitario);
            aux = aux->siguiente;
        }
        
    }else{
        printf("\nNo existe productos para calcular el total recaudado");
    }

    return total;
}

void ingresarProductos(){
    int opc;
    do
    {
        printf("\nIngrese el codigo del producto: ");
        scanf("%d", &producto.codProducto);
        printf("\nIngrese el rubro del producto: ");
        fflush(stdin);
        gets(producto.rubro);
        printf("\nIngrese la cantidad de productos: ");
        fflush(stdin);
        scanf("%d", &producto.cantidadProducto);
        printf("\nIngrese la descripcion del producto: ");
        fflush(stdin);
        gets(producto.descripcion);
        printf("\nIngrese el precio del producto: ");
        fflush(stdin);
        scanf("%f", &producto.precioUnitario);
        insertarProducto(producto);

        printf("\nDesea ingresar un nuevo producto 1.Si 0.No: ");
        fflush(stdin);
        scanf("%d",&opc);
    } while (opc == 1);
    
    
}

void menu(){
int opcion;
    do{
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t\t MENU\t\t\t|\n");
        printf("\t\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t\t|\t1. Inicializar Pila\t\t|\n");
        printf("\t\t\t\t\t|\t2. Agregar Producto\t\t|\n");
        printf("\t\t\t\t\t|\t3. Quitar Producto\t\t|\n");
        printf("\t\t\t\t\t|\t4. Visualizar Productos\t\t|\n");
        printf("\t\t\t\t\t|\t5. Total Recaudado\t\t|\n");
        printf("\t\t\t\t\t|\t6. Producto en la Cima\t\t|\n");
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
                system("cls");
                break;
            case 2:
                ingresarProductos();
                system("pause");
                system("cls");
                break;
            case 3:
                quitarProducto();
                system("pause");
                system("cls");
                break;
            case 4:
                visualizarProductos(pila);
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\nTotal Recadado: $%.2f\n", totalRecaudado(pila));
                system("pause");
                system("cls");
                break;
            case 6:
                printf("\nEl Producto en la cima es: %s\n",productoCima(pila).descripcion);
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
    }while(opcion > 0 && opcion < 7);
}