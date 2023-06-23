#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Forking failed
        fprintf(stderr, "Forking process failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
        printf("Executing child process...\n");

        // Perform some task in the child process
        // ...

        sleep(5); // Simulating some work

        printf("Child process completed.\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID: %d\n", pid);
        printf("Waiting for child process to complete...\n");

        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process finished successfully.\n");
        } else {
            printf("Child process terminated abnormally.\n");
        }

        printf("Parent process completed.\n");
    }

    return 0;
}
