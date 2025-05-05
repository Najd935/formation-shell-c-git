#include <stdio.h>
#include "string.h"

#include "personne.h"
#include "gestion_personnes.h"
#include "gestion_fichier.h"


#define MAX_PERSONNES 50
#define CHEMIN_FICHIER "data/prenoms.txt"

int main()
{
    Personne personnes[MAX_PERSONNES];
    int nb_personnes = 0;

    charger_personnes(personnes,&nb_personnes,CHEMIN_FICHIER);
    int choix = -1;

    while(choix != 0)
    {
        afficher_menu();
        scanf("%d",&choix);
        getchar();

        switch(choix)
        {
            case 0:
                printf("Sauvegarde en cours...\n");
                sauvegarder_personnes(personnes,nb_personnes,CHEMIN_FICHIER);
                printf("Au revoir!\n");
                break;
            case 1:
                ajouter_personne(personnes,&nb_personnes);
                break;
            case 2:
                afficher_personnes(personnes,nb_personnes);
                break;
            case 3:
            {
                char to_find[20];
                printf("Choisissez un prénom à rechercher : \n");
                fgets(to_find,20,stdin);
                to_find[strcspn(to_find,"\n")] = '\0';

                int res = rechercher_personne(personnes,nb_personnes,to_find);
                if (res == -1)
                {
                    printf("%s n'est pas dans la liste.\n",to_find);
                }
                else
                {
                    printf("%s est bien dans la liste.\n",to_find);
                }
                break;
            }
                
            case 4:
                trier_personnes(personnes,nb_personnes);
                afficher_personnes(personnes,nb_personnes);
                break;
            case 5:
            {
                char to_delete[20];
                printf("Choisissez un prénom à supprimer : \n");
                fgets(to_delete,20,stdin);
                to_delete[strcspn(to_delete,"\n")] = '\0';

                supprimer_personne(personnes,&nb_personnes,to_delete);
                printf("Liste mise à jour.\n");
                afficher_personnes(personnes,nb_personnes);
                
                break;
            }

            default :
                printf("Choix invalide.\n");
                break;
        }
    }


    return 0;
}