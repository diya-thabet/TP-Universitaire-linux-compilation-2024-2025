#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){
    int tube1[2], tube2[2], t[2], s ,p ; 
    pipe(tube1) ; 
    pipe(tube2) ;
    p = fork();  
    switch(p){
        case -1 : printf("Errueur! \n"); break;
        case 0 : 
            dup2(tube1[1], 1) ; 
            close(tube1[1]); 
            close(tube1[0]);
            execlp("ls", "ls", "-l", NULL); 
            break ; 

        default:  
            dup2(tube1[0], 0);
            close(tube1[0]);
            close(tube1[1]); 
            execlp("wc", "wc", "-l", NULL); 
            wait(NULL);   
            
            
            break ; 
    }

}