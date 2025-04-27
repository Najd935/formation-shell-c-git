#include <stdio.h>


int main() {

    int a;
    int b;
    char op;

    printf("Choisis un premier nombre.\n");
    scanf("%d",&a);

    printf("Choisis un deuxieme nombre.\n");
    scanf("%d",&b);

    printf("Choisis une opération (+, -, *, /, %%)\n");
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
        printf("%d %% %d = %d\n",a,b,a%b);

    }
    else {
        printf("Opération non supportée.\n");
    }

    return 0;
    
}