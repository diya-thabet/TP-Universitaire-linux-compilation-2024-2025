#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
    int tub;  
     mkfifo("hahaha", S_IRGRP | S_IWUSR); 
     tub = open("hahaha", O_WRONLY); 
     dup2(tub, 1); 
     close(tub); 
     execlp("ls", "ls", "-l", NULL); 
    return 0; 
}