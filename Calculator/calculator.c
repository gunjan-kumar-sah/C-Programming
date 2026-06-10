#include <stdio.h>

int main()
{
    float num1, num2, result;
    char op;

    printf("===== Simple Calculator =====\n");

    // Input numbers
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &num2);

    // Perform calculation
    switch(op)
    {
        case '+':
            result = num1 + num2;
            printf("Result = %.2f\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result = %.2f\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result = %.2f\n", result);
            break;

        case '/':
            if(num2 != 0)
            {
                result = num1 / num2;
                printf("Result = %.2f\n", result);
            }
            else
            {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}