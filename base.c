#include <stdio.h>
#include <stdbool.h>

int main()
{
    char name[20];
    
    printf("Welcome to Pixel Pet!");
    printf("\nTo begin, enter a name for your Pixel pet!");
    printf("\nWhat would you like to name your pet?");
    scanf("%s", name);

    printf(" ^-^ ");
    printf("\n(0_0)");
    printf("\n(   )");
    printf("\n v-v ");
    printf("\n%s", name);
}