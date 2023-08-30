else if (choice == 3) {
            //printf("Backing up your data into your root folder......\n");
            const char *command3 = "sudo -i cp ~/Downloads/password manager/passwords.txt /root/rootPswd.txt -v";
             int backupRoot = system(command3);
            printf("\n", backupRoot);