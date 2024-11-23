#include <stdio.h>
#include <string.h>

struct Student
{
    char name[100];
    char birth_date[11]; // dd/mm/yyyy + '\0'
    int year;
    char class;
    int number;
    int grades[10];
    int grade_count;
};

void add_students(struct Student *student);
void list_students(struct Student students[], int count);
void add_grade(struct Student students[], int count);

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

void list_students(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d - %s (ID: %d, Class: %c)\n", i + 1, students[i].name, students[i].number, students[i].class);
    }
}

void add_grade(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("No students available. Please add students first.\n");
        return;
    }

    printf("Choose a student to add a grade:\n");
    list_students(students, count);

    int choice;
    printf("Enter the student number:\n");
    scanf("%d" , &choice);
    getchar();

    if (choice < 1 || choice > count)
    {
        printf("Invalid choice.\n");
        return;
    }

    struct Student *selected_student = &students[choice - 1];

    if (selected_student->grade_count >= 10)
    {
        printf("This student already has the maximum number of grades.\n");
        return;
    }

    int new_grade;
    printf("Enter the grade to add:\n");
    scanf("%d" , &new_grade);
    getchar();

    
}