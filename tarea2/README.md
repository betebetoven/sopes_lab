
# **TAREA 2 - LABORATORIO SISTEMAS OPERATIVOS 1**

## **Datos del Estudiante**

- **Nombre:** Alberto Josué Hernández Armas
- **Carnet:** 201903553

## **Descripción de la Tarea**

Esta tarea tiene como objetivo que los estudiantes aprendan a automatizar la creación de múltiples contenedores en Docker utilizando un script de Bash. Esta práctica es esencial para comprender cómo gestionar despliegues en masa y optimizar el proceso de orquestación de contenedores.

## **Objetivo**

El objetivo de esta tarea es familiarizar a los estudiantes con la automatización de procesos en Docker mediante la creación de contenedores utilizando un script en Bash.

## **Instrucciones**

1. **Creación del Script:**
    - Escribe un script de Bash que genere 10 contenedores en Docker.
    - Utiliza la imagen `alpine` como base para los contenedores.
    - Asigna nombres aleatoriamente a los contenedores.

2. **Resultados Obtenidos:**
    - Se creó un script en Bash llamado `create_containers.sh` que automatiza la creación de 10 contenedores.
    - Los contenedores fueron generados exitosamente utilizando la imagen `alpine`.
    - Cada contenedor fue nombrado de manera aleatoria utilizando la función `openssl rand -hex 3` para generar los nombres únicos.
    - Los contenedores fueron lanzados exitosamente y el resultado de su creación se muestra en la terminal.

    ```bash
    alber@raspberrypi:~/Desktop/sopes_lab/tarea2 $ ./create_containers.sh 
    Unable to find image 'alpine:latest' locally
    latest: Pulling from library/alpine
    690e87867337: Pull complete 
    Digest: sha256:0a4eaa0eecf5f8c050e5bba433f58c052be7587ee8af3e8b3910ef9ab5fbe9f5
    Status: Downloaded newer image for alpine:latest
    053e92cffb27d4267e6b39bd94e189f2aed14c0a19e87e60c937c600b761e858
    Created container: container_8f3014
    91aaa728824f13ad73b15cb3b03699913d3186c54f9d4e11a6098f8227889484
    Created container: container_5bfb6d
    47ee0a12bac161baf3aa1b2ad3017f59cf62644302f4ef42da73eafd682e43ae
    Created container: container_8a30c6
    19a5adcbf3ce17393abf781e3f4f04b3184791691fb8bc4b73bf165fe1cacd11
    Created container: container_fa3b65
    ddca37d4f0ca4c405ad6f95db84375ea35ce09bdbd8e6fe91e54ed2c46d24c0b
    Created container: container_add7e5
    de1308baa184b524581a67f5f7dce4ff4b1f39352e09f2f57319ed5933300e94
    Created container: container_67e0c8
    2ef894f2e1907655c42e7d435c1b85585efe8de3dde2083abbb843559df19966
    Created container: container_2304a9
    4198ae306179b2b0f2b5ad3a8f682304fb0d70007927f8d94da656227360b4a7
    Created container: container_d6a833
    b6ddcba0d0b1cda892c7c1af7c69d049744987eabfb8d123d0888736309fa28b
    Created container: container_ab4393
    f5caace6f09faf99522e2d80023f27c08330a93341afdee645aa48ae31d04932
    Created container: container_dc0185
    ```

    - Después de la creación de los contenedores, el comando `docker ps` fue utilizado para verificar que todos los contenedores estuvieran corriendo correctamente.

    ```bash
    alber@raspberrypi:~/Desktop/sopes_lab/tarea2 $ docker ps
    CONTAINER ID   IMAGE     COMMAND        CREATED          STATUS          PORTS     NAMES
    f5caace6f09f   alpine    "sleep 3600"   27 seconds ago   Up 26 seconds             container_dc0185
    b6ddcba0d0b1   alpine    "sleep 3600"   27 seconds ago   Up 27 seconds             container_ab4393
    4198ae306179   alpine    "sleep 3600"   28 seconds ago   Up 27 seconds             container_d6a833
    2ef894f2e190   alpine    "sleep 3600"   28 seconds ago   Up 28 seconds             container_2304a9
    de1308baa184   alpine    "sleep 3600"   28 seconds ago   Up 28 seconds             container_67e0c8
    ddca37d4f0ca   alpine    "sleep 3600"   29 seconds ago   Up 29 seconds             container_add7e5
    19a5adcbf3ce   alpine    "sleep 3600"   29 seconds ago   Up 29 seconds             container_fa3b65
    47ee0a12bac1   alpine    "sleep 3600"   30 seconds ago   Up 29 seconds             container_8a30c6
    91aaa728824f   alpine    "sleep 3600"   30 seconds ago   Up 30 seconds             container_5bfb6d
    053e92cffb27   alpine    "sleep 3600"   31 seconds ago   Up 30 seconds             container_8f3014
    ```

    - Una captura de pantalla del comando `docker ps` mostrando los contenedores en ejecución se ha incluido en este repositorio como `tarea2sopes.png`.

## **Entregables**

- **Script de Bash:** `create_containers.sh`
- **Imagen de los contenedores:** `tarea2sopes.png`

## **Conclusión**

La tarea fue completada exitosamente. Se logró automatizar la creación de 10 contenedores en Docker utilizando un script de Bash, y todos los contenedores fueron creados y verificados como funcionales.
