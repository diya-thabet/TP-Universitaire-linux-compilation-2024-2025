#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int n ; 
void handler(int signum){
    printf("experiration en %d secondes \n", n);
    fflush(stdout); 
    exit(0);
}
int main(int argc, char **argv ){
    signal(SIGALRM, handler); 
    n = atoi(*(argv +1)); 
    alarm(n); 
    while(1); 
}