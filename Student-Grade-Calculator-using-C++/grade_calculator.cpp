#include <iostream>
using namespace std;

class Student
{
private:
    int n;
    float marks[50], total = 0, percentage;

public:
    void inputMarks()
    {
        cout << "Enter number of subjects: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
    }

    void calculate()
    {
        percentage = (total / (n * 100)) * 100;
    }

    void display()
    {
        cout << "\nTotal Marks = " << total;
        cout << "\nPercentage = " << percentage << "%";

        if(percentage >= 90)
            cout << "\nGrade = A+" << endl;
        else if(percentage >= 75)
            cout << "\nGrade = A" << endl;
        else if(percentage >= 60)
            cout << "\nGrade = B" << endl;
        else if(percentage >= 40)
            cout << "\nGrade = C" << endl;
        else
            cout << "\nGrade = Fail" << endl;
    }
};

int main()
{
    Student s;

    cout << "===== Student Grade Calculator =====\n";

    s.inputMarks();
    s.calculate();
    s.display();

    return 0;
}