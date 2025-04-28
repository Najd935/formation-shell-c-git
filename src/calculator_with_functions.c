#include <stdio.h>

void erreur_division()
{
    printf("Division par zéro impossible.\n");
}

void erreur_modulo()
{
    printf("Modulo par zéro impossible.\n");
}

void erreur_operateur()
{
    printf("Opérateur inconnu.\n");
}

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
        erreur_division();
        return 9999999;
    }

    return a / b;
}

int modulo(int a, int b)
{
    if (b == 0)
    {
        erreur_modulo();
        return 9999999;

    }

    return a % b;
}

void message_bienvenue()
{
    printf("Bienvenue dans la calculatrice ! \n");
}

void menu()
{
    printf("Veuillez choisir une opération :\n");
    printf("+ pour addition\n");
    printf("- pour soustraction\n");
    printf("* pour multiplication\n");
    printf("/ pour division\n");
    printf("%% pour modulo.\n");
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
        erreur_operateur();
        return 9999999;
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
        message_bienvenue();
        printf("Choisissez un premier nombre.\n");
        scanf("%d",&a);

        printf("Choisissez un deuxième nombre.\n");
        scanf("%d",&b);

        menu();
        scanf(" %c",&op);

        int res = calculer(a,b,op);
        if (res != 9999999)
        {
            printf("Résultat : %d %c %d = %d\n",a,op,b,res);
        }


        printf("Voulez-vous continuer? o/n\n");
        scanf(" %c", &choix);
    }
}