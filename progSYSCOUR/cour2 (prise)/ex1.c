#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define FIFO1 "/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/cour2 (prise)/fifo1"
#define FIFO2 "/home/dhia/Desktop/Tp Universitaires/progSYSCOUR/cour2 (prise)/fifo2"

int main() {
    char buffer1[30] = "";
    int dL1, dE1;

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    dE1 = open(FIFO1, O_WRONLY);
    dL1 = open(FIFO2, O_RDONLY);

    if (dE1 < 0 || dL1 < 0) {
        perror("erreur !!!");
        exit(1);
    }

    printf("donner votre chaine: ");
    gets(buffer1);
    printf("*** fils : Ecriture dans tube...\n");
    write(dE1, buffer1, sizeof(buffer1));

    printf("*** fils : lecture du tube...\n");
    read(dL1, buffer1, sizeof(buffer1));
    printf("fils : %s\n", buffer1);

    close(dL1);
    close(dE1);

    return 0;
}
