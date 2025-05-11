#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void handler(int signum) {
    printf("processus %d \n", getpid());
}

int main() {
    signal(SIGALRM, handler);
    alarm(5); 
    pid_t pid = fork();

    switch (pid) {
        case -1:
            perror("erreur de fork");
            exit(0);

        case 0:
            
            printf("je suis le processus enfant, PID = %d\n", getpid());
            //alarm(5);
            pause();
            break;

        default:
            
            printf("je suis le processus pere, PID = %d, enfant = %d\n", getpid(), pid);
            //alarm(5);
            pause();
            break;
    }

    return 0;
}
