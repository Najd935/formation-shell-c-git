#include <stdio.h>
#include <string.h>



int main()

{

    char names[5][20];

    for (int i = 0; i < 5; i++)
    {
        printf("Entrez le prénom %d : \n",i+1);
        scanf("%s",names[i]);
    }

    char to_find[20];
    printf("Entre le prénom à chercher dans le tableau.\n");
    scanf("%s",to_find);

    for (int i = 0; i < 5; i++)
    {
       if (strcmp(names[i],to_find) == 0)
       {
        printf("Prénom trouvé dans la liste!\n");
        return 0;
       }
        
    }

    printf("Prénom non trouvé.\n");

    return 0;


}