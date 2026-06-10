#include <iostream>
#include <fstream>
using namespace std;

class Patient
{
private:
    int id;
    string name;
    int age;
    string disease;
    string doctor;
    bool admitted;

public:

    void addPatient()
    {
        cout << "Enter Patient ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Disease: ";
        cin >> disease;

        cout << "Enter Doctor Assigned: ";
        cin >> doctor;

        admitted = true;

        ofstream file("patients.txt", ios::app);
        file << id << " " << name << " " << age << " " << disease << " " << doctor << " " << admitted << endl;
        file.close();

        cout << "\nPatient Added Successfully!\n";
    }

    void viewPatients()
    {
        ifstream file("patients.txt");

        cout << "\n===== PATIENT RECORDS =====\n";

        while (file >> id >> name >> age >> disease >> doctor >> admitted)
        {
            cout << "ID: " << id
                 << " | Name: " << name
                 << " | Age: " << age
                 << " | Disease: " << disease
                 << " | Doctor: " << doctor
                 << " | Admitted: " << (admitted ? "Yes" : "No")
                 << endl;
        }

        file.close();
    }

    void dischargePatient(int pid)
    {
        ifstream file("patients.txt");
        ofstream temp("temp.txt");

        bool found = false;

        while (file >> id >> name >> age >> disease >> doctor >> admitted)
        {
            if (id == pid && admitted == true)
            {
                admitted = false;
                found = true;
                cout << "Patient Discharged Successfully!\n";
            }

            temp << id << " " << name << " " << age << " " << disease << " " << doctor << " " << admitted << endl;
        }

        file.close();
        temp.close();

        remove("patients.txt");
        rename("temp.txt", "patients.txt");

        if (!found)
            cout << "Patient not found or already discharged!\n";
    }

    void searchPatient(int pid)
    {
        ifstream file("patients.txt");
        bool found = false;

        while (file >> id >> name >> age >> disease >> doctor >> admitted)
        {
            if (id == pid)
            {
                cout << "\n--- PATIENT FOUND ---\n";
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Age: " << age << endl;
                cout << "Disease: " << disease << endl;
                cout << "Doctor: " << doctor << endl;
                cout << "Admitted: " << (admitted ? "Yes" : "No") << endl;

                found = true;
                break;
            }
        }

        if (!found)
            cout << "Patient not found!\n";

        file.close();
    }
};

class Hospital
{
private:
    string adminUser = "admin";
    string adminPass = "1234";

public:

    bool login()
    {
        string user, pass;

        cout << "===== HOSPITAL LOGIN =====\n";

        cout << "Username: ";
        cin >> user;

        cout << "Password: ";
        cin >> pass;

        if (user == adminUser && pass == adminPass)
        {
            cout << "\nLogin Successful!\n";
            return true;
        }
        else
        {
            cout << "\nInvalid Credentials!\n";
            return false;
        }
    }
};

int main()
{
    Hospital h;
    Patient p;

    if (!h.login())
        return 0;

    int choice, id;

    do
    {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Patient";
        cout << "\n2. View Patients";
        cout << "\n3. Discharge Patient";
        cout << "\n4. Search Patient";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p.addPatient();
            break;

        case 2:
            p.viewPatients();
            break;

        case 3:
            cout << "Enter Patient ID: ";
            cin >> id;
            p.dischargePatient(id);
            break;

        case 4:
            cout << "Enter Patient ID: ";
            cin >> id;
            p.searchPatient(id);
            break;

        case 5:
            cout << "Thank you for using Hospital System!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}