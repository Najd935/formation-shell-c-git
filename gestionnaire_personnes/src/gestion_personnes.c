#include "gestion_personnes.h" 
#include "personne.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void ajouter_personne(Personne personnes[], int *nb_personnes)
{   
    char name_buffer[20];

    printf("Choisis un prénom.\n");
    fgets(name_buffer,20,stdin);
    name_buffer[strcspn(name_buffer,"\n")] = '\0';
    strcpy(personnes[*nb_personnes].nom,name_buffer);

    printf("Choisis un âge.\n");
    scanf("%d",&personnes[*nb_personnes].age);

    while (getchar() != '\n'); // on vide le buffer des retours à la ligne
    (*nb_personnes)++;

}
void afficher_personnes(Personne personnes[], int nb_personnes)
{
    if (nb_personnes == 0)
    {
        printf("Liste de personne vide.\n");
        return;
    }

    printf("Liste de personnes : \n");
    printf("--------------------\n");
    for (int i = 0; i < nb_personnes; i++)
    {
        printf("Personne %d : %s, %d ans.\n", i + 1, personnes[i].nom,personnes[i].age);
    }
    printf("\n");
}

int rechercher_personne(Personne personnes[], int nb_personnes, char *nom_recherche)
{
    for (int i = 0; i < nb_personnes; i++)
    {
        if (strcmp(personnes[i].nom,nom_recherche) == 0)
        {
            return i;
        }
    }

    return -1;
}

void trier_personnes(Personne personnes[], int nb_personnes)
{
    char tmp[20];

    for (int i = 0; i < nb_personnes; i++)
    {
        for (int j = i + 1 ; j < nb_personnes; j++)
        {
            if ( strcmp(personnes[i].nom,personnes[j].nom) > 0 )
            {
                strcpy(tmp,personnes[i].nom);
                strcpy(personnes[i].nom,personnes[j].nom);
                strcpy(personnes[j].nom,tmp);
            }
        }
    }
}

void supprimer_personne(Personne personnes[], int *nb_personnes, char *prenom_supprime)
{

    int position = rechercher_personne(personnes,*nb_personnes,prenom_supprime);
    if (position == -1)
    {
        printf("Prénom non trouvé, rien supprimé.\n");
        return;
    }

    for (int i = position ; i < *nb_personnes - 1; i++ )
    {

        strcpy(personnes[i].nom,personnes[i+1].nom);
        personnes[i].age = personnes[i+1].age;

    }
    *nb_personnes = *nb_personnes - 1;
}

void afficher_menu()
{
    printf("1. Ajouter une personne\n");
    printf("2. Afficher toutes les personnes\n");
    printf("3. Rechercher une personne\n");
    printf("4. Trier les personnes\n");
    printf("5. Supprimer une personne\n");
    printf("0. Quitter\n");
}
