#include <stdio.h>


int main() 
{
    char choix = 'o';

    while (choix == 'o') 
    {
        int a;
        int b;
        char op;

        printf("Choisis un premier nombre.\n");
        scanf("%d",&a);

        printf("Choisis un deuxième nombre.\n");
        scanf("%d",&b);

        printf("Choisis une opération (+,-,*,/,%%)\n");
        scanf(" %c",&op);

        if (op == '+') {
            printf("%d + %d = %d\n",a,b,a+b);
        }
        else if (op == '-')
        {
            printf("%d - %d = %d\n",a,b,a-b);
        }
        else if (op == '*')
        {
            printf("%d * %d = %d\n",a,b,a*b);
        }
        else if (op == '/')
        {
            if (b == 0){
                printf("Division par zéro impossible.\n");
            }
            else {
                printf("%d / %d = %d\n",a,b,a/b);
            }
        }
        else if (op == '%')
        {
            if (b == 0) {
                printf("Modulo par zéro impossible.\n");
            } else {
                printf("%d %% %d = %d\n", a, b, a % b);
            }
    
        }
        else {
            printf("Opération non supportée.\n");
        }
        
        printf("Veux-tu continuer? (o/n)\n");
        scanf(" %c",&choix);

    }

    printf("Aurevoir!\n");

    return 0;
}