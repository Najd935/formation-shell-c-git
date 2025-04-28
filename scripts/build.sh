#!/bin/bash


if [ -z "$1" ]
then
    echo "Erreur : nom du fichier à compiler manquant"
    exit 1
fi

source_file="src/$1.c"
output_file="bin/$1"

gcc "$source_file" -o "$output_file"

if [ $? -eq 0 ]
then
    echo "Compilation réussie."
    ./$output_file
else
    echo "Erreur de compilation"
    exit 1
fi
