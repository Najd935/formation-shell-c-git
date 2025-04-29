#include "gestion_prenoms.h"
#include <stdio.h>
#include <string.h>




void ajouter_prenom(char prenoms[][20], int *nb_prenoms)
{
    printf("Choisis un prénom.\n");
    fgets(prenoms[*nb_prenoms],20,stdin);

    prenoms[*nb_prenoms][strcspn(prenoms[*nb_prenoms], "\n")] = '\0';
    *nb_prenoms = *nb_prenoms + 1;

}
void afficher_prenom(char prenoms[][20], int nb_prenoms)
{
    for (int i = 0; i < nb_prenoms; i++)
    {
        printf("Prénom %d : %s\n", i + 1, prenoms[i]);
    }
}

int rechercher_prenom(char prenoms[][20], int nb_prenoms, char *prenom_recherche)
{
    for (int i = 0; i < nb_prenoms; i++)
    {
        if (strcmp(prenoms[i],prenom_recherche) == 0)
        {
            return i;
        }
    }

    return -1;
}

void trier_prenoms(char prenoms[][20], int nb_prenoms)
{
    char tmp[20];

    for (int i = 0; i < nb_prenoms; i++)
    {
        for (int j = i + 1 ; j < nb_prenoms; j++)
        {
            if ( strcmp(prenoms[i],prenoms[j]) > 0 )
            {
                strcpy(tmp,prenoms[i]);
                strcpy(prenoms[i],prenoms[j]);
                strcpy(prenoms[j],tmp);
            }
        }
    }
}
