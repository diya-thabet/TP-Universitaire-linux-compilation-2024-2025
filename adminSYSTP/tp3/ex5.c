#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){
    int p1[2], p2[2], p3[2] , t[2], s ,p ; 
    pipe(p1) ; 
    pipe(p2) ; pipe(p3); 
    char msg[30]="" ; 
    p = fork();  
    
    if (fork())
    {
        if (fork())
        {//pere 
            printf("donner moi un message: ");
            gets(msg); 
            close(p1[0]); 
            write(p1[1], msg, sizeof(msg)); 
            clsoe(p1[1]); 
            close(p3[1]); 
            read(p3[0], msg, sizeof(msg));
            close(p3[0]); 
            puts(msg); 
            wait(NULL); 
            wait(NULL); 

        }else{
            //fils 2
            close(p2[1]); 
        }
        
    }
    

}