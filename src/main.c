#include <stdio.h>
#include "utils.h"


int main()
{
    int a = 5;
    doubler(&a);
    printf("%d\n", a);
    return 0;
}