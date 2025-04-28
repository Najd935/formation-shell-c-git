#!/bin/bash

echo "Vous avez passé $# argument(s)."
compteur=1
for arg in "$@"
do
    echo "Argument $compteur : $arg"
    compteur=$((compteur+1))
done