#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For usleep function in loading
#include <stdbool.h> // For boolean type
#include <ctype.h>

int isStrongPassword(const char *password) {
    int length = strlen(password);
    int hasDigit = 0;
    int hasLower = 0;
    int hasUpper = 0;
    int hasSpecial = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isupper(password[i])) {
            hasUpper = 1;
        } else if (ispunct(password[i])) {
            hasSpecial = 1;
        }
    }

    // Check password strength based on criteria
    if (length >= 8 && hasDigit && hasLower && hasUpper && hasSpecial) {
        return 1; // Strong password
    } else {
        return 0; // Weak password
    }
}

struct PasswordEntry {
    char email[50];
    char website[50];
    char username[50];
    char password[50];
};




void addPassword(struct PasswordEntry **passwords, int *count) {
    *passwords = realloc(*passwords, (*count + 1) * sizeof(struct PasswordEntry));

    char password[50];


    printf("Enter the E-mail you've regestered with: ");
    scanf("%s", (*passwords)[*count].email);

    printf("Enter website: ");
    scanf("%s", (*passwords)[*count].website);

    printf("Enter username: ");
    scanf("%s", (*passwords)[*count].username);

    printf("Enter password: ");
    scanf("%s", (*passwords)[*count].password);

    if (isStrongPassword(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Hey dear terminal user, how could you password be still weak if you're running this 80's looking program.\n");
    }


    (*count)++;
}

void displayPasswords(struct PasswordEntry *passwords, int count) {
    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s\n", passwords[i].email);
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

void savePasswordsToFile(struct PasswordEntry *passwords, int count) {
    FILE *file = fopen("passwords.txt", "w");
    //SetFileAttributes("passwords.txt", FILE_ATTRIBUTE_HIDDEN);

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %s\n",passwords[i].email, passwords[i].website, passwords[i].username, passwords[i].password);
    }

    fclose(file);
}

void loadPasswordsFromFile(struct PasswordEntry **passwords, int *count) {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No saved passwords found.\n");
        return;
    }

    struct PasswordEntry entry;
    while (fscanf(file, "%s %s  %s %s", entry.email, entry.website, entry.username, entry.password) != EOF) {
        *passwords = realloc(*passwords, (*count + 1) * sizeof(struct PasswordEntry));
        (*passwords)[*count] = entry;
        (*count)++;
    }

    fclose(file);
}

int main() {


    struct PasswordEntry *passwords = NULL;
    int count = 0;
    int choice;
        loadPasswordsFromFile(&passwords, &count);

        const char *command22 = "figlet Pswd Manager";
        int figletwelcome = system(command22);

        printf("", figletwelcome);
        //printf("\nWelcome to Password Manager\n\n");
        while (1) {
            printf("------MENU------\n");
            printf("1. Add Password\n");
            printf("2. Display Passwords\n");
            printf("3. Back up your existing passwords\n");
            printf("4. Exit\n");
            printf("-------------\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

             if (choice == 1) {

            //using bash commands
            const char *command = "clear";
            int exitCode = system(command);
            printf("\n", exitCode);
            addPassword(&passwords, &count);
            savePasswordsToFile(passwords, count);


            
        } else if (choice == 2) {
            displayPasswords(passwords, count);

        }
            else if (choice == 3) {
            //printf("Backing up your data into your root folder......\n");
           // const char *command3 = "sudo cp ~/Desktop/passwords.txt /root/rootPswd.txt ";   
            const char *command3 = "sudo cp ~/Downloads/password manager/passwords.txt /root/rootPswd.txt";
             int backupRoot = system(command3);
            printf("\n", backupRoot);

        for (int i = 0; i < 10; i++) { //For the loading function of backup 
        printf("\rBacking up...... %d%%", i * 10);
        fflush(stdout); // Flush the output to make sure it's immediately visible
        usleep(500000); // Sleep for 0.5 seconds
    }
    printf("\nBackup complete.\n");



        } 
        
        else if (choice == 4) {
            printf("Exiting...\n");
            free(passwords);
            exit(0);


        }

        
        else {
            printf("Invalid input\n");
        }
    }
}

    



