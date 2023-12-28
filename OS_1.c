/*Implement the process system calls fork (), exec () and wait ()*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    // Fork a child process
    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Hello from Child\n");
        printf("Child Process Id is %d\n", getpid());
        printf("Parent Process Id is %d\n", getppid());

        // Replace the child process with a new program using exec
        char *args[] = {"ls", "-l", NULL};
        if (execvp("ls", args) == -1)
        {
            printf("Exec failed");
        }
    }
    else
    {
        // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("Hello from Parent\n");
        printf("Parent Process Id is %d\n", getpid());
    }

    return 0;
}
