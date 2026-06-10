#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

typedef struct {
    int seatNo;
    char name[50];
    int age;
    int booked;   // 0 = free, 1 = booked
} Seat;

Seat seats[MAX_SEATS];

// Initialize seats
void initSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNo = i + 1;
        seats[i].booked = 0;
    }
}

// Show available seats
void showSeats() {
    printf("\n===== SEAT STATUS =====\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d : %s\n",
               seats[i].seatNo,
               seats[i].booked ? "Booked" : "Available");
    }
}

// Generate PNR
int generatePNR() {
    return rand() % 10000 + 1000;
}

// Book Ticket
void bookTicket() {
    int seat;
    int pnr;
    FILE *file;

    printf("Enter Seat Number (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS || seats[seat - 1].booked) {
        printf("Seat not available!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    scanf("%s", seats[seat - 1].name);

    printf("Enter Age: ");
    scanf("%d", &seats[seat - 1].age);

    seats[seat - 1].booked = 1;

    pnr = generatePNR();

    file = fopen("tickets.txt", "a");
    fprintf(file, "PNR:%d Seat:%d Name:%s Age:%d\n",
            pnr,
            seat,
            seats[seat - 1].name,
            seats[seat - 1].age);
    fclose(file);

    printf("\nTicket Booked Successfully!\n");
    printf("Your PNR is: %d\n", pnr);
}

// Cancel Ticket
void cancelTicket() {
    int seat;
    printf("Enter Seat Number to Cancel: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS || seats[seat - 1].booked == 0) {
        printf("Invalid Seat!\n");
        return;
    }

    seats[seat - 1].booked = 0;
    strcpy(seats[seat - 1].name, "");
    seats[seat - 1].age = 0;

    printf("Ticket Cancelled Successfully!\n");
}

// View Bookings
void viewBookings() {
    FILE *file;
    char ch;

    printf("\n===== ALL BOOKINGS =====\n");

    file = fopen("tickets.txt", "r");

    if (file == NULL) {
        printf("No bookings found!\n");
        return;
    }

    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}

// Admin login
int login() {
    char user[20], pass[20];

    printf("===== ADMIN LOGIN =====\n");

    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("\nLogin Successful!\n");
        return 1;
    }

    printf("\nInvalid Credentials!\n");
    return 0;
}

int main() {
    int choice;

    if (!login()) {
        return 0;
    }

    initSeats();

    do {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====");
        printf("\n1. Show Seats");
        printf("\n2. Book Ticket");
        printf("\n3. Cancel Ticket");
        printf("\n4. View Bookings");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showSeats();
                break;

            case 2:
                bookTicket();
                break;

            case 3:
                cancelTicket();
                break;

            case 4:
                viewBookings();
                break;

            case 5:
                printf("Thank you for using Railway System!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}