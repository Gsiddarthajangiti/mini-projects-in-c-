#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 100

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Bank is full!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);

    printf("Enter account holder's name: ");
    getchar(); // to consume the newline character left by the previous input
    fgets(accounts[accountCount].name, NAME_LEN, stdin);
    strtok(accounts[accountCount].name, "\n"); // remove trailing newline

    accounts[accountCount].balance = 0.0;
    accountCount++;
    printf("Account created successfully!\n");
}

void deposit() {
	int i;
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount deposited successfully! New balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accountNumber;
    double amount;
    int i;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! New balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void checkBalance() {
    int accountNumber,i;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void transferFunds() {
    int i,fromAccount, toAccount;
    double amount;

    printf("Enter source account number: ");
    scanf("%d", &fromAccount);

    printf("Enter destination account number: ");
    scanf("%d", &toAccount);

    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);

    Account *source = NULL, *destination = NULL;
    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == fromAccount) {
            source = &accounts[i];
        }
        if (accounts[i].accountNumber == toAccount) {
            destination = &accounts[i];
        }
    }

    if (source && destination) {
        if (source->balance >= amount) {
            source->balance -= amount;
            destination->balance += amount;
            printf("Amount transferred successfully! New balance of source account: %.2lf\n", source->balance);
        } else {
            printf("Insufficient balance in source account!\n");
        }
    } else {
        printf("One or both accounts not found!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nSimple Banking System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Transfer Funds\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                transferFunds();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

