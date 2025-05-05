#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H

#include "personne.h"

void sauvegarder_personnes(Personne personnes[], int nb_personnes, const char *nom_fichier);
void charger_personnes(Personne personnes[], int *nb_personnes, const char *nom_fichier);


#endif