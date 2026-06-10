#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    int present;
    int total;
} Student;

Student students[MAX];
int count = 0;

// Add student
void addStudent()
{
    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    students[count].present = 0;
    students[count].total = 0;

    count++;

    printf("Student Added Successfully!\n");
}

// Mark attendance
void markAttendance()
{
    int id;
    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            char status;
            printf("Mark Attendance (P/A): ");
            scanf(" %c", &status);

            students[i].total++;

            if (status == 'P' || status == 'p')
            {
                students[i].present++;
            }

            printf("Attendance Marked!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

// Show report
void showReport()
{
    printf("\n===== ATTENDANCE REPORT =====\n");

    for (int i = 0; i < count; i++)
    {
        float percent = 0;

        if (students[i].total != 0)
        {
            percent = (students[i].present * 100.0) / students[i].total;
        }

        printf("ID: %d | Name: %s | Present: %d | Total: %d | %% %.2f\n",
               students[i].id,
               students[i].name,
               students[i].present,
               students[i].total,
               percent);
    }
}

// Find low attendance students
void lowAttendanceAlert()
{
    printf("\n===== LOW ATTENDANCE ALERT (<75%%) =====\n");

    for (int i = 0; i < count; i++)
    {
        float percent = 0;

        if (students[i].total != 0)
        {
            percent = (students[i].present * 100.0) / students[i].total;
        }

        if (percent < 75)
        {
            printf("⚠ ID: %d | Name: %s | Attendance: %.2f%%\n",
                   students[i].id,
                   students[i].name,
                   percent);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== SMART ATTENDANCE SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Mark Attendance");
        printf("\n3. Show Report");
        printf("\n4. Low Attendance Alert");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            markAttendance();
            break;

        case 3:
            showReport();
            break;

        case 4:
            lowAttendanceAlert();
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}