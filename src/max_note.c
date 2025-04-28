#include <stdio.h>


int main() 
{
    int notes[5];
    int note_max;

    for (int i = 0; i < 5; i++)
    {
        printf("Tapez la note %d : \n",i + 1);
        scanf("%d",&notes[i]);
    }

    note_max = notes[0];

    for (int i = 1; i < 5; i++)
    {
        if (notes[i] > note_max)
        {
            note_max = notes[i];
        }
    }

    printf("Note maximale : %d\n",note_max);

    return 0;
}