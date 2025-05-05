#ifndef TACHE_H
#define TACHE_H

typedef struct {
    char* description;
    char* date;      // format jj/mm/aaaa
    int priorite;    // de 1 (basse) à 5 (haute)
} Tache;

void ajouter_tache(Tache** taches, int* nb_taches, int* capacite);
void afficher_taches(Tache* taches, int nb_taches);

#endif