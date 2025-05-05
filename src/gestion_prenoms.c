#include "gestion_prenoms.h"
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


void sauvegarder_personnes(Personne personnes[], int nb_personnes, const char *nom_fichier)

{
    FILE *f = fopen(nom_fichier,"w");
    if (f == NULL)
    {
        printf("Impossible d'ouvrir le fichier %s en écriture.\n",nom_fichier);
        return;
    }

    for (int i = 0; i < nb_personnes; i++)
    {
        fprintf(f,"%s;%d\n",personnes[i].nom,personnes[i].age);

    }

    fclose(f);
}
void charger_personnes(Personne personnes[], int *nb_personnes, const char *nom_fichier)

{

    FILE *f = fopen(nom_fichier,"r");

    if (f == NULL)
    {
        printf("Fichier %s introuvable. Aucune personne trouvée.\n",nom_fichier);
        return;
    }
    char ligne[256];

    while (fgets(ligne,256,f) != NULL)
    {
        
        ligne[strcspn(ligne,"\n")] = '\0';
        char prenom[20];
        char age[20];
        int index_nom = 0;
        int index_age = 0;
        int i = 0;
        
        while (ligne[index_nom] != ';')
        {
            prenom[index_nom] = ligne[index_nom];
            index_nom++;
        }
         // on saute le ';'
        i = index_nom + 1;

         while (ligne[i] != '\0')
         {
            age[index_age] = ligne[i];
            index_age++;
            i++;
         }

        prenom[index_nom] = '\0';
        age[index_age] = '\0';
        int age_personne = atoi(age);

        Personne personne;
        strcpy(personne.nom,prenom);
        personne.age = age_personne;

        personnes[*nb_personnes] = personne;
        (*nb_personnes)++;
        
    }
    fclose(f);
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
