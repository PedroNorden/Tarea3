# Tarea3
Para compilar la tarea se debe escribir en la terminal "gcc -g *.c -o Tarea" y luego escribir "./Tarea" para ejecutarla.

Todas las opciones funcionan correctamente a excepcion de la función para mostrar las tareas. Las tareas se muestran por orden de prioridad y en el caso que hayan solo 2 tareas también las ordena por precedencia. El problema viene cuando son más de 2 tareas con precedencia, ya que no lo ordena correctamente y además, si se quiere mostrar por segunda vez, el codigo se cae. Creo que este error viene de un error al checkear cuales tareas estan visitadas y también puede haber un error en el datos anteriores quedan guardados y al tratar de usar la opción de nuevo, se ejecuta el codigo con estos datos y se cae.

Estoy haciendo la tarea solo, por lo que no adjunto coevaluación.
