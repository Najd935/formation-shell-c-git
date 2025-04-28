#include <stdio.h>
#include <string.h>



int main()

{

    char names[5][20] = {
        "Karim",
        "Sarah",
        "Adam",
        "Nassim",
        "Lea"
    };
    
    
    

    /*
    for (int i = 0; i < 5; i++)
    {
        printf("Entrez le prénom %d : \n",i+1);
        scanf("%s",names[i]);
    }
        */

   char tmp[20];

   

   for (int i = 0; i < 5 - 1; i++) {
    for (int j = i + 1; j < 5; j++) {
        if (strcmp(names[i], names[j]) > 0) {
            strcpy(tmp, names[i]);
            strcpy(names[i], names[j]);
            strcpy(names[j], tmp);
        }
    }
}

   printf("Prénoms triés : \n");
   for (int k = 0; k < 5; k++)
   {
    printf("Prénom %d : %s\n", k+1, names[k]);

   }
   return 0;
}