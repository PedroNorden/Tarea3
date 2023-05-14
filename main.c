#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"heap.h"

void agregarTarea(Heap *pq)
{
    char* nombreTarea = malloc(sizeof(char)*100);
    int prioridad = 0;
    printf("Ingrese el nombre de la tarea: \n");
    scanf("%s", nombreTarea);
    printf("Ingrese la prioridad de la tarea: \n");
    scanf("%d", &prioridad);
    heap_push(pq, nombreTarea, prioridad);
}


int main()
{
    Heap* heapTareas = createHeap();
    int opcion;
    while(opcion != 0)
    {
        printf("Ingrese una opcion: \n");
        printf("1.-Agregar tarea\n");
        printf("2.-Establecer precendencia entre tareas\n");
        printf("3.-Mostrar tareas por hacer\n");
        printf("4.-Marcar tarea como completada\n");
        printf("0.-Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("Agregando tarea\n");
                agregarTarea(heapTareas);
                break;
            case 2:
                printf("Estableciendo precendencia\n");
                break;
            case 3:
                printf("Mostrando tareas\n");
                break;
            case 4:
                printf("Marcando tarea\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }
}