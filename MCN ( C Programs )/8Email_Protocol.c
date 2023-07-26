#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1025

void handle_connection(int client_fd) {
    char buffer[1024];
    int bytes_received;

    // Send welcome message to client
    const char *welcome_message = "220 Welcome to my email server\r\n";
    send(client_fd, welcome_message, strlen(welcome_message), 0);

    // Receive client command and respond
    while ((bytes_received = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';

        // Handle client command
        if (strncmp(buffer, "HELO", 4) == 0) {
            const char *response = "250 Hello\r\n";
            send(client_fd, response, strlen(response), 0);
        } else if (strncmp(buffer, "MAIL FROM:", 10) == 0) {
            const char *response = "250 OK\r\n";
            send(client_fd, response, strlen(response), 0);
        } else if (strncmp(buffer, "RCPT TO:", 8) == 0) {
            const char *response = "250 OK\r\n";
            send(client_fd, response, strlen(response), 0);
        } else if (strncmp(buffer, "DATA", 4) == 0) {
            const char *response = "354 Start mail input; end with <CRLF>.<CRLF>\r\n";
            send(client_fd, response, strlen(response), 0);

            // Receive email message from client
            while ((bytes_received = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
                buffer[bytes_received] = '\0';

                // Check for end of email message
                if (strncmp(buffer, ".\r\n", 3) == 0) {
                    const char *response = "250 OK\r\n";
                    send(client_fd, response, strlen(response), 0);
                    break;
                }
            }
        } else if (strncmp(buffer, "QUIT", 4) == 0) {
            const char *response = "221 Bye\r\n";
            send(client_fd, response, strlen(response), 0);
            break;
        } else {
            const char *response = "500 Command not recognized\r\n";
            send(client_fd, response, strlen(response), 0);
        }
    }

    close(client_fd);
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle them
    printf("Email server listening on port %d\n", PORT);
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("accept");
            continue;
        }

        // Handle client connection
        handle_connection(client_fd);
    }

    close(server_fd);
    return 0;
}