#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define _XOPEN_SOURCE 600

#include "Commands.h" // Include the linked list header file
#include "Command.cpp" // Include the linked list source file

int main(int argc, char** argv) {
    char* tokens;
    char* selection[10];
    char* command = (char*)malloc(81 * sizeof(char));
    pid_t pid;
    int idList[5];
    int a = 0;
    char* currDir = (char*)malloc(81 * sizeof(char)); // Allocating memory for 80 characters
    int execStatus;
    int* status;

    if ((getcwd(currDir, 1000)) == NULL) {
        printf("we got an erroooooorr :( \n");
    }

    // Allocate memory for the string
    for (int i = 0; i < 10; i++) {
        selection[i] = (char*)malloc(81 * sizeof(char)); // Allocating memory for 80 characters
        selection[i] = NULL;
    }

    while (1) {
        printf("prompt$ ");
        char* str = (char*)malloc(1000 * sizeof(char));
        fgets(str, 1000, stdin); // Read user input

        tokens = strtok(str, " ");
        int i = 0;
        while (tokens != NULL) {
            if (i == 0) {
                command = strdup(tokens);
            }
            selection[i] = strdup(tokens);
            tokens = strtok(NULL, " ");
            i++;
        }

        //error check
        if (strncmp(str, "exit", 4) == 0) {
            printf("Exiting!\n");
            break;
        }

        //print check for arg parsing
        printf("Command: %s ", command);
        for (int j = 0; j < i; j++) {
            //arguments are parsed int
            printf("\"%s\" ", selection[j]);
        }

        //Check for commands: cd or ls -al
        if (strcmp(command, "cd") == 0) {
            //CHANGE TO TAKE 1 PARAMETER
            chgDir(selection[1], currDir);
        }
        else if (strcmp(command, "showpid") == 0) {
            showpid(idList);
        }

        //create new Process
        else {
            if ((pid = fork()) == 0) {
                execStatus = execvp(command, selection);
                if (execStatus == -1) {            //error handle
                    printf("Error: Command could not be executed\n");
                    exit(EXIT_FAILURE);
                }
                kill(pid, SIGTERM);
            }
            else {
                if (a == 5) {
                    a = 0;
                }
                idList[a] = pid;
                a++;
                waitpid(pid, status, 0);
            }
        }
    }

    // Free allocated memory
    free(command);
    for (int i = 0; i < 10; i++) {
        free(selection[i]);
    }
    free(currDir);

    return 0;
}
