#ifndef GESTION_PRENOMS_H
#define GESTION_PRENOMS_H
#define CHEMIN_FICHIER "data/prenoms.txt"

void ajouter_prenom(char prenoms[][20], int *nb_prenoms);
void afficher_prenom(char prenoms[][20], int nb_prenoms);
int rechercher_prenom(char prenoms[][20], int nb_prenoms, char *prenom_recherche);
void trier_prenoms(char prenoms[][20], int nb_prenoms);
void afficher_menu();
void supprimer_prenom(char prenoms[][20], int *nb_prenoms, char *prenom_supprime);
void sauvegarder_prenoms(const char prenoms[][20], int nb_prenoms, const char *nom_fichier);
void charger_prenoms(char prenoms[][20], int *nb_prenoms, const char *nom_fichier);



#endif