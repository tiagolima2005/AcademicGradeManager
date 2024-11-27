#include <stdio.h>
#include <string.h>

// Definition of the Student structure
struct Student
{
    char name[100];      // Student's name (up to 99 characters + null terminator)
    char birth_date[11]; // Student's birth date in "dd/mm/yyyy" format
    int year;            // Year the student is in
    char class;          // Class of the student (e.g., A, B, etc.)
    int number;          // Student's ID number
    int grades[10];      // Array to store up to 10 grades
    int grade_count;     // Number of grades currently assigned to the student
};

// Function prototypes
void add_students(struct Student students[], int *count);
void list_students(struct Student students[], int count);
void add_grade(struct Student students[], int count);
void all_students_grades(struct Student students[], int count);

int main()
{
    int option;                   // Menu option chosen by the user
    struct Student students[100]; // Array to store up to 100 students
    int student_count = 0;        // Counter for the number of students added

    do
    {
        // Displaying the menu options
        printf("\nWelcome to the Academic Grade Manager Program!\n");
        printf("Type the number of the function you wish to use:\n");
        printf("1 - Add Students\n");
        printf("2 - Add Grades to a Student\n");
        printf("3 - List all Students\n");
        printf("4 - Show all students grades\n");
        printf("5 - Calculate the average grade\n");
        printf("6 - See passed and failed students\n");
        printf("7 - Exit program\n");
        scanf("%d", &option);
        getchar(); // Consume leftover newline character from input buffer

        // Handle the selected menu option
        switch (option)
        {
        case 1:
            add_students(students, &student_count); // Add a new student
            break;

        case 2:
            add_grade(students, student_count); // Add a grade to a selected student
            break;

        case 3:
            list_students(students, student_count); // List all students
            break;

        case 4:
            all_students_grades(students, student_count); // Show grades of all students
            break;

        default:
            break; // Do nothing for invalid options or other cases
        }
    } while (option != 7); // Exit loop when user chooses option 7

    return 0; // Program ends
}

// Function to add a new student
void add_students(struct Student students[], int *count)
{
    if (*count >= 100) // Check if the student array is full
    {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct Student *new_student = &students[*count]; // Pointer to the next available position in the array

    // Collecting student information from the user
    printf("Insert the student's name:\n");
    fgets(new_student->name, sizeof(new_student->name), stdin);
    new_student->name[strcspn(new_student->name, "\n")] = '\0'; // Remove trailing newline

    printf("Insert the student's year:\n");
    scanf("%d", &new_student->year);
    getchar(); // Consume leftover newline character

    printf("Insert the student's class:\n");
    scanf(" %c", &new_student->class);
    getchar();

    printf("Insert the student's number/id:\n");
    scanf("%d", &new_student->number);
    getchar();

    new_student->grade_count = 0; // Initialize the grade counter for this student
    (*count)++;                   // Increment the student counter

    printf("Student added successfully!\n");
}

// Function to list all students
void list_students(struct Student students[], int count)
{
    if (count == 0) // Check if there are no students
    {
        printf("No students available.\n");
        return;
    }

    // Iterate through the student array and print their details
    for (int i = 0; i < count; i++)
    {
        printf("%d - %s (ID: %d, Class: %c)\n", i + 1, students[i].name, students[i].number, students[i].class);
    }
}

// Function to add a grade to a student
void add_grade(struct Student students[], int count)
{
    if (count == 0) // Check if there are no students
    {
        printf("No students available. Please add students first.\n");
        return;
    }

    printf("Choose a student to add a grade:\n");
    list_students(students, count); // Display a list of all students

    int choice;
    printf("Enter the student number:\n");
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > count) // Validate the student's choice
    {
        printf("Invalid choice.\n");
        return;
    }

    struct Student *selected_student = &students[choice - 1]; // Pointer to the selected student

    if (selected_student->grade_count >= 10) // Check if the student already has the maximum grades
    {
        printf("This student already has the maximum number of grades.\n");
        return;
    }

    int new_grade;
    printf("Enter the grade to add:\n");
    scanf("%d", &new_grade);
    getchar();

    if (new_grade < 0 || new_grade > 100) // Validate the grade value
    {
        printf("Invalid grade. Please enter a value between 0 and 100.\n");
        return;
    }

    // Add the grade to the student's grades array and increment the grade counter
    selected_student->grades[selected_student->grade_count++] = new_grade;
    printf("Grade added successfully to %s.\n", selected_student->name);
}

// Function to display all students' grades
void all_students_grades(struct Student students[], int count)
{
    if (count == 0) // Check if there are no students
    {
        printf("No students available.\n");
        return;
    }

    // Iterate through all students
    for (int i = 0; i < count; i++)
    {
        printf("%d - %s (ID: %d, Class: %c)\n", i + 1, students[i].name, students[i].number, students[i].class);

        if (students[i].grade_count == 0) // Check if the student has no grades
        {
            printf("   No grades available\n");
        }
        else
        {
            printf("   Grades: ");
            for (int j = 0; j < students[i].grade_count; j++) // Print all grades of the student
            {
                printf("%d ", students[i].grades[j]);
            }
            printf("\n");
        }
    }
}