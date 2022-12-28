#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char* ch = "A111\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(40000);
    len = sizeof(address);
    printf("Connecting to server...\n");
    result = connect(sockfd, (struct sockaddr *)&address, len);
    printf("result = %d\n", result);
    if (result == -1)
    {
        perror("oops: client1");
        exit(1);
    }
    int res = write(sockfd, ch, strlen(ch));
    printf("write res: %d\n", res);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);
    exit(0);
}
