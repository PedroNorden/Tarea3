#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char *nombre;
    int prioridad;
    char *tareasPrecedentes;
}Tareas;

typedef struct
{
    Tareas *tareas;
    int capacidad;
    int size;
}heapTareas;



int main()
{
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