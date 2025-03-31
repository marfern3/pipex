#!/bin/bash

# Limpiamos resultados anteriores
rm -f resultado*.txt hola.txt test*.txt

echo "==== Test 1: Comando simple ===="
echo "uno dos tres" > test1.txt
./pipex test1.txt "cat" "wc -w" resultado1.txt
cat resultado1.txt

echo "==== Test 2: grep + rev ===="
echo -e "uno\ndos\ntres\ncuatro" > test2.txt
./pipex test2.txt "grep o" "rev" resultado2.txt
cat resultado2.txt

echo "==== Test 3: tr (minúsculas a mayúsculas) ===="
echo "hola marco como estas" > hola.txt
./pipex hola.txt "tr a-z A-Z" "rev" resultado3.txt
cat resultado3.txt

echo "==== Test 4: comando inexistente ===="
./pipex hola.txt "comandonovalido" "rev" resultado4.txt
cat resultado4.txt

echo "==== Test 5: cut (solo palabras 2 y 4) ===="
echo "hola marco como estas" > test5.txt
./pipex test5.txt "cut -d' ' -f2,4" "rev" resultado5.txt
cat resultado5.txt

echo "==== Todos los tests completados ===="
