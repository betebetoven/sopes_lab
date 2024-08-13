
# README - Proyecto: Módulo del Kernel

## Descripción

Este proyecto consiste en la creación de un módulo del kernel que imprime información sobre la memoria del sistema y los procesos en ejecución. El módulo genera un archivo en `/proc/sysinfo` que, al ser leído, muestra información sobre la memoria RAM, la memoria libre, los procesos padre y sus procesos hijos.

## Comandos Utilizados

### 1. `make`

**Comando:**
```bash
make
```
**Descripción:** 
Este comando compila el módulo del kernel utilizando el Makefile presente en el directorio. Genera los archivos objeto `.o`, así como el archivo del módulo final `.ko`.

**Output Esperado:**
- Se mostrarán líneas que indican la compilación de cada archivo fuente (`sysinfo.c`).
- Se generará el archivo `sysinfo.ko`, que es el módulo del kernel compilado.

### 2. `sudo insmod sysinfo.ko`

**Comando:**
```bash
sudo insmod sysinfo.ko
```
**Descripción:**
Este comando inserta el módulo `sysinfo.ko` en el kernel. `insmod` es utilizado para cargar módulos del kernel de manera manual.

**Output Esperado:**
- No debería haber output directo en la terminal si el módulo se carga correctamente.
- Puedes verificar la carga correcta del módulo revisando los logs del kernel con `dmesg`.

### 3. `cat /proc/sysinfo`

**Comando:**
```bash
cat /proc/sysinfo
```
**Descripción:**
Este comando lee el contenido del archivo `/proc/sysinfo` generado por el módulo. Muestra información detallada sobre la memoria del sistema y los procesos.

**Output Esperado:**
- Información sobre la RAM total, RAM libre, procesos padre y sus procesos hijos.
- Ejemplo:
  ```
  Total RAM: 2061412 KB
  Free RAM: 1705940 KB
  Parent Process: systemd [PID: 1]
    Child Process: sshd [PID: 2149]
  ```

### 4. `sudo rmmod sysinfo`

**Comando:**
```bash
sudo rmmod sysinfo
```
**Descripción:**
Este comando elimina el módulo del kernel `sysinfo` que fue previamente cargado. `rmmod` es utilizado para remover módulos del kernel.

**Output Esperado:**
- No debería haber output directo en la terminal si el módulo se elimina correctamente.
- Puedes verificar la remoción correcta del módulo revisando los logs del kernel con `dmesg`.

### 5. `zip -r SO1Tarea1_201903553.zip ./`

**Comando:**
```bash
zip -r SO1Tarea1_201903553.zip ./*
```
**Descripción:**
Este comando crea un archivo comprimido que incluye todos los archivos y directorios presentes en el directorio actual (`sopes_lab`).

**Output Esperado:**
- Se generará un archivo `SO1Tarea1_201903553.zip` que contiene todos los archivos y subdirectorios en el directorio `sopes_lab`.

## Notas

- Asegúrate de haber seguido todos los pasos y de incluir los archivos correctos en el archivo comprimido antes de la entrega.
- Si necesitas verificar los logs del kernel, puedes usar el comando `dmesg`.

---

Fin del archivo README.
