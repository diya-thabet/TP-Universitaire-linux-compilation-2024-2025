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
            close(tube1[1]) ; 
            printf("fils: lecture de 2 nombres\n");
            read(tube1[0], t, sizeof(t)); 
            close(tube1[0]); 
            s=t[0]+t[1] ; 
            close(tube2[0]); 
            write(tube2[1], &s, sizeof(s)); 
            close(tube2[1]);
            break ; 

        default:  
            close(tube1[0]) ;
            printf("donner 2 entiers: "); 
            scanf("%d%d", t, t+1); //t7ot el addresse mte3 Tab t ok ? 
            write(tube1[1], t, sizeof(t)); 
            close(tube1[1]);   
            close(tube2[1]); 
            read(tube2[0], &s , sizeof(s));
            printf("La somme = %d \n", s);
            close(tube2[0]);   
            
            break ; 
    }

}