#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server;
    char message[30], server_reply[30];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("on ne peut pas creer le serveur\n");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("erreur\n");
        return 1;
    }

    printf("enter ton message (je suis client): ");
    scanf("%s", message);
    send(sock, message, strlen(message), 0);

    recv(sock, server_reply, sizeof(server_reply), 0);
    printf("reponse du serveur: %s\n", server_reply);

    close(sock);
    return 0;
}
