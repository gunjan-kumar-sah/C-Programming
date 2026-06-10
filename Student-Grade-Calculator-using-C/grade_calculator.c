#include <stdio.h>

int main()
{
    int n, i;
    float marks[50], sum = 0, percentage;

    printf("===== Student Grade Calculator =====\n");

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    // Input marks
    for(i = 0; i < n; i++)
    {
        printf("Enter marks of subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    // Calculate percentage
    percentage = (sum / (n * 100)) * 100;

    printf("\nTotal Marks = %.2f", sum);
    printf("\nPercentage = %.2f%%\n", percentage);

    // Grade calculation
    if(percentage >= 90)
        printf("Grade = A+\n");
    else if(percentage >= 75)
        printf("Grade = A\n");
    else if(percentage >= 60)
        printf("Grade = B\n");
    else if(percentage >= 40)
        printf("Grade = C\n");
    else
        printf("Grade = Fail\n");

    return 0;
}