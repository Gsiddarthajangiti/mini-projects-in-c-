#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define ISBN_LEN 20

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char isbn[ISBN_LEN];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    
    printf("Enter book title: ");
    getchar(); // to consume the newline character left by the previous input
    fgets(library[bookCount].title, TITLE_LEN, stdin);
    strtok(library[bookCount].title, "\n"); // remove trailing newline

    printf("Enter book author: ");
    fgets(library[bookCount].author, AUTHOR_LEN, stdin);
    strtok(library[bookCount].author, "\n");

    printf("Enter book ISBN: ");
    fgets(library[bookCount].isbn, ISBN_LEN, stdin);
    strtok(library[bookCount].isbn, "\n");

    bookCount++;
    printf("Book added successfully!\n");
}

void deleteBook() {
	int i,j;
    char isbn[ISBN_LEN];
    printf("Enter ISBN of the book to delete: ");
    getchar(); // to consume the newline character left by the previous input
    fgets(isbn, ISBN_LEN, stdin);
    strtok(isbn, "\n");

    for ( i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            for ( j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void searchBook() {
	int i;
    char isbn[ISBN_LEN];
    printf("Enter ISBN of the book to search: ");
    getchar(); // to consume the newline character left by the previous input
    fgets(isbn, ISBN_LEN, stdin);
    strtok(isbn, "\n");

    for ( i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN: %s\n", library[i].isbn);
            return;
        }
    }
    printf("Book not found!\n");
}

void displayBooks() {
	int i;
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Books in the library:\n");
    for (i = 0; i < bookCount; i++) {
        printf("Title: %s, Author: %s, ISBN: %s\n",
               library[i].title, library[i].author, library[i].isbn);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

