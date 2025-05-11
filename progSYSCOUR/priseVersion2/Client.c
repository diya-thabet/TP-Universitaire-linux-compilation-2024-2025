#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> //home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/
#include <fcntl.h> 
int main(){
char buffer1[30]; char buffer2[30]; 
int d_L1,d_E1;
mkfifo("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo1",0666);
mkfifo("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo2",0666);

d_E1=open("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo1",O_WRONLY);
d_L1=open("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo2",O_RDONLY);

 printf("donner votre chaine moi client\n");
 scanf("%s",buffer1);
 printf("client : Ecriture dans tube\n");
 write(d_E1,buffer1,20);
 
 
  printf("client: Lecture tube\n");
  read(d_L1,buffer1,sizeof(buffer1));
  printf("client: %s\n",buffer1);
 

close(d_L1);
close(d_E1);


unlink("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo1");
unlink("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo2");
return 0;
}
