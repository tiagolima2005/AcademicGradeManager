#include <stdio.h>
#include <string.h>

struct Student
{
    char name[100];
    char birth_date[11]; // dd/mm/yyyy + '\0'
    int year;
    char class;
    int number;
};

void add_students(struct Student *student);

int main()
{
    int option;
    struct Student student;

    do
    {
        printf("Welcome to the Academic Grade Manager Program!\n");
        printf("Type the number of the function you wish to use:\n");
        printf("1 - Add Students\n");
        printf("2 - Add Grades to a Student\n");
        printf("3 - Calculate the average grade\n");
        printf("4 - See passed and failed students\n");
        printf("5 - Exit program\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            add_students(&student);
            break;

        default:
            break;
        }
    } while (option != 5);

    return 0;
}

void add_students(struct Student *student)
{
    printf("Insert the student's name:\n");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    printf("Insert the student's year:\n");
    scanf("%d", &student->year);
    getchar();

    printf("Insert the student's class:\n");
    scanf(" %c", &student->class);
    getchar();

    printf("Insert the student's number/id:\n");
    scanf("%d", &student->number);
}