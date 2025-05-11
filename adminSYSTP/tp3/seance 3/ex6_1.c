#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int tub;
    mode_t mode;
     mode = S_IRGRP | S_IWUSR; 
     mkfifo("lalala", mode);
     tub = open("lalala", O_WRONLY); // open in write only
    write(tub, "012345789", 10);
    close(tub);
    return 0;
}