# Pipex - 42 Project

Recreación en C del comportamiento de las pipes (`|`) de la shell.

## 🧠 Objetivo

Este programa reproduce el siguiente comportamiento:

```
./pipex infile "cmd1" "cmd2" outfile
```

Equivalente a:

```
< infile cmd1 | cmd2 > outfile
```

## 🔧 Compilación

Clona el repositorio y ejecuta:

```
make
```

Esto compilará `pipex` junto con la `libft`.

## 🚀 Uso

```
./pipex archivo_entrada "comando1" "comando2" archivo_salida
```

### 📌 Ejemplo:

```
echo "hola marco como estas" > hola.txt
./pipex hola.txt "tr a-z A-Z" "rev" resultado.txt
cat resultado.txt
```

Resultado:
```
SATSE OMOC OCRAM ALOH
```

## ✅ Funcionalidades implementadas

- Redirección de entrada/salida con `open`, `dup2`
- Uso de `pipe()` y `fork()` para manejar procesos hijos
- Ejecución de comandos con `execve()`
- Manejo de errores y permisos
- Búsqueda de comandos usando `PATH`
- Protección contra fugas de memoria
- Compatible con Norminette de 42

## 📁 Estructura del proyecto

- `main.c` → lógica principal del programa
- `pipex.c` → ejecución de comandos
- `process.c` → lógica de los procesos hijo1 y hijo2
- `paths.c` → búsqueda del path de los comandos
- `utils.c` → funciones auxiliares (`msg_error`, `free_split`, etc)
- `pipex.h` → prototipos y includes
- `libft/` → implementación obligatoria de la libft

## 👤 Autor

Marco Fernandez Callejon  
42 Madrid
