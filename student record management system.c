#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define ID_LEN 20
#define NAME_LEN 100

typedef struct {
    char id[ID_LEN];
    char name[NAME_LEN];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter student ID: ");
    fgets(students[studentCount].id, ID_LEN, stdin);
    strtok(students[studentCount].id, "\n"); // remove trailing newline

    printf("Enter student name: ");
    fgets(students[studentCount].name, NAME_LEN, stdin);
    strtok(students[studentCount].name, "\n"); // remove trailing newline

    printf("Enter student GPA: ");
    while (scanf("%f", &students[studentCount].gpa) != 1) {
        clearInputBuffer(); // Clear the input buffer if input is invalid
        printf("Invalid input. Enter student GPA: ");
    }
    clearInputBuffer(); // Clear the input buffer

    studentCount++;
    printf("Student added successfully!\n");
}

void deleteStudent() {
	int i,j;
    char id[ID_LEN];
    printf("Enter student ID to delete: ");
    fgets(id, ID_LEN, stdin);
    strtok(id, "\n"); // remove trailing newline

    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for ( j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void updateStudent() {
    char id[ID_LEN];
    int i;
    printf("Enter student ID to update: ");
    fgets(id, ID_LEN, stdin);
    strtok(id, "\n"); // remove trailing newline

    for ( i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Enter new name: ");
            fgets(students[i].name, NAME_LEN, stdin);
            strtok(students[i].name, "\n"); // remove trailing newline

            printf("Enter new GPA: ");
            while (scanf("%f", &students[i].gpa) != 1) {
                clearInputBuffer(); // Clear the input buffer if input is invalid
                printf("Invalid input. Enter new GPA: ");
            }
            clearInputBuffer(); // Clear the input buffer

            printf("Student record updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void displayStudents() {
	int i;
    if (studentCount == 0) {
        printf("No students in the list.\n");
        return;
    }

    printf("Student records:\n");
    for ( i = 0; i < studentCount; i++) {
        printf("ID: %s, Name: %s, GPA: %.2f\n",
               students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer(); // Clear the input buffer if input is invalid
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

