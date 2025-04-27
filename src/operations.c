#include <stdio.h>


int main() {

    int a;
    int b;

    printf("Choisis un nombre.\n");
    scanf("%d",&a);

    printf("Choisis un nombre.\n");
    scanf("%d",&b);

    printf("a + b = %d\n",a+b);
    printf("a - b = %d\n",a-b);
    printf("a * b = %d\n",a*b);
    printf("a / b = %d\n",a/b);
    printf("a %% b = %d\n",a%b);

    return 0;

}