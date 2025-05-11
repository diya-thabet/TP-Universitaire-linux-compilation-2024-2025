#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>

void main(){
    char buffer[100]="" ; int fd[2]; int p[2] ; pipe(p) ; 
    pipe(fd) ; pipe(p); 
    switch(fork()){
        //case -1 : printf("ERROR\n") ; exit(-1) ; 
        case 0 : 
            sleep(5);
            close(fd[1]) ; 
            printf("fils: lecture tube\n");
            read(fd[0], buffer, sizeof(buffer)); 
            printf("fils: %s\n", buffer); 

            // bidirectionnel
            close(p[0]); 
            printf("fils: donner votre chaine de caractere\n");
            gets(buffer); 
            printf("fils: ecriture dans la tube ");  
            write(p[1], buffer, 20); 
            break ; 

        default:  
            close(fd[0]) ; 
            printf("pere: donner votre chaine de caractere\n");
            gets(buffer); 
            printf("pere: ecriture dans la tube "); 
            write(fd[1], buffer, 20); 


            //buffer="";
            wait(NULL) ;
            //bidirectionnel
            close(p[1]) ; 
            printf("pere: lecture tube\n");
            read(p[0], buffer, sizeof(buffer)); 
            printf("pere: %s\n", buffer); 
            //wait(NULL) ; 

            break ; 
    }

}