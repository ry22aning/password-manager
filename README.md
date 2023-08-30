# password-manager
Functionality:

    Data Structure: The code defines a struct PasswordEntry to hold website, username, password, and email information.
    Adding Passwords: The addPassword function allows users to input website, email, username, and password data. It reallocates memory to accommodate the new entry.
    Displaying Passwords: The displayPasswords function prints the stored password information.
    Saving to File: The savePasswordsToFile function writes the password entries to a text file named "passwords.txt."
    Loading from File: The loadPasswordsFromFile function reads password entries from the file "passwords.txt" into memory.
    Menu Interface: The main function presents a menu to the user with options to add passwords, display passwords, create backups, or exit the program.

Cybersecurity Aspects:

    Input Validation: The code lacks proper input validation for user inputs (e.g., choices, password entries). This could lead to buffer overflows or other vulnerabilities if not handled properly.
    Sensitive Data Handling: Passwords and other sensitive information are stored in plain text within the program's memory and in the "passwords.txt" file. Storing passwords in plaintext is a significant security risk.
    Memory Management: The code uses realloc to manage memory for password entries. However, there's no handling of memory errors or freeing memory when the program terminates.
    File Handling: File operations lack error handling. If file operations fail, the program continues execution without notifying the user.
    System Commands: The program uses system commands to perform actions such as clearing the screen, creating directories, copying files, and displaying ASCII art. Running system commands without proper validation and input sanitization can lead to command injection vulnerabilities.
    Root Privileges: The code uses sudo to execute certain commands with root privileges. This raises security concerns as it grants potentially unnecessary permissions to the program.
    Backup Process: The backup process could be enhanced by using secure methods for data transfer, encryption, and integrity verification. The current backup mechanism lacks proper error handling and doesn't provide enough security.

Security Recommendations:

    Hashed and Salted Passwords: Store hashed and salted passwords instead of plain text.
    Input Sanitization: Validate and sanitize user inputs to prevent buffer overflows and injection attacks.
    Secure Memory Handling: Clear sensitive information from memory after use.
    Encryption: Encrypt stored passwords and sensitive data.
    File Operations: Implement proper error handling for file operations.
    Avoid Excessive Privileges: Minimize the use of root privileges and validate inputs before executing system commands.
    Backup Process: Implement a secure backup mechanism, including encryption and authentication, when transferring files.


