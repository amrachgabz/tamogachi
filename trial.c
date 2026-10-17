#include <stdio.h>
#include <stdbool.h>

//functions to check for minimum
bool happiness_checker(int happiness) { return happiness > 0; }
bool health_checker(int health) { return health > 0; }

int main()
{
    char name[20];
    bool running = false;
    int health = 5, happiness = 5;
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
            if (gain + health > health_max)
            {
                printf("Uh oh! Seems like your pet is full!\n");
            }
            else
            {
                health += gain; 
                happiness -= cost; 
            }
            
            if (!happiness_checker(happiness))
            {
                printf("Uh oh! Your pet is too sad. See you another time!\n");
                running = false;
            }

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
            int gain = 0, cost = 0;

            //Gain and Cost measures
            if (toy == 1) { gain = 5; cost = 3; }
            else if (toy == 2) { gain = 3; cost = 2; }
            else if (toy == 3) { gain = 1; cost = 1; }

            //Increasing happiness based on toy
            if (gain + happiness > happiness_max)
            {
                printf("You're Pet is very happy!\n");
            }
            else
            {
                happiness += gain;
                health -= cost;
            }
            
            if (!health_checker(health))
            {
                printf("Uh oh! Your pet is sick! See you another time;");
                running = false;
            }

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