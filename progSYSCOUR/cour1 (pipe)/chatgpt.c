#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main() {
    int pipefd[2]; 
    pipe(pipefd);    // pipefd[0] for reading, pipefd[1] for writing
    int pid = fork();

    switch (pid) {
        case -1:  // Fork failed
            perror("fork");
            exit(1);

        case 0:  // Child process
            // Close unused write end
            execlp("ls", "ls", "-la","-h", NULL); 
            break;

        default:  // Parent process
            // Close unused read end
            close(pipefd[0]);

            char message[] = "Hello from Parent!";
            write(pipefd[1], message, sizeof(message));  // Write to pipe
            close(pipefd[1]);

            // Wait for child to finish (optional)
            wait(NULL);
            break;
    }

    return 0;
}
