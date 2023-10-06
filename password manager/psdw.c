#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct PasswordEntry {
    char website[50];
    char username[50];
    char password[50];
    char email[50];
};

void addPassword(struct PasswordEntry **passwords, int *count) {
    *passwords = realloc(*passwords, (*count + 1) * sizeof(struct PasswordEntry));

    printf("Enter website: ");
    fgets((*passwords)[*count].website, sizeof((*passwords)[*count].website), stdin);

    printf("Enter the e-mail address you've registered with: ");
    fgets((*passwords)[*count].email, sizeof((*passwords)[*count].email), stdin);

    printf("Enter username: ");
    fgets((*passwords)[*count].username, sizeof((*passwords)[*count].username), stdin);

    printf("Enter password: ");
    fgets((*passwords)[*count].password, sizeof((*passwords)[*count].password), stdin);

    (*count)++;

}

void displayPasswords(struct PasswordEntry *passwords, int count) {
    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Email: %s\n", passwords[i].email);
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
        fprintf(file, "%s %s %s %s\n", passwords[i].website, passwords[i].email, passwords[i].username, passwords[i].password);
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
    while (fscanf(file, "%s %s %s %s", entry.website, entry.email, entry.username, entry.password) != EOF) {
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
        printf("------MENU------");
        printf("\n1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Back up your existing passwords\n");
        printf("4. Exit\n");
        printf("-------------");
        printf("\nEnter your choice: ");
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

    const char *mkdirCommand = "sudo mkdir -p /root/";
    int mkdirResult = system(mkdirCommand);
    
    if (mkdirResult != 0) {
        printf("Error creating the destination directory.\n");
        return 1; // You can choose an appropriate error code here
    }

    const char *command3 = "sudo cp passwords.txt /root/rootPswd.txt -v";
    int backupRoot = system(command3);
    printf("\n", backupRoot);

    for (int i = 0; i < 10; i++) {
        printf("\rBacking up...... %d%%", i * 10);
        fflush(stdout);
        usleep(500000);
    }
    printf("\nBackup complete.\n");





        



        } else if (choice == 4) {
            printf("Exiting...\n");
            free(passwords);
            exit(0);



        } else {
            printf("Invalid input\n");
        }
    }


