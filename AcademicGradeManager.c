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

void add_students(struct Student students[], int *count);
void list_students(struct Student students[], int count);
void add_grade(struct Student students[], int count);

int main()
{
    int option;
    struct Student students[100];
    int student_count = 0;

    do
    {
        printf("Welcome to the Academic Grade Manager Program!\n");
        printf("Type the number of the function you wish to use:\n");
        printf("1 - Add Students\n");
        printf("2 - Add Grades to a Student\n");
        printf("3 - List all Students\n");
        printf("4 - Show all students grades\n");
        printf("5 - Calculate the average grade\n");
        printf("6 - See passed and failed students\n");
        printf("7 - Exit program\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            add_students(students, &student_count);
            break;

        case 2:
            add_grade(students, student_count);
            break;

        default:
            break;
        }
    } while (option != 7);

    return 0;
}

void add_students(struct Student students[], int *count)
{
    if (*count >= 100)
    {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct Student *new_student = &students[*count];

    printf("Insert the student's name:\n");
    fgets(new_student->name, sizeof(new_student->name), stdin);
    new_student->name[strcspn(new_student->name, "\n")] = '\0';

    printf("Insert the student's year:\n");
    scanf("%d", &new_student->year);
    getchar();

    printf("Insert the student's class:\n");
    scanf(" %c", &new_student->class);
    getchar();

    printf("Insert the student's number/id:\n");
    scanf("%d", &new_student->number);
    getchar();

    new_student->grade_count = 0; // Inicializa o contador de notas
    (*count)++;

    printf("Student added successfully!\n");
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
    scanf("%d", &choice);
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
    scanf("%d", &new_grade);
    getchar();

    if (new_grade < 0 || new_grade > 100)
    {
        printf("Invalid grade. Please enter a value between 0 and 100.\n");
        return;
    }

    selected_student->grades[selected_student->grade_count++] = new_grade;
    printf("Grade added successfully to %s.\n", selected_student->name);
}