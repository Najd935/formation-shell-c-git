#include <stdio.h>


int main()
{

    char prenom[20];
    printf("Quel est ton prénom?\n");
    scanf("%s",prenom);

    printf("Bienvenue %s.\n",prenom);

    return 0;

}