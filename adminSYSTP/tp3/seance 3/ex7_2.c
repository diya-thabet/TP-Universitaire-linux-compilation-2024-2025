#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
    int tub; 
    char zone[11]=""; 
    
     tub = open("hahaha", O_RDONLY); 
     dup2(tub, 0); 
     close(tub); 
     execlp("wc", "wc", "-l", NULL); 
    return 0; 
}