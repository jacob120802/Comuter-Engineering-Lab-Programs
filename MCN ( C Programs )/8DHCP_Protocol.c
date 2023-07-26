#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define CLIENT_PORT 54321
#define SERVER_PORT 12345
#define MAX_MESSAGE_SIZE 1024

struct dhcp_packet {
    uint8_t type;
};

void handle_discover(struct dhcp_packet *packet) {
    printf("Handling DHCP Discover\n");
}

void handle_request(struct dhcp_packet *packet) {
    printf("Handling DHCP Request\n");
}

void handle_release(struct dhcp_packet *packet) {
    printf("Handling DHCP Release\n");
}

int main() {
    int server_fd;
    struct sockaddr_in server_addr;
    struct dhcp_packet packet;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket to server port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("DHCP server listening on port %d\n", SERVER_PORT);

    // Main loop
    while (1) {
        // Receive DHCP packet from client
        memset(&packet, 0, sizeof(packet));
        ssize_t num_bytes = recvfrom(server_fd, &packet, sizeof(packet), 0, NULL, NULL);
        if (num_bytes < 0) {
            perror("recvfrom failed");
            continue;
        }

        // Determine the DHCP message type
        uint8_t message_type = packet.type;

        switch (message_type) {
            case 1:
                handle_discover(&packet);
                break;
            case 3:
                handle_request(&packet);
                break;
            case 5:
                handle_release(&packet);
                break;
            default:
                printf("Unsupported DHCP message type\n");
                break;
        }
    }

    return 0;
}