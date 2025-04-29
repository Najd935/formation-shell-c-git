#!/bin/bash


if [ -z "$1" ]
then
    echo "Vous n'avez pas fourni d'argument(s)."
    exit 1
fi

sources=""
output_file="main"

for file in "$@"
do
    sources="$sources src/$file.c"
done

if gcc $sources -I include -o bin/$output_file
then
    echo "✅ Compilation réussie."
    ./bin/$output_file
else
    echo "❌ Erreur de compilation."
    exit 1
fi
