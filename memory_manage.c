#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define SHRINK_SIZE 6
#define MAX_EMAIL_LENGTH 100

// Function prototypes
char** allocate_email_array(int size);
void free_email_array(char** emails, int size);
char** shrink_email_array(char** emails, int old_size, int new_size);
void display_emails(char** emails, int size);
void input_emails(char** emails, int size);

int main() {
    printf("=== Student Email Management System ===\n");
    printf("Using Dynamic Memory Management for 2023M Cohort\n\n");
    
    // Step 1: Allocate memory for 10 students initially
    printf("1. Allocating memory for %d students...\n", INITIAL_SIZE);
    char** student_emails = allocate_email_array(INITIAL_SIZE);
    
    if (student_emails == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Step 2: Input email addresses for 10 students
    printf("2. Please enter email addresses for %d students:\n", INITIAL_SIZE);
    input_emails(student_emails, INITIAL_SIZE);
    
    // Step 3: Display current emails
    printf("\n3. Current student emails (%d students):\n", INITIAL_SIZE);
    display_emails(student_emails, INITIAL_SIZE);
    
    // Step 4: Shrink the array to 6 students
    printf("\n4. Shrinking array from %d to %d students...\n", INITIAL_SIZE, SHRINK_SIZE);
    char** shrunk_emails = shrink_email_array(student_emails, INITIAL_SIZE, SHRINK_SIZE);
    
    if (shrunk_emails == NULL) {
        printf("Memory reallocation failed!\n");
        free_email_array(student_emails, INITIAL_SIZE);
        return 1;
    }
    
    // Update pointer to point to shrunk array
    student_emails = shrunk_emails;
    
    // Step 5: Display shrunk array
    printf("5. After shrinking (%d students):\n", SHRINK_SIZE);
    display_emails(student_emails, SHRINK_SIZE);
    
    // Step 6: Free all allocated memory
    printf("\n6. Freeing allocated memory...\n");
    free_email_array(student_emails, SHRINK_SIZE);
    
    printf("Program completed successfully!\n");
    
    // Justification for dynamic memory management
    printf("\n=== WHY DYNAMIC MEMORY MANAGEMENT? ===\n");
    printf("1. FLEXIBILITY: Array size can be changed during runtime\n");
    printf("2. EFFICIENCY: Memory is allocated only when needed\n");
    printf("3. SCALABILITY: Can handle varying number of students\n");
    printf("4. MEMORY OPTIMIZATION: Unused memory can be freed\n");
    printf("5. REAL-WORLD APPLICATIONS: Student databases change frequently\n");
    
    return 0;
}

/**
 * Allocates memory for an array of email strings
 * @param size: Number of email addresses to store
 * @return: Pointer to array of string pointers, or NULL if allocation fails
 */
char** allocate_email_array(int size) {
    // Allocate memory for array of string pointers
    char** emails = (char**)malloc(size * sizeof(char*));
    
    if (emails == NULL) {
        printf("ERROR: Failed to allocate memory for email array\n");
        return NULL;
    }
    
    // Allocate memory for each email string
    for (int i = 0; i < size; i++) {
        emails[i] = (char*)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        if (emails[i] == NULL) {
            printf("ERROR: Failed to allocate memory for email %d\n", i + 1);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(emails[j]);
            }
            free(emails);
            return NULL;
        }
        // Initialize with empty string
        strcpy(emails[i], "");
    }
    
    printf("SUCCESS: Memory allocated for %d email addresses\n", size);
    return emails;
}

/**
 * Frees all memory allocated for the email array
 * @param emails: Pointer to the email array
 * @param size: Number of emails in the array
 */
void free_email_array(char** emails, int size) {
    if (emails == NULL) {
        printf("WARNING: Attempted to free NULL pointer\n");
        return;
    }
    
    // Free each individual email string
    for (int i = 0; i < size; i++) {
        if (emails[i] != NULL) {
            free(emails[i]);
            emails[i] = NULL;  // Avoid dangling pointers
        }
    }
    
    // Free the array of pointers
    free(emails);
    printf("SUCCESS: Memory freed for %d email addresses\n", size);
}

/**
 * Shrinks the email array using realloc
 * @param emails: Original email array
 * @param old_size: Current size of the array
 * @param new_size: New smaller size
 * @return: Pointer to resized array, or NULL if reallocation fails
 */
char** shrink_email_array(char** emails, int old_size, int new_size) {
    if (emails == NULL) {
        printf("ERROR: Cannot shrink NULL array\n");
        return NULL;
    }
    
    if (new_size >= old_size) {
        printf("ERROR: New size must be smaller than current size\n");
        return NULL;
    }
    
    // Free memory for emails that will be removed
    for (int i = new_size; i < old_size; i++) {
        if (emails[i] != NULL) {
            free(emails[i]);
            emails[i] = NULL;
        }
    }
    
    // Reallocate the array to smaller size
    char** temp = (char**)realloc(emails, new_size * sizeof(char*));
    
    if (temp == NULL) {
        printf("ERROR: Failed to reallocate memory\n");
        return NULL;
    }
    
    printf("SUCCESS: Array shrunk from %d to %d students\n", old_size, new_size);
    return temp;
}

/**
 * Displays all email addresses in the array
 * @param emails: Array of email strings
 * @param size: Number of emails to display
 */
void display_emails(char** emails, int size) {
    if (emails == NULL) {
        printf("ERROR: Cannot display NULL array\n");
        return;
    }
    
    printf("--- Student Email List ---\n");
    for (int i = 0; i < size; i++) {
        if (emails[i] != NULL && strlen(emails[i]) > 0) {
            printf("Student %d: %s\n", i + 1, emails[i]);
        } else {
            printf("Student %d: [No email entered]\n", i + 1);
        }
    }
    printf("Total students: %d\n", size);
}

/**
 * Inputs email addresses from user
 * @param emails: Array to store emails
 * @param size: Number of emails to input
 */
void input_emails(char** emails, int size) {
    if (emails == NULL) {
        printf("ERROR: Cannot input to NULL array\n");
        return;
    }
    
    char temp_email[MAX_EMAIL_LENGTH];
    
    for (int i = 0; i < size; i++) {
        printf("Enter email for student %d (2023M cohort): ", i + 1);
        
        // Read email with input validation
        if (fgets(temp_email, MAX_EMAIL_LENGTH, stdin) != NULL) {
            // Remove newline character if present
            size_t len = strlen(temp_email);
            if (len > 0 && temp_email[len - 1] == '\n') {
                temp_email[len - 1] = '\0';
            }
            
            // Copy to allocated memory
            strcpy(emails[i], temp_email);
        } else {
            printf("ERROR: Failed to read email for student %d\n", i + 1);
            strcpy(emails[i], "invalid@email.com");
        }
    }
}
