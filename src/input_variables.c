#include <stdio.h>



int main(){

    int age;
    float height;
    char letter;

    printf("How old are you?\n");
    scanf("%d",&age);

    printf("How tall are you?\n");
    scanf("%f",&height);

    printf("What's your name's first letter?\n");
    scanf(" %c",&letter);

    printf("Age : %d years old\nHeight : %0.2f meters\nFirst letter : %c\n",age,height,letter);

        return 0;
}