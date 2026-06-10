#include <iostream>
#include <cmath>

using namespace std;

class Calculator
{
public:
    double add(double a, double b)
    {
        return a + b;
    }

    double subtract(double a, double b)
    {
        return a - b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }

    double divide(double a, double b)
    {
        if (b == 0)
        {
            cout << "Error: Division by zero is not allowed!" << endl;
            return 0;
        }
        return a / b;
    }

    double power(double a, double b)
    {
        return pow(a, b);
    }

    double squareRoot(double a)
    {
        if (a < 0)
        {
            cout << "Error: Negative number!" << endl;
            return 0;
        }
        return sqrt(a);
    }

    double modulus(int a, int b)
    {
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a % b;
    }
};

int main()
{
    Calculator calc;
    int choice;
    double num1, num2;

    do
    {
        cout << "\n====================================";
        cout << "\n      SCIENTIFIC CALCULATOR";
        cout << "\n====================================";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Power";
        cout << "\n6. Square Root";
        cout << "\n7. Modulus";
        cout << "\n8. Exit";
        cout << "\n------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result = " << calc.add(num1, num2) << endl;
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result = " << calc.subtract(num1, num2) << endl;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result = " << calc.multiply(num1, num2) << endl;
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result = " << calc.divide(num1, num2) << endl;
            break;

        case 5:
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            cout << "Result = " << calc.power(num1, num2) << endl;
            break;

        case 6:
            cout << "Enter a number: ";
            cin >> num1;
            cout << "Result = " << calc.squareRoot(num1) << endl;
            break;

        case 7:
        {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            cout << "Result = " << calc.modulus(a, b) << endl;
            break;
        }

        case 8:
            cout << "\nThank you for using the calculator!\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}