#include <stdio.h>


int main() 
{
    int notes[5];
    int somme_notes = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Tapez la note %d : \n",i + 1);
        scanf("%d",&notes[i]);
    }

    for (int i = 0; i < 5; i++)
    {
       somme_notes = somme_notes + notes[i];
    }

    printf("Somme des notes : %d\n",somme_notes);

    return 0;
}