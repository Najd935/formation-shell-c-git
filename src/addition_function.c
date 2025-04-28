#include <stdio.h>


int addition(int a, int b)
{
    return a + b;
}

int main() 
{
    int a;
    int b;

    printf("Choisis un nombre\n");
    scanf("%d",&a);

    printf("Choisis un deuxième nombre\n");
    scanf("%d",&b);

    printf("%d + %d = %d\n",a,b,addition(a,b));

    return 0;
}