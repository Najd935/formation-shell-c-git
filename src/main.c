#include <stdio.h>
#include "gestion_prenoms.h"
#include "string.h"


int main()
{
    char prenoms[50][20];
    int nb_prenoms = 0;
    int choix = -1;

    while(choix != 0)
    {
        afficher_menu();
        scanf("%d",&choix);
        getchar();

        switch(choix)
        {
            case 0:
                printf("Au revoir!\n");
                break;
            case 1:
                ajouter_prenom(prenoms,&nb_prenoms);
                break;
            case 2:
                afficher_prenom(prenoms,nb_prenoms);
                break;
            case 3:
            {
                char to_find[20];
                printf("Choisissez un prénom à rechercher : \n");
                fgets(to_find,20,stdin);
                to_find[strcspn(to_find,"\n")] = '\0';

                int res = rechercher_prenom(prenoms,nb_prenoms,to_find);
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
                trier_prenoms(prenoms,nb_prenoms);
                afficher_prenom(prenoms,nb_prenoms);
                break;
            case 5:
            {
                char to_delete[20];
                printf("Choisissez un prénom à supprimer : \n");
                fgets(to_delete,20,stdin);
                to_delete[strcspn(to_delete,"\n")] = '\0';

                supprimer_prenom(prenoms,&nb_prenoms,to_delete);
                printf("Liste mise à jour.\n");
                afficher_prenom(prenoms,nb_prenoms);
                break;
            }

            default :
                printf("Choix invalide.\n");
                break;
        }
    }


    return 0;
}