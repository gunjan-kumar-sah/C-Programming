#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int id;
    char title[50];
    char priority[10];
    char dueDate[15];
    int completed;
} Task;

char currentUser[50];

void getFileName(char fileName[])
{
    strcpy(fileName, currentUser);
    strcat(fileName, "_tasks.txt");
}

void registerUser()
{
    char user[50], pass[50];

    printf("Enter Username: ");
    scanf("%s", user);

    printf("Enter Password: ");
    scanf("%s", pass);

    FILE *file = fopen("users.txt", "a");
    fprintf(file, "%s %s\n", user, pass);
    fclose(file);

    printf("User Registered Successfully!\n");
}

int login()
{
    char user[50], pass[50], u[50], p[50];

    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    FILE *file = fopen("users.txt", "r");

    while (fscanf(file, "%s %s", u, p) != EOF)
    {
        if (strcmp(user, u) == 0 && strcmp(pass, p) == 0)
        {
            strcpy(currentUser, user);
            fclose(file);
            printf("\nLogin Successful!\n");
            return 1;
        }
    }

    fclose(file);
    printf("\nInvalid Credentials!\n");
    return 0;
}

void addTask()
{
    Task t;
    char fileName[60];

    getFileName(fileName);

    printf("Enter Task ID: ");
    scanf("%d", &t.id);

    printf("Enter Title: ");
    scanf("%s", t.title);

    printf("Enter Priority (High/Med/Low): ");
    scanf("%s", t.priority);

    printf("Enter Due Date (DD-MM-YYYY): ");
    scanf("%s", t.dueDate);

    t.completed = 0;

    FILE *file = fopen(fileName, "a");
    fprintf(file, "%d %s %s %s %d\n", t.id, t.title, t.priority, t.dueDate, t.completed);
    fclose(file);

    printf("Task Added Successfully!\n");
}

void viewTasks()
{
    Task t;
    char fileName[60];

    getFileName(fileName);

    FILE *file = fopen(fileName, "r");

    printf("\n===== YOUR TASKS =====\n");

    while (fscanf(file, "%d %s %s %s %d",
                  &t.id, t.title, t.priority, t.dueDate, &t.completed) != EOF)
    {
        printf("ID: %d | Task: %s | Priority: %s | Due: %s | Status: %s\n",
               t.id,
               t.title,
               t.priority,
               t.dueDate,
               t.completed ? "Done" : "Pending");
    }

    fclose(file);
}

void completeTask(int taskId)
{
    Task t;
    char fileName[60];

    getFileName(fileName);

    FILE *file = fopen(fileName, "r");
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(file, "%d %s %s %s %d",
                  &t.id, t.title, t.priority, t.dueDate, &t.completed) != EOF)
    {
        if (t.id == taskId)
        {
            t.completed = 1;
        }

        fprintf(temp, "%d %s %s %s %d\n",
                t.id, t.title, t.priority, t.dueDate, t.completed);
    }

    fclose(file);
    fclose(temp);

    remove(fileName);
    rename("temp.txt", fileName);

    printf("Task Updated Successfully!\n");
}

void deleteTask(int taskId)
{
    Task t;
    char fileName[60];

    getFileName(fileName);

    FILE *file = fopen(fileName, "r");
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(file, "%d %s %s %s %d",
                  &t.id, t.title, t.priority, t.dueDate, &t.completed) != EOF)
    {
        if (t.id != taskId)
        {
            fprintf(temp, "%d %s %s %s %d\n",
                    t.id, t.title, t.priority, t.dueDate, t.completed);
        }
    }

    fclose(file);
    fclose(temp);

    remove(fileName);
    rename("temp.txt", fileName);

    printf("Task Deleted Successfully!\n");
}

int main()
{
    int choice, id;

    printf("===== ADVANCED TO-DO LIST (C VERSION) =====\n");

    printf("1. Register\n2. Login\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        registerUser();
    }

    if (!login())
        return 0;

    do
    {
        printf("\n===== MENU =====");
        printf("\n1. Add Task");
        printf("\n2. View Tasks");
        printf("\n3. Complete Task");
        printf("\n4. Delete Task");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            printf("Enter Task ID: ");
            scanf("%d", &id);
            completeTask(id);
            break;

        case 4:
            printf("Enter Task ID: ");
            scanf("%d", &id);
            deleteTask(id);
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