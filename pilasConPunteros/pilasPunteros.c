#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tString[25];

typedef struct 
{
    int code;
    tString description;
    float price;
}tData;

typedef struct node
{
    tData data;
    struct nodo * next;
}tStack;

void stackInit();
bool emptyStack(tStack *);
void insertNode(tData);
void removeNode();
void showData( tStack *);
tData topNode ( tStack *);
tStack * topNode2( tStack *);

tStack * stack;
tData  emptyData;

int main(){

    emptyData.code = 0; 
    strcpy(emptyData.description, " "); 
    emptyData.price = 0.0; 

    tData data;
    
    stackInit();
    
    data.code = 100;
    strcpy(data.description, "Palta");
    data.price = 237.50;
    insertNode(data);
    data.code = 101;
    strcpy(data.description, "Tomate");
    data.price = 350.75;
    insertNode(data);
    data.code = 102;
    strcpy(data.description, "Lechuga");
    data.price = 200;

    insertNode(data);
    showData(stack);

    removeNode();
    showData(stack);

    printf("\nTop Node: %s", topNode(stack).description);
    printf("\nTop Node2.0: %s", topNode2(stack)->data.description);

    return 0;
}

void stackInit(){
    stack = NULL;
    printf("\nStack initialized...");
}

bool emptyStack(tStack * pStack){
    return pStack == NULL;
}

void insertNode(tData pData){
    tStack * newNode;

    newNode = (tStack *) malloc(sizeof(tStack));

    newNode->data = pData;

    newNode->next = stack;

    stack = newNode;

    printf("\nThe new node has been inserted!");
}

void removeNode(){
    
    if(!emptyStack(stack)){
        tStack * deleteNode = stack;

        stack = stack->next;

        printf("\nNode removed: %s", deleteNode->data.description);

        free(deleteNode);

        deleteNode = NULL;
    }else{
        printf("\nStack empty!");
    }
}

void showData( tStack * pStack){
    tStack * aux = pStack;

    if (emptyStack(pStack))
    {
        printf("\nEmpty stack!");
    }else{
        printf("\nInformation");
        printf("\n---------------------------------\n");
        printf("\nCode\t| Description\t| Price");
        while (aux != NULL)
        {
            printf("\n%d\t%s\t$%.2f",aux->data.code, aux->data.description, aux->data.price);
            aux = aux->next;
        }       
    }
       
}

tData topNode (tStack * pStack){
    return emptyStack(pStack) == true ? emptyData : pStack->data;
}

tStack * topNode2 ( tStack * pStack){
    return emptyStack(pStack) == true ? NULL : pStack;
}