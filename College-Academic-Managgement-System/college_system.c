#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define SUBJECTS 5

// Student structure
typedef struct {
    int id;
    char name[50];
    float marks[SUBJECTS];
    float cgpa;
    float percentage;
} Student;

Student students[MAX];
int count = 0;

// CGPA to Percentage
float cgpaToPercentage(float cgpa)
{
    return cgpa * 9.5;
}

// Percentage to CGPA
float percentageToCGPA(float percentage)
{
    return percentage / 9.5;
}

// Calculate result
void calculate(Student *s)
{
    float total = 0;

    for (int i = 0; i < SUBJECTS; i++)
    {
        total += s->marks[i];
    }

    s->cgpa = total / (SUBJECTS * 10);
    s->percentage = cgpaToPercentage(s->cgpa);
}

// Add student
void addStudent()
{
    printf("\nEnter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter marks (5 subjects):\n");

    for (int i = 0; i < SUBJECTS; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &students[count].marks[i]);
    }

    calculate(&students[count]);

    count++;

    printf("Student Added Successfully!\n");
}

// Show all students
void showStudents()
{
    printf("\n==================== STUDENT REPORT ====================\n");
    printf("ID | Name | CGPA | Percentage\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d | %s | %.2f | %.2f%%\n",
               students[i].id,
               students[i].name,
               students[i].cgpa,
               students[i].percentage);
    }
}

// Average CGPA
void averageCGPA()
{
    float sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += students[i].cgpa;
    }

    printf("\nAverage CGPA of Class: %.2f\n", sum / count);
}

// Rank system
void showTopper()
{
    int idx = 0;

    for (int i = 1; i < count; i++)
    {
        if (students[i].cgpa > students[idx].cgpa)
        {
            idx = i;
        }
    }

    printf("\n🏆 TOPPER STUDENT 🏆\n");
    printf("Name: %s\nCGPA: %.2f\nPercentage: %.2f%%\n",
           students[idx].name,
           students[idx].cgpa,
           students[idx].percentage);
}

// Save to file
void saveToFile()
{
    FILE *fp = fopen("students.txt", "w");

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d %s %.2f %.2f\n",
                students[i].id,
                students[i].name,
                students[i].cgpa,
                students[i].percentage);
    }

    fclose(fp);

    printf("\nData Saved to File Successfully!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== COLLEGE MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Show All Students");
        printf("\n3. Average CGPA");
        printf("\n4. Show Topper");
        printf("\n5. Save to File");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            showStudents();
            break;

        case 3:
            averageCGPA();
            break;

        case 4:
            showTopper();
            break;

        case 5:
            saveToFile();
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}