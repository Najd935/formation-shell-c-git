#include <stdio.h>
#include "gestion_prenoms.h"
#include "string.h"


int main()
{
    char prenoms[50][20];
    int nb_prenoms = 0;

    for (int i = 0; i < 4; i++)
    {
        ajouter_prenom(prenoms,&nb_prenoms);
    }
    
    char prenom[20];
    printf("Quel prénom cherchez-vous?\n");
    fgets(prenom,20,stdin);
    prenom[strcspn(prenom,"\n")] = '\0';

    int res = rechercher_prenom(prenoms,nb_prenoms,prenom);

    if (res == -1)
    {
        printf("Prénom non trouvé.\n");
    }
    else
    {
        printf("Prénom trouvé à la position %d.\n",res + 1);
    }

    printf("Liste non triée : \n");
    afficher_prenom(prenoms,nb_prenoms);
    trier_prenoms(prenoms,nb_prenoms);
    printf("Liste triée : \n");
    afficher_prenom(prenoms,nb_prenoms);
    

    return 0;
}