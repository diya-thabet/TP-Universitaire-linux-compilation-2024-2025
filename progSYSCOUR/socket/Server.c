#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char client_message[30], message[30];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("on ne peut pas creer le serveur\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("erreur\n");
        return 1;
    }

    listen(socket_desc, 3);

    printf("je la en port 8888, donner moi une reponse svp :)\n");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0) {
        printf("erreur d'acceptation\n");
        return 1;
    }

    recv(client_sock, client_message, sizeof(client_message), 0);
    printf("message de client: %s\n", client_message);

    printf("entrer votre message (je suis server): ");
    scanf("%s", message);
    send(client_sock, message, strlen(message), 0);

    close(client_sock);
    close(socket_desc);
    return 0;
}
