#!/bin/bash


echo "Entre ton âge stp!"

read age

if [ "$age" -lt 13 ]
then
    echo "Tu es un enfant."
elif [ "$age" -ge 13 ] && [ "$age" -le 17 ]
then
    echo "Tu es un adolescent."
elif [ "$age" -ge 18 ] && [ "$age" -le 64 ]
then
    echo "Tu es un adulte."
else
    echo "Tu es un senior."
fi