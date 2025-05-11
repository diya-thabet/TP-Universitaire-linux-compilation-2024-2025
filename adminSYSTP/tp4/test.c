#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>


void main(){
    int tube1[2], tube2[2], t[2], s ,p ; 
    pipe(tube1) ; 
    pipe(tube2) ;
    p = fork();  
    switch(p){
        case -1 : printf("Errueur! \n"); break;
        
        default:  
             
            char ss[30]=""; 
            close(tube1[0]);
            read(tube1[0],&ss, sizeof(ss) );
            printf("hello nihaha");
            break ; 
        
    }

}