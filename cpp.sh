#!/bin/bash

# Verificar si se proporcionó un argumento
if [ $# -eq 0 ]; then
    echo "Uso: ./cpp.sh <archivo.cpp>"
    exit 1
fi

# Obtener el nombre del archivo de C++ pasado como argumento
cpp_file="$1"

# Verificar si el archivo existe
if [ ! -e "$cpp_file" ]; then
    echo "El archivo '$cpp_file' no existe."
    exit 1
fi

# Compilar el archivo C++ con g++
g++ -o "${cpp_file%.*}" "$cpp_file"

# Verificar si la compilación tuvo éxito
if [ $? -eq 0 ]; then
    # Ejecutar el programa compilado
    "./${cpp_file%.*}"
else
    echo "Error durante la compilación."
fi
