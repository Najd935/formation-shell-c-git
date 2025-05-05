#include "gestion_fichier.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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