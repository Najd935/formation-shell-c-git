#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
🧪 Exercice – Tableau dynamique d'entiers avec realloc

🎯 Objectif :
Créer un programme qui construit dynamiquement un tableau d'entiers, en agrandissant la mémoire avec realloc si nécessaire.

✅ Étapes :
1. Créer un tableau d'entiers dynamique : int* tab = NULL
2. Initialiser la capacité à 2 et le compteur d'éléments à 0
3. Tant que l’utilisateur entre un entier >= 0 :
   a. Si le nombre d’éléments atteint la capacité :
      - Doubler la capacité
      - Utiliser realloc pour agrandir le tableau
      - Afficher "Capacité augmentée à X"
   b. Ajouter l’entier au tableau
4. Si l'utilisateur entre -1 : arrêter la saisie
5. Afficher les entiers saisis
6. Libérer la mémoire allouée avec free

⚠️ Contraintes :
- Utiliser malloc / realloc / free
- Ne pas dépasser la capacité du tableau
- Pas de fuite mémoire

Bonne chance 💡
*/




int main()
{

    int capacity = 2;
    int nb_elements = 0;
    int *tab = malloc(capacity * sizeof(int));
    if (tab == NULL)
    {
        printf("Couldn't initialize tab.\n");
        return 1;
    }
    int choix = 0;

    while(choix != -1)
    {
        printf("Choisissez un nombre positif à rentrer dans le tableau ou entrez -1 pour quitter le programme.\n");
        scanf("%d",&choix);
        getchar();
        if (choix == -1)
        {
            printf("Fin de remplissage du tableau...\n");
            break;
        }

        if (choix < 0)
        {
            printf("Vous ne pouvez entrer que des nombres positifs.\n");
        }
        else
        {
            if (nb_elements == capacity) 
            {
                capacity *= 2;
                int* tmp = realloc(tab, capacity * sizeof(int));
                if (tmp == NULL) {
                    printf("Échec d'allocation d'espace au tableau.\n");
                    printf("Fin de remplissage du tableau.\n");
                    break; // ou return 1;
                }
                tab = tmp;
            }
            tab[nb_elements++] = choix;
        }
    }
    printf("nb_elements : %d, capacity : %d\n",nb_elements,capacity);
    for (int i = 0; i < nb_elements;i++)
    {
        printf("Élément %d : %d\n", i + 1, tab[i]);
    }

    free(tab);
    printf("Fin du programme.\n");
    return 0;

}