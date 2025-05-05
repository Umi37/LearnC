//op_client.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]){
    int sock;

    struct sockaddr_in serv_addr;

    if (argc != 3){
        printf("사용법: %s <IP><PORT>\n", argv[0]);
        exit(1);
    }
    
    sock = socket(PF_INET, SOCK_STREAM, 0); //sock_stream -> tcp setting | SOCK_DGRAM -> udp setting
    if(sock == -1){
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr)); // 주소에 대한 초기화
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // inet_addr : 중간 중간 .점들을 바꿔주는 함수 // 숫자로 받기에 localhost는 받을 수 없는 형태임 -> 바꾸면 가능
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
        error_handling("connect() error");// listen 상태인 서버에 접속
    }else{
        puts("connected server");
    }
    // 연결된 상태의 코드
    char message[BUF_SIZE];
    int str_len, recv_len, recv_cnt;
    int result, opnd_cnt, i;

    fputs("피연산자 갯수를 넣으세요: ",stdout);
    scanf("%d", &opnd_cnt);
    message[0] = (char)opnd_cnt; // 1byte

    for(i = 0; i < opnd_cnt; ++i){
        printf("%d번째 피연산자를 넣으세요: ", i + 1);
        scanf("%d", (int*)&message[i * 4 + 1]); // 4byte + 1byte(피연산자의 수)
    }
    fgetc(stdin); // 버퍼에 남아있는 개행문자 제거
    fputs("연산자를 넣으세요: ", stdout);
    scanf("%c", &message[opnd_cnt * 4 + 1]);

    write(sock, message, opnd_cnt * 4 + 2); // 피연산자 갯수 + 피연산자 갯수 * 4 + 연산자
    read(sock, &result, 4);

    printf("연산 결과는: %d \n", result);
    close(sock);

    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}