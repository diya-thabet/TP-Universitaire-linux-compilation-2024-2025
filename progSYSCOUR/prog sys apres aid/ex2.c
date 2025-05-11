#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>       
#include <string.h>  

int handle; 

void handler(int signum){
    printf("pas de saisie dans les 5 secondes\n"); 
    close(handle); 
}

int main(int argc, char **argv){
    char chaine[20]; 
    signal(SIGALRM, handler) ; 
    alarm(5) ; 
    printf("donner une chaine...\n"); 
    scanf("%s", chaine); 
    alarm(0); 
    handle= open("junk", O_CREAT|O_WRONLY); 
    write(handle, chaine, strlen(chaine)); 
    close(handle); 
    return 0; 
}