//exemple d'execution:
//./a.out  ls -l : wc -l

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int fd[2];
    pipe(fd);
     int delim = -1;
     
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], ":") == 0) {
            delim = i;
            break;
        }
    }
   char *argv1[delim];
    for (int j = 0; j < delim - 1; j++) {
        argv1[j] = argv[j + 1];
    }
    argv1[delim - 1] = NULL;
    char *argv2[argc - delim];
    for (int k = 0; k < argc - delim - 1; k++) {
        argv2[k] = argv[k + delim + 1];
    }
    argv2[argc - delim - 1] = NULL;
    switch (fork()) {
        case -1:
            perror("fork()");
            exit(-1);
        case 0:
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            execvp(argv1[0],argv1);
            break;
        default:
            close(fd[1]); 
            dup2(fd[0], STDIN_FILENO);
            execvp(argv2[0],argv2);
            wait(NULL);
            break;
    }
    return 0;
}