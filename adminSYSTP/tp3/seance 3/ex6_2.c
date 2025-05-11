#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int tub; 
    char zone[11]=""; 
    
     tub = open("lalala", O_RDONLY); 
     read(tub,zone, 11);  
     printf("jai lu le nb %s", zone); 
     close(tub); 
    return 0; 
}