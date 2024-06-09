#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void){
    char ip[32];
    printf("Portscanner by zack :p\nEnter the ip : ");
    fgets(ip, 32, stdin);
    for (int i = 20; i < 65535; i++){
        int sock, ret;
        sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in teste;
        teste.sin_family = AF_INET;
        teste.sin_addr.s_addr = inet_addr(ip);
        teste.sin_port = htons(i);
        sleep(1);
        ret = connect(sock, (struct sockaddr *)&teste, sizeof(teste));
        if (ret == 0){
            printf("[ + ] Port %d is open\n", i);
            close(sock);
        }
        else if (ret == -1){
            close(sock);
            continue;    
        }
    }
    return 0;
}
