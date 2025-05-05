#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
🧪 Exercice – Gestion dynamique d’un prénom

🎯 Objectif :
Créer un programme qui utilise malloc pour stocker dynamiquement un prénom entré par l’utilisateur.

✅ Étapes :
1. Allouer dynamiquement un espace mémoire de 50 caractères pour un prénom.
2. Demander à l’utilisateur : "Quel est votre prénom ?"
3. Lire la saisie avec fgets (et supprimer le \n si présent).
4. Copier la chaîne saisie dans la mémoire allouée.
5. Afficher : "Bonjour [prénom] !"
6. Libérer la mémoire à la fin du programme.

⚠️ Contraintes :
- Utiliser malloc (pas de variable statique pour le prénom)
- Pas de fuite mémoire (free obligatoire)
- Ne pas utiliser strdup

Bonne chance !
*/


int main()
{

    char *prenom = malloc(50 * sizeof(char)); 
    if (prenom == NULL)
    {
        printf("Erreur d'allocation.\n");
        return 1;
    }
    printf("Quel est votre prénom?\n");
    char input[50];
    fgets(input,50,stdin);
    input[strcspn(input,"\n")] = '\0';
    strcpy(prenom,input);

    printf("Bonjour [%s].\n",prenom);

    free(prenom);
    return 0;
    //afficher_menu();


}