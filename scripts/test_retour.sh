#!/bin/bash


if [ -n "$1" ]
then
    ls "$1"
    if [ $? -eq 0 ]
    then
        echo "Dossier accessible : $1"
    else
        echo "Erreur dossier $1 inaccessible."
    fi
else
    echo "Aucun argument fourni."
    exit 1
fi
