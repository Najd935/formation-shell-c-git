#include <stdio.h>
#include <string.h>

int main() 
{
    char first[40];
    char second[40];

    printf("Quel est le premier mot?\n");
    fgets(first,40,stdin);
    first[strcspn(first,"\n")] = '\0';

    printf("Quel est le second mot?\n");
    fgets(second,40,stdin);
    second[strcspn(second,"\n")] = '\0';


    if (strcmp(first,second) == 0)
    {
        printf("Les mots sont identiques.\n");
    }
    else
    {
        printf("Les mots sont différents.\n");
    }

    return 0;

}