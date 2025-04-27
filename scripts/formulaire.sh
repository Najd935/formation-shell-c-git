#!/bin/bash

echo "Quel est ton prénom?"
read prenom

echo "Quel âge as-tu?"
read age

echo "Où habites-tu ?"
read ville

if [ "$age" -lt 18 ]
then
    echo "Salut $prenom, tu es mineur."
else
    echo "Salut $prenom, tu es majeur."
fi


echo -e "Résumé :\nPrénom : $prenom\nÂge : $age\nVille : $ville"

