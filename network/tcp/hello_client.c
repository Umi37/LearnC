//hello_client.c
#include <arpa/inet.h>   // IP주소 변환, htonl(), htons() 함수 등을 사용하기 위함
#include <stdio.h>       // printf(), perror() 같은 입출력 함수 사용
#include <stdlib.h>      // exit(), atoi() 같은 함수 사용
#include <string.h>      // memset() 사용
#include <sys/socket.h>  // socket(), bind(), listen(), accept() 같은 소켓 관련 함수 사용
#include <unistd.h>      // close() 함수 사용

int main(int argc, char *argv[]){
    int serv_sock;
    int clnt_sock; // 필요 없는 변수 선언
    /*
    클라이언트는 자신이 직접 연결할 "서버 소켓(serv_sock)" 하나만 만들면 됨.
    클라이언트 측에서는 별도로 새로운 소켓이 accept()를 통해 만들어지지 않음.

    즉, **클라이언트 입장에서의 "서버 소켓"**은

    서버 프로그램이 실행 중인 컴퓨터에 있는 소켓이 아니라,
    서버 프로그램과 연결된 "통신용 소켓"을 의미함.

    따라서 serv_sock만으로도 충분히 모든 작업이 가능하고,
    clnt_sock은 전혀 쓰이지 않아요.
    */

    struct sockaddr_in serv_addr;   // 서버 주소 정보를 담을 구조체 변수

    // 명령줄 인자의 개수가 올바르지 않으면 사용법 안내 후 종료
    if (argc != 3){
        printf("사용법: %s <IP><PORT>\n", argv[0]); // ex) ./hello_client 127.0.0.1 8888
        exit(1); // 오류 코드 1을 반환하며 비정상 종료
    }
    
    // 소켓 생성: IPv4(PF_INET), TCP(SOCK_STREAM), 기본 프로토콜(0)
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    // serv_addr 구조체를 0으로 초기화하여 쓰레기값 제거
    memset(&serv_addr, 0, sizeof(serv_addr));       // 주소에 대한 초기화
    serv_addr.sin_family = AF_INET;                 // 주소 체계 설정 (IPv4 사용)
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // 문자열 IP 주소를 32비트 정수형으로 변환 (inet_addr() : 중간 중간 .점들을 바꿔주는 함수 // 숫자로 받기에 localhost는 받을 수 없는 형태임 -> 바꾸면 가능)
    serv_addr.sin_port = htons(atoi(argv[2]));      // 문자열 포트 번호를 정수로 바꾼 뒤, 네트워크 바이트 순서로 변환

    // 서버에 연결 요청 (3-way handshake 수행됨)
    connect(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); // connect: listen 상태인 서버에 접속
    
    // 서버로 보낼 메시지를 정의하고 전송
    char message[] = "강사님집에갈까요";            // 전송할 문자열 메시지
    write(serv_sock, message, sizeof(message)); // 메시지를 서버로 전송

    // 전송한 메시지를 확인 차 콘솔에 출력
    printf("서버에 보낸 메세지: %s\n", message);

    // 사용한 소켓 리소스 반환
    close(serv_sock);

    return 0;
}

//./hello_client  127.0.0.1 8888

/* ss -s : 소켓 정보 출력
aa@aa-virtual-machine:~/Big2025/build/network$ ss -s
Total: 899
TCP:   10 (estab 3, closed 0, orphaned 0, timewait 0)

Transport Total     IP        IPv6
RAW       1         0         1        
UDP       6         4         2        
TCP       10        9         1        
INET      17        13        4        
FRAG      0         0         0        

ss - t: tcp 정보 출력
aa@aa-virtual-machine:~/Big2025/build/network$ ss -t
State  Recv-Q  Send-Q   Local Address:Port     Peer Address:Port  Process  
ESTAB  0       0         192.168.0.89:55834   13.107.253.49:https     


ss -tulpm : 전체 정보 출력


ss -tulpn : 


*/