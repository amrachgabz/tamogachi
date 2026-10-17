#include <stdio.h>
#include <stdbool.h>

bool happiness_checker(int happiness)
{
    if (happiness == 0) { return false; }
    else { return true; }
}

int main()
{
    char name[20];
    bool running = false;
    int health = 10, happiness = 10;
    int health_max = 10, happiness_max = 10;

    //Intro
    printf("Welcome to Pixel Pet!\n");
    printf("To begin, enter a name for your Pixel pet!\n");
    printf("What would you like to name your pet?\n");
    scanf("%19s", name);

    //Pixel Pet
    printf(" ∩_∩ ");
    printf("\n(0_0)");
    printf("\n(   )");
    printf("\n v-v \n");
    printf("%s\n", name);

    //Stats
    printf("\n");
    printf("Health: %d\n", health);
    printf("Happiness: %d\n", happiness);
    running = true;

    while (running)
    {
        //Menu 
        int choice = 0;
        printf("What would you like to do?\n");
        printf("1. Feed Pet\n");
        printf("2. Play with Pet\n");
        printf("3. Quit Game :(\n");
        do
        {
            scanf("%d", &choice);
        }
        while (choice < 1 || choice > 3);

        if (choice == 1)
        {
            //picking food
            int food_choice = 0;
            printf("Pick your food\n");
            printf("1. Pizza (+5)\n2. Cupcake (+3)\n3. Coffee (+1)\n");
            do { scanf("%d", &food_choice); }
            while (food_choice < 1 || food_choice > 3);
            
            //gain and cost measures
            int gain = 0, cost = 0;
            if (food_choice == 1) { gain = 5; cost = 3; }
            else if (food_choice == 2) { gain = 3; cost = 2; }
            else if (food_choice == 3) { gain = 1; cost = 1; }

            //increasing health based on food choice
            if (food_choice == 1) 
            { 
                if (gain + health <= health_max && happiness >= 3)
                {
                    health += 5; 
                    happiness -= 3; 
                }
                else if (!happiness_checker(happiness))
                {
                    printf("Uh oh! Your pet is too sad. See you another time!\n");
                    running = false;
                }
                else
                {
                    printf("Uh oh! Seems like your pet is full!\n");
                }
            }
            else if (food_choice == 2) { health += 3; happiness -= 2; }
            else if (food_choice == 3) { health += 1; happiness -= 1; }

            printf("Health: %d\n", health);
            printf("Happiness: %d\n", happiness);
        }
        else if (choice == 2)
        {
            //picking toy
            int toy = 0;
            printf("Pick toy\n");
            printf("1. Trampoline \n2. Ball \n 3. Chew Toy \n");
            do { scanf("%d", &toy); }
            while (toy < 1 || toy > 3);
            
            //decreasing health based on food choice
            if (toy == 1) { happiness += 5; health -= 3; }
            else if (toy == 2) { happiness += 3; health -= 2;}
            else if (toy == 3) { happiness += 1; health -= 1;}

            printf("Health: %d\n", health);
            printf("Happiness: %d\n", happiness);
        }
        else if (choice == 3)
        {
            printf("Thank you for playing! %s says bye!", name);
            running = false;
        }
    }
}