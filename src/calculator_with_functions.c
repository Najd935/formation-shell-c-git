#include <stdio.h>



int addition(int a, int b)
{
    return a + b;
}

int soustraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if (b == 0)
    {
        printf("Division par zéro impossible.\n");
        return 9999999;
    }

    return a / b;
}

int modulo(int a, int b)
{
    if (b == 0)
    {
        printf("Modulo par zéro impossible.\n");
        return 9999999;

    }

    return a % b;
}

int calculer(int a, int b, char op)
{
    if (op == '+')
    {
        return addition(a,b);
    }
    else if (op == '-')
    {
        return soustraction(a,b);
    }
    else if (op == '*')
    {
        return multiplication(a,b);
    }
    else if (op == '/')
    {
        return division(a,b);
    }
    else if (op == '%')
    {
        return modulo(a,b);
    }
    else 
    {
        printf("Opération non prise en compte.\n");
        return -1;
    }
}

int main()
{
    char choix = 'o';
    int a;
    int b;
    char op;

    while (choix == 'o')
    {
        printf("Choisissez un premier nombre.\n");
        scanf("%d",&a);

        printf("Choisissez un deuxième nombre.\n");
        scanf("%d",&b);

        printf("Choisissez une opération (+,-,*,/,%%).\n");
        scanf(" %c",&op);

        int res = calculer(a,b,op);
        if (res != 9999999)
        {
            printf("%d %c %d = %d\n",a,op,b,res);
        }


        printf("Voulez-vous continuer? o/n\n");
        scanf(" %c", &choix);
    }
}