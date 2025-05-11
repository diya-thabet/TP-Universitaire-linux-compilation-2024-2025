#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 
int main(){
char buffer1[30]; char buffer2[30]; 
int d_L1,d_E1;
mkfifo("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo1",0666);
mkfifo("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo2",0666);
d_E1= open("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo1",O_RDONLY);
d_L1= open("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo2",O_WRONLY);



printf("serveur: Lecture tube\n");
  read(d_E1,buffer1,sizeof(buffer1));
  printf("serveur: %s\n",buffer1);

 printf("donner votre chaine moi serveur\n");
 scanf("%s",buffer1);
 printf("serveur: Ecriture dans tube\n");
 write(d_L1,buffer1,20);
 
 
 

close(d_L1);
close(d_E1);

unlink("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo1");
unlink("/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/prise version 2/fifo2");
return 0;
}