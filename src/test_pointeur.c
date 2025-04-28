#include <stdio.h>


int main()
{

    int x = 10;
    int *pointeur_x;

    pointeur_x = &x;

    printf("%d\n",x);
    printf("%p\n",&x);
    printf("%p\n",pointeur_x);
    printf("%d\n",*pointeur_x);

    return 0;
}