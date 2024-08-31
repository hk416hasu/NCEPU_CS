#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

    // u must check the argv[1] !!!
    // and the return struct

int main(int argc, char *argv[]) {
    printf("argc num is %d\n", argc);
    const char *domain = "example.com"; // Replace with the domain name you want to resolve
    if (argc > 2) {
        printf("Usage: %s [<domain name>]\n", argv[0]);
        return 0;
    } else if (argc == 2) {
        domain = argv[1];
    }
    struct addrinfo hints, *res;
    char ipstr[INET_ADDRSTRLEN];

    // Zero out the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4

    // Get address information
    getaddrinfo(domain, NULL, &hints, &res);

    // Convert the IP to a string
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr));

    // Print the IPv4 address
    printf("IPv4 address for %s: %s\n", domain, ipstr);

    // Free the linked list
    freeaddrinfo(res);

    return 0;
}

