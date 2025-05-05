//echo_client.c
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
    int str_len, recv_len, recv_cnt;

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
    while (1){
        fputs("메시지를 넣으세요(Q 나가기): ",stdout);
        fgets(message, BUF_SIZE, stdin);
        if(!strcmp(message, "Q\n") || !strcmp(message, "q\n")){
            break;
        }
        str_len = write(sock, message, strlen(message)); // 항상 max치인 1024를 보내면 낭비이니 strlen을 사용
        while(recv_len < str_len){ // 송수신 데이터 양이 많을 경우
            recv_len = read(sock, message, BUF_SIZE - 1); 
            if(recv_len == -1){ // 무한루프 돌 수 있으니 유의
                fputs("read() error", stderr);
                break;
            }
            recv_len += recv_cnt; // 잘라서 받는 양이 총 받은 양과 같아질 때까지
        }
        message[str_len] = '\0'; // null termination
        printf("서버에 보낸 메세지: %s\n", message); // debugging message
    }
    close(sock);

    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

//./echo_client 192.168.0.89 8890

/*


*/