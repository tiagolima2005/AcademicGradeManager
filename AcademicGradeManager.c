#include <stdio.h>

int main()
{
    int option;
    do
    {
        printf("Welcome to the Academic Grade Manager Program!\n");
        printf("Type the number of the function you wish to use:\n");
        printf("1 - Add Students\n");
        printf("2 - Add Grades to a Student\n");
        printf("3 - Calculate the average grade\n");
        printf("4 - See passed and failed students\n");
        printf("5 - Exit program\n");
        switch (option)
        {
        case 1:
            /* code */
            break;

        default:
            break;
        }
    } while (option != 5);

    return 0;
}