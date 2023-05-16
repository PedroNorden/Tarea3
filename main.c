#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"heap.h"
#include"list.h"
#include"map.h"

typedef struct Tarea{
    char* nombre;
    int prioridad;
    List *dependencias;
}Tareas;

int is_equal_string(void *key1, void *key2)
{
    if (strcmp((char *)key1, (char *)key2) == 0)
    {
        return 1;
    }
    return 0;
}

Tareas *agregarTarea()
{
    Tareas* tarea = (Tareas*)malloc(sizeof(Tareas));
    tarea->nombre = (char*)malloc(sizeof(char)*50);
    tarea->dependencias = createList();
    printf("Ingrese el nombre de la tarea: \n");
    scanf("%s", tarea->nombre);
    printf("Ingrese la prioridad de la tarea: \n");
    scanf("%d", &tarea->prioridad);
    return tarea;
}

void establecerPrecedencia(Map *mapaTareas)
{
    char* tarea1 = (char*)malloc(sizeof(char)*50);
    char* tarea2 = (char*)malloc(sizeof(char)*50);
    printf("Ingrese el nombre de la tarea que debe realizarse primero: \n");
    scanf("%s", tarea1);
    printf("Ingrese el nombre de la tarea dependiente: \n");
    scanf("%s", tarea2);
    Tareas *tareaPrecedente = searchMap(mapaTareas, tarea1);
    Tareas *tareaDependiente = searchMap(mapaTareas, tarea2);
    if(tareaPrecedente == NULL || tareaDependiente == NULL)
    {
        printf("No se encontraron las tareas\n");
        return;
    }
    eraseMap(mapaTareas, tarea1);
    pushBack(tareaPrecedente->dependencias, tareaDependiente);
    insertMap(mapaTareas, tarea1, tareaPrecedente);

}

void mostrarTareas(Map *mapaTareas)
{
    printf("Tareas por hacer: \n");
    Tareas *tarea, *dependencia;
    for(tarea = firstMap(mapaTareas); tarea != NULL; tarea = nextMap(mapaTareas))
    {
        printf("Tarea: %s | Prioridad: %d", tarea->nombre, tarea->prioridad);
        if((dependencia = firstList(tarea->dependencias)) != NULL)
        {
            printf(" | Dependencias: ");
            for(dependencia = firstList(tarea->dependencias); dependencia != NULL; dependencia = nextList(tarea->dependencias))
            {
                printf("%s", dependencia->nombre);
            }
        }
    }
    printf("\n");
}

int main()
{
    Map *mapaTareas = createMap(is_equal_string);
    Heap* heapTareas = createHeap();
    int opcion;
    Tareas *tarea;
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
                tarea = agregarTarea(heapTareas);
                heap_push(heapTareas, tarea, tarea->prioridad);
                insertMap(mapaTareas, tarea->nombre, tarea);
                break;
            case 2:
                printf("Estableciendo precendencia\n");
                establecerPrecedencia(mapaTareas);
                break;
            case 3:
                printf("Mostrando tareas\n");
                mostrarTareas(mapaTareas);
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