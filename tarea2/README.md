
# Tarea 2 - Laboratorio Sistemas Operativos 1

## UNIVERSIDAD DE SAN CARLOS DE GUATEMALA
### FACULTAD DE INGENIERÍA
### ESCUELA DE CIENCIAS Y SISTEMAS
### SECCIÓN: A
### SEGUNDO SEMESTRE 2024

**Nombre:** Alberto Josué Hernández Armas  
**Carnet:** 201903553

## TAREA 2

### Objetivo
Que los estudiantes aprendan a automatizar la creación de múltiples contenedores en Docker utilizando un script de Bash. Esta práctica es esencial para comprender cómo gestionar despliegues en masa y optimizar el proceso de orquestación de contenedores.

### Instrucciones
1. **Creación del Script:**
   - Escribe un script de Bash que genere 10 contenedores en Docker.
   - Utiliza la imagen alpine como base para los contenedores.
   - Asigna nombres aleatoriamente.

### Entregables:
- Link del Repositorio.
- Script de Bash.
- Imagen de los contenedores.

### Fecha límite de entrega:
Sábado 17/08/2024 antes de las 23:59.

NOTA: Dudas o consultas realizarlas en el foro semanal.

## Ejecución de la Tarea

El script de Bash creado para esta tarea se encargó de automatizar la creación de 10 contenedores utilizando la imagen `alpine`. A continuación se presenta el script:

```bash
#!/bin/bash

# Number of containers to create
NUM_CONTAINERS=10

# Loop to create containers
for i in $(seq 1 $NUM_CONTAINERS)
do
  # Generate a random name for the container
  CONTAINER_NAME=$(openssl rand -hex 3)
  
  # Run a container with the alpine image
  docker run -d --name "container_$CONTAINER_NAME" alpine sleep 3600

  # Print the name of the container that was created
  echo "Created container: container_$CONTAINER_NAME"
done
```

### Proceso Realizado

1. **Ejecución del Script:**
   Se ejecutó el script `create_containers.sh` para crear los contenedores.

   ```bash
   ./create_containers.sh
   ```

   Este comando creó 10 contenedores con nombres aleatorios basados en la imagen `alpine`.

2. **Verificación de Contenedores:**
   Se verificó que los contenedores estuvieran corriendo correctamente utilizando el comando:

   ```bash
   docker ps
   ```

3. **Limpieza de Contenedores:**
   Para detener y eliminar los contenedores creados, se utilizaron los siguientes comandos:

   ```bash
   docker stop $(docker ps -q)
   docker rm $(docker ps -aq)
   docker system prune -a
   ```

   Estos comandos aseguraron que no quedaran contenedores ni imágenes innecesarias en el sistema.

4. **Verificación de Limpieza:**
   Finalmente, se verificó que el sistema estuviera limpio y sin contenedores o imágenes residuales utilizando:

   ```bash
   docker ps -a
   ```

   No se encontraron contenedores en el sistema.

## Conclusión

Se completaron todos los pasos indicados en la tarea, asegurando la automatización y manejo adecuado de contenedores en Docker mediante el uso de scripts en Bash.
