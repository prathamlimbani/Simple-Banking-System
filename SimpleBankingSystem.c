#include <stdio.h>
#include <stdlib.h>

float balance = 0.0f;

// Function Prototypes
void showMenu();
void viewBalance();
void depositMoney();
void withdrawMoney();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        showMenu();  // Display the menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear buffer after reading integer

        switch (choice) {
            case 1:
                viewBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);  // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void showMenu() {
    printf("\n--- Simple Banking System ---\n");
    printf("1. View Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

// Function to display the current balance
void viewBalance() {
    printf("\nCurrent Balance: $%.2f\n", balance);
}

// Function to deposit money
void depositMoney() {
    float amount;

    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);
    clearInputBuffer();  // Clear the buffer after reading float

    if (amount <= 0) {
        printf("Invalid amount! Deposit must be positive.\n");
    } else {
        balance += amount;
        printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, balance);
    }
}

// Function to withdraw money
void withdrawMoney() {
    float amount;

    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);
    clearInputBuffer();  // Clear buffer after reading float

    if (amount <= 0) {
        printf("Invalid amount! Withdrawal must be positive.\n");
    } else if (amount > balance) {
        printf("Insufficient funds! Your current balance is $%.2f.\n", balance);
    } else {
        balance -= amount;
        printf("Successfully withdrew $%.2f. New Balance: $%.2f\n", amount, balance);
    }
}

// Function to clear the input buffer to avoid leftover characters
void clearInputBuffer() {
    while (getchar() != '\n');
}
