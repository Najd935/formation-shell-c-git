#include <stdio.h>


int main()
{
    int notes[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Entrez la note %d : \n", i + 1);
        scanf("%d",&notes[i]);
    }

    printf(" Voici les notes que vous avez saisies.\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Note %d : %d\n",i + 1,notes[i]);
    }
}