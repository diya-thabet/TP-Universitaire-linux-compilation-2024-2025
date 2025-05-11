#include<unistd.h>
#include<stdio.h>


void main(){
    FILE *f = fopen("toto", "a+");
    char ch[5]=""; 
    int p = fork(); 
    switch(p){
        case -1 : 
            printf("Erreur \n"); 
            break ; 
        case 0 : 
            printf("\nProcesus fils :\n"); 
            fputs("ab", f); 
            sleep(5); 
            rewind(f) ; 
            fgets(ch, 3, f); 
            puts(ch); 
            break ; 
        default :
            sleep(10); 
            printf("\n procesus pere:\n"); 
            rewind(f);
            fgets(ch, 3, f); 
            puts(ch); 
            fputs("AB", f); 
            wait();  

    }
    fclose(f); 

    return; 
}