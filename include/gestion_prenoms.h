#ifndef GESTION_PRENOMS_H
#define GESTION_PRENOMS_H


void ajouter_prenom(char prenoms[][20], int *nb_prenoms);
void afficher_prenom(char prenoms[][20], int nb_prenoms);
int rechercher_prenom(char prenoms[][20], int nb_prenoms, char *prenom_recherche);
void trier_prenoms(char prenoms[][20], int nb_prenoms);



#endif