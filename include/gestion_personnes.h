#ifndef GESTION_PRENOMS_H
#define GESTION_PRENOMS_H

#include "personne.h"



void ajouter_personne(Personne personnes[], int *nb_personnes);
void afficher_personnes(Personne personnes[], int nb_personnes);
int rechercher_personne(Personne personnes[], int nb_personnes, char *nom_recherche);
void trier_personnes(Personne personnes[], int nb_personnes);
void supprimer_personne(Personne personnes[], int *nb_personnes, char *prenom_supprime);
void afficher_menu();


#endif