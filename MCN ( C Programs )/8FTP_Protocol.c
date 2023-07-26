#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 63500

int main()
{
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char server_response[BUFSIZ];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        perror("Could not create socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Bind failed");
        return 1;
    }

    listen(socket_desc, 3);

    printf("FTP Server listening on port %d\n", SERVER_PORT);

    while (1)
    {
        c = sizeof(struct sockaddr_in);
        client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
        if (client_sock < 0)
        {
            perror("Accept failed");
            return 1;
        }

        printf("New connection accepted\n");

        // Send welcome message
        strcpy(server_response, "220 Welcome to the FTP server\r\n");
        ssize_t bytes_written = write(client_sock, server_response, strlen(server_response));
        if (bytes_written < 0)
        {
            perror("Write failed");
            // close(client_sock);
            continue;
        }

        // Close the connection
        strcpy(server_response, "221 Goodbye\r\n");
        bytes_written = write(client_sock, server_response, strlen(server_response));
        if (bytes_written < 0)
        {
            perror("Write failed");
        }
        // close(client_sock);
    }

    return 0;
}