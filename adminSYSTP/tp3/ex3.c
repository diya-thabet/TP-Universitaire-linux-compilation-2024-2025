#include<stdio.h>
#include<unistd.h>

int main(){
    int tube[2];
    char cl, buf[20] = ""; 
    pipe(tube) ;
    int p = fork(); 
    //printf("%d", p) ; 
    switch (p)
    {
    case -1:
        printf("**************** erreur !!! ****************");
        break; 

    case 0 : //fils
        close(tube[1]); 
        while((read(tube[0], &cl , sizeof(char)))!=0) printf("%c", cl);
        printf("%s bien recu \n");
        close(tube[0]); 
        break;
    
    default: // pere
        printf("donner chaine de caractere: "); 
        close(tube[0]); 
        gets(buf); 
        write(tube[1], buf , sizeof(buf)); 
        close(tube[1]); 
        wait();
    }
    return 0; 
}