#include <stdio.h>


void doubler(int *px)
{
    *px = *px * 2;
}

int main() 
{

    int a = 5;
    doubler(&a);
    printf("%d\n",a);

    return 0;

}