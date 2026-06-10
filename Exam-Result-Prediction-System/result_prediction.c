#include <stdio.h>

#define MAX_SUBJECTS 5

// Student structure
typedef struct {
    int id;
    char name[50];
    int marks[MAX_SUBJECTS];
    int total;
    float percentage;
} Student;

// Calculate total + percentage
void calculateResult(Student *s, int subjectCount)
{
    s->total = 0;

    for (int i = 0; i < subjectCount; i++)
    {
        s->total += s->marks[i];
    }

    // FIX: proper float division
    s->percentage = (float)s->total / (subjectCount * 100) * 100;
}

// Predict grade (FIXED LOGIC)
void predictResult(Student s)
{
    printf("\n===== RESULT =====\n");
    printf("Student ID   : %d\n", s.id);
    printf("Name         : %s\n", s.name);
    printf("Total Marks  : %d\n", s.total);
    printf("Percentage   : %.2f%%\n", s.percentage);

    // FIX: proper boundary handling
    if (s.percentage >= 80.0 && s.percentage <= 100.0)
    {
        printf("Grade        : Excellent 🏆\n");
    }
    else if (s.percentage >= 60.0)
    {
        printf("Grade        : Good 👍\n");
    }
    else if (s.percentage >= 40.0)
    {
        printf("Grade        : Average ⚠️\n");
    }
    else if (s.percentage >= 0.0)
    {
        printf("Grade        : Fail ❌\n");
    }
    else
    {
        printf("Grade        : Invalid Data ❌\n");
    }
}

int main()
{
    Student s;
    int subjectCount;

    printf("===== EXAM RESULT PREDICTION SYSTEM =====\n");

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);

    printf("Enter Student Name: ");
    scanf("%s", s.name);

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &subjectCount);

    if (subjectCount <= 0 || subjectCount > MAX_SUBJECTS)
    {
        printf("Invalid number of subjects!\n");
        return 0;
    }

    printf("\nEnter marks (out of 100):\n");

    for (int i = 0; i < subjectCount; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);

        // optional safety check
        if (s.marks[i] < 0 || s.marks[i] > 100)
        {
            printf("Invalid marks! Enter 0-100 only.\n");
            return 0;
        }
    }

    calculateResult(&s, subjectCount);
    predictResult(s);

    return 0;
}