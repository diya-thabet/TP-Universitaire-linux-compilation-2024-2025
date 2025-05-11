#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>


void main(){
    FILE *f = fopen("toto", "a+");
    char ch[5]=""; 
    int p = fork(); 
    switch(p){
        case -1 : 
            printf("Erreur \n"); 
            break ; 
        case 0 : 
            printf("\nProcesus fils mon pid est %d, celui de mon pere est %d\n", getpid(), getppid()); 
            execlp("ls", "ls", "-l", "-h", NULL); 
            break ; 
        default :
            sleep(10); 
            printf("\n ici le procesus pere mon pid est %d, etr celui de mon fils est %d\n", getpid(), p); 
            printf("fin de pere\n") ; 
            wait(NULL);  

    }
    fclose(f); 

    return; 
}