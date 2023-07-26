#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 1053

void handle_dns_query(int sockfd, struct sockaddr_in client_addr, socklen_t client_len)
{
    char buffer[1024] = {0};

    // Receive DNS query from client
    ssize_t bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_len);
    if (bytes_received < 0)
    {
        perror("recvfrom failed");
        return;
    }

    printf("Received DNS query from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    const char *response = "DNS response";
    ssize_t bytes_sent = sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client_addr, client_len);
    if (bytes_sent < 0)
    {
        perror("sendto failed");
        return;
    }

    printf("Sent DNS response to %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
}

int main()
{
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("DNS server listening on port %d\n", PORT);

    // Accept incoming DNS queries and send responses
    while (1)
    {
        handle_dns_query(sockfd, client_addr, client_len);
    }

    close(sockfd);
    return 0;
}