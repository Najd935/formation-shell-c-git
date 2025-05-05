#ifndef GESTION_PRENOMS_H
#define GESTION_PRENOMS_H
#define CHEMIN_FICHIER "data/prenoms.txt"

typedef struct {
    char nom[20];
    int age;
} Personne;

void ajouter_personne(Personne personnes[], int *nb_personnes);
void afficher_personnes(Personne personnes[], int nb_personnes);
int rechercher_personne(Personne personnes[], int nb_personnes, char *nom_recherche);
void trier_personnes(Personne personnes[], int nb_personnes);
void supprimer_personne(Personne personnes[], int *nb_personnes, char *prenom_supprime);
void sauvegarder_personnes(Personne personnes[], int nb_personnes, const char *nom_fichier);
void charger_personnes(Personne personnes[], int *nb_personnes, const char *nom_fichier);
void afficher_menu();


#endif