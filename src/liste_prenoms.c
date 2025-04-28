#include <stdio.h>



int main()

{

    char names[5][20];

    for (int i = 0; i < 5; i++)
    {
        printf("Entrez le prénom %d : \n",i+1);
        scanf("%s",names[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Prénom %d : %s \n",i+1, names[i]);
        
    }

    return 0;


}