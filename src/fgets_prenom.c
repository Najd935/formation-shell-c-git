#include <stdio.h>
#include <string.h>

int main() 
{
    char nom[40];

    printf("Quel est ton nom et ton prénom?\n");
    fgets(nom,40,stdin);

    nom[strcspn(nom,"\n")] = '\0';


    printf("Bienvenue [%s] !\n",nom);

    return 0;

}