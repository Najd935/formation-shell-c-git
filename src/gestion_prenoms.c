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
    if (nb_prenoms == 0)
    {
        printf("Liste vide.\n");
        return;
    }
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

void supprimer_prenom(char prenoms[][20], int *nb_prenoms, char *prenom_supprime){
    int position = rechercher_prenom(prenoms,*nb_prenoms,prenom_supprime);
    if ( position == -1)
    {
        printf("Prénom non trouvé, rien supprimé.\n");
        return;
    }

    for (int i = position ; i < *nb_prenoms - 1; i++ )
    {

        strcpy(prenoms[i],prenoms[i+1]);
    }
    *nb_prenoms = *nb_prenoms - 1;
}


void afficher_menu()
{
    printf("1. Ajouter un prénom\n");
    printf("2. Afficher tous les prénoms\n");
    printf("3. Rechercher un prénom\n");
    printf("4. Trier les prénoms\n");
    printf("5. Supprimer un prénom\n");
    printf("0. Quitter\n");
}
