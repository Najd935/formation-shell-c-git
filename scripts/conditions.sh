#!/bin/bash

echo "Quel âge as-tu?"

read age

if [ "$age" -ge 18 ]
then
    echo "Tu peux voter."
else
    echo "Tu ne peux pas encore voter."
fi