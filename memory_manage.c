#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define INITIAL_STUDENTS 10
#define REDUCED_STUDENTS 6

// Function to display student emails
void displayEmails(char **emails, int count) {
    printf("\n=== Student Email Addresses ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, emails[i]);
    }
    printf("Total students: %d\n", count);
}

// Function to free memory for all emails
void freeEmailMemory(char **emails, int count) {
    for (int i = 0; i < count; i++) {
        free(emails[i]);
    }
    free(emails);
}

int main() {
    // Sample email addresses for 2023M cohort
    char sampleEmails[INITIAL_STUDENTS][MAX_EMAIL_LENGTH] = {
        "alice@university.edu",
        "alice.1@university.edu",
        "alice.3@university.edu",
        "david@university.edu",
        "david.1@university.edu",
        "david.2@university.edu",
        "grace@university.edu",
        "grace.1@university.edu",
        "grace.2@university.edu",
        "john.1@university.edu"
    };
    
    printf("=== Dynamic Memory Management for Student Emails ===\n");
    printf("2023M Cohort - Initial Setup with %d students\n", INITIAL_STUDENTS);
    
    // Step 1: Allocate memory for array of string pointers using malloc
    char **studentEmails = (char **)malloc(INITIAL_STUDENTS * sizeof(char *));
    if (studentEmails == NULL) {
        printf("Memory allocation failed for email array!\n");
        return 1;
    }
    
    // Step 2: Allocate memory for each email string using malloc
    for (int i = 0; i < INITIAL_STUDENTS; i++) {
        studentEmails[i] = (char *)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        if (studentEmails[i] == NULL) {
            printf("Memory allocation failed for email %d!\n", i + 1);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(studentEmails[j]);
            }
            free(studentEmails);
            return 1;
        }
        strcpy(studentEmails[i], sampleEmails[i]);
    }
    
    printf("\nStep 1: Initial memory allocation completed successfully!\n");
    displayEmails(studentEmails, INITIAL_STUDENTS);
    
    // Step 3: Demonstrate memory reallocation to shrink to 6 students
    printf("\n=== Memory Reallocation Process ===\n");
    printf("Shrinking from %d students to %d students...\n", INITIAL_STUDENTS, REDUCED_STUDENTS);
    
    // Free memory for students 7-10 (indices 6-9)
    for (int i = REDUCED_STUDENTS; i < INITIAL_STUDENTS; i++) {
        free(studentEmails[i]);
        studentEmails[i] = NULL; // Good practice to avoid dangling pointers
    }
    
    // Reallocate the array to smaller size using realloc
    char **resizedEmails = (char **)realloc(studentEmails, REDUCED_STUDENTS * sizeof(char *));
    if (resizedEmails == NULL) {
        printf("Memory reallocation failed!\n");
        freeEmailMemory(studentEmails, REDUCED_STUDENTS);
        return 1;
    }
    studentEmails = resizedEmails;
    
    printf("Step 2: Memory successfully reallocated to %d students!\n", REDUCED_STUDENTS);
    displayEmails(studentEmails, REDUCED_STUDENTS);
    
    // Step 4: Alternative demonstration using calloc
    printf("\n=== Alternative Implementation using calloc ===\n");
    char **callocEmails = (char **)calloc(REDUCED_STUDENTS, sizeof(char *));
    if (callocEmails == NULL) {
        printf("Memory allocation with calloc failed!\n");
        freeEmailMemory(studentEmails, REDUCED_STUDENTS);
        return 1;
    }
    
    // Allocate and copy first 6 emails to demonstrate calloc usage
    for (int i = 0; i < REDUCED_STUDENTS; i++) {
        callocEmails[i] = (char *)calloc(MAX_EMAIL_LENGTH, sizeof(char));
        if (callocEmails[i] == NULL) {
            printf("Memory allocation failed for calloc email %d!\n", i + 1);
            for (int j = 0; j < i; j++) {
                free(callocEmails[j]);
            }
            free(callocEmails);
            freeEmailMemory(studentEmails, REDUCED_STUDENTS);
            return 1;
        }
        strcpy(callocEmails[i], sampleEmails[i]);
    }
    
    printf("Step 3: Alternative allocation with calloc completed!\n");
    displayEmails(callocEmails, REDUCED_STUDENTS);
    
    // Step 5: Memory cleanup - free all allocated memory
    printf("\n=== Memory Cleanup ===\n");
    printf("Freeing all allocated memory...\n");
    
    freeEmailMemory(studentEmails, REDUCED_STUDENTS);
    freeEmailMemory(callocEmails, REDUCED_STUDENTS);
    
    printf("All memory successfully freed!\n");

    printf("\n");

     // Justification for dynamic memory management
    printf("\n=== Why Dynamic Memory Management is Important ===\n");
    printf("1. FLEXIBILITY: Allows runtime memory allocation based on actual needs\n");
    printf("2. EFFICIENCY: Prevents memory waste by allocating only required amount\n");
    printf("3. SCALABILITY: Can handle varying data sizes without recompilation\n");
    printf("4. RESOURCE MANAGEMENT: Enables proper memory cleanup to prevent leaks\n");
    printf("5. OPTIMIZATION: Allows memory reallocation to adapt to changing requirements\n");
    printf("6. DYNAMIC STRUCTURES: Essential for implementing linked lists, trees, etc.\n");
    
    return 0;
}