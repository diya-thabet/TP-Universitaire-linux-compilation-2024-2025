#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define FIFO1 "/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/cour2 (prise)/fifo1"
#define FIFO2 "/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/cour2 (prise)/fifo2"

int main() {
    char buffer1[30]="";
    int dL1, dE1;

    dE1 = open(FIFO1, O_RDONLY);
    dL1 = open(FIFO2, O_WRONLY);

    if (dE1 < 0 || dL1 < 0) {
        perror("erreur :(");
        exit(1);
    }

    printf("*** fils : lecture du tube...\n");
    read(dE1, buffer1, sizeof(buffer1));
    printf("fils : %s\n", buffer1);

    printf("donner votre chaine : ");
    gets(buffer1);
    printf("*** fils : ecriture dans tube...\n");
    write(dL1, buffer1, sizeof(buffer1));

    close(dL1);
    close(dE1);

    return 0;
}
