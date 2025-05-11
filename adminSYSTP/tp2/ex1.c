#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>



void main(){
    int p , i;  
    p = fork(); 
    switch(p){
        case -1 : 
            printf("Erreur: echec du fork() \n"); 
            break ; 

        case 0 : /*proc fils*/
            sleep(2);
            printf("procesus fils: \n mon PID est %d celui de mon pere est %d \n", getpid(), getppid()); 
            printf("***fin fils    \n"); 
            break; 
        
        default: /*pricesus pere*/
            
            //sleep(1); 
            printf("Ici le pere: \n mon PID est %d, mon fils est %d\n", getpid(), p);
            printf("***fin de pere.\n");
             
            wait(NULL);

    }
    return; 
}