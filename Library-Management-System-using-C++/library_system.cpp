#include <iostream>
#include <fstream>
using namespace std;

class Book
{
private:
    int bookId;
    string bookName;
    string author;
    bool isIssued;

public:
    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> bookId;

        cout << "Enter Book Name: ";
        cin >> bookName;

        cout << "Enter Author Name: ";
        cin >> author;

        isIssued = false;

        ofstream file("books.txt", ios::app);
        file << bookId << " " << bookName << " " << author << " " << isIssued << endl;
        file.close();

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks()
    {
        ifstream file("books.txt");

        cout << "\n===== BOOK LIST =====\n";

        while (file >> bookId >> bookName >> author >> isIssued)
        {
            cout << "ID: " << bookId
                 << " | Name: " << bookName
                 << " | Author: " << author
                 << " | Issued: " << (isIssued ? "Yes" : "No")
                 << endl;
        }

        file.close();
    }

    void issueBook(int id)
    {
        ifstream file("books.txt");
        ofstream temp("temp.txt");

        bool found = false;

        while (file >> bookId >> bookName >> author >> isIssued)
        {
            if (bookId == id && isIssued == false)
            {
                isIssued = true;
                found = true;
                cout << "Book Issued Successfully!\n";
            }

            temp << bookId << " " << bookName << " " << author << " " << isIssued << endl;
        }

        file.close();
        temp.close();

        remove("books.txt");
        rename("temp.txt", "books.txt");

        if (!found)
            cout << "Book not available or already issued!\n";
    }

    void returnBook(int id)
    {
        ifstream file("books.txt");
        ofstream temp("temp.txt");

        bool found = false;

        while (file >> bookId >> bookName >> author >> isIssued)
        {
            if (bookId == id && isIssued == true)
            {
                isIssued = false;
                found = true;
                cout << "Book Returned Successfully!\n";
            }

            temp << bookId << " " << bookName << " " << author << " " << isIssued << endl;
        }

        file.close();
        temp.close();

        remove("books.txt");
        rename("temp.txt", "books.txt");

        if (!found)
            cout << "Invalid Book ID or Book not issued!\n";
    }
};

int main()
{
    Book b;
    int choice, id;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.addBook();
            break;

        case 2:
            b.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            b.issueBook(id);
            break;

        case 4:
            cout << "Enter Book ID to return: ";
            cin >> id;
            b.returnBook(id);
            break;

        case 5:
            cout << "Thank you for using Library System!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}