#include <stdio.h>


int main()
{

    int x = 10;
    int *pointeur_x = &x;
    *pointeur_x = 20;

    printf("%d\n",*pointeur_x);


    return 0;



}