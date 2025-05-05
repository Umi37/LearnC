//hello_server.c
#include <arpa/inet.h>   // IP주소 변환, htonl(), htons() 함수 등을 사용하기 위함
#include <stdio.h>       // printf(), perror() 같은 입출력 함수 사용
#include <stdlib.h>      // exit(), atoi() 같은 함수 사용
#include <string.h>      // memset() 사용
#include <sys/socket.h>  // socket(), bind(), listen(), accept() 같은 소켓 관련 함수 사용
#include <unistd.h>      // close() 함수 사용

int main(int argc, char *argv[]){ // 명령줄에서 프로그램 시작될 때 입력받을 값들을 argc(인자의 개수)와 argv(인자의 내용들)로 전달받음
    int serv_sock; // 서버 소켓 파일 디스크립터
    int clnt_sock; // 클라이언트 소켓 파일 디스크립터

    struct sockaddr_in serv_addr; // sockaddr_in 구조체 안에는 주소 정보를 구성하는 필드(멤버변수) 들이 들어있음 (주소 체계, 포트 번호, IP 주소 구조체)
    struct sockaddr_in clnt_addr; // sockaddr_in 구조체 타입으로 선언된 변수(일종의 객체)로서 주소 정보를 담음
    socklen_t clnt_addr_size;     // 클라이언트 주소 구조체 크기를 담을 변수

    if (argc != 2){ // 명령줄에서 인자를 제대로 입력 받지 않았을 경우 오류 메세지 출력
        printf("사용법: %s <PORT>\n", argv[0]);
        exit(1);    // 반환값 없이 숫자 1을 운영체제 커널에 넘기며 프로그램 종료
    }
    
    // 함수 결과 값 반환하여 성공시 파일 디스크립터(정수) 또는 실패시(-1)을 serv_sock 변수에 저장
    serv_sock = socket(PF_INET, SOCK_STREAM, 0); //sock_stream -> tcp setting | SOCK_DGRAM -> udp setting (socket() 함수에서 두 번째 인자로 무엇을 넣느냐에 따라 소켓이 TCP를 쓸지, UDP를 쓸지 결정됨)
    // IPv4 사용하고, TCP 방식으로 통신할 수 있는 소켓 만들기
    // socket() 호출 전 : 통신할 수단 없음
    // socket() 호출 후 : 통신용 전화기를 하나 만든 셈
    // 아직 누군가와 연결되지 않았고, "준비 완료" 상태

    memset(&serv_addr, 0, sizeof(serv_addr));   // serv_addr 구조체의 모든 필드(멤버변수)를 메모리 차원에서 전부  0으로  초기화
    serv_addr.sin_family = AF_INET;             // 주소 구조체가 어떤 주소 체계 (패밀리)를 따르는지 명시 ==> AF_INET 은 IPv4 주소 체계 를 의미
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 어떤 IP 주소로 바인딩(연결 대기) 할 것인지 설정(모든 네트워크 인터페이스(IP)에서 접속 허용 (0.0.0.0)==> INADDR_ANY)
                                                    // htonl(): 호스트 바이트 순서를 네트워크 바이트 순서로 바꿔주는 함수
    serv_addr.sin_port = htons(atoi(argv[1]));      // htons(): 정수(16비트 포트 번호)를 네트워크 바이트 순서(Big Endian)로 변환(atoi로 배열을 인트로 바꿔서 해당 포트값 지정)

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));   // 포트 재사용 허락 설정(SO_REUSEADDR로 옵션 활성화 ==> 단순히 1과 0으로 키고 켜는 설정이 가능함)
    bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));          // 서버 소켓(serv_sock)을 서버 주소(serv_addr)에 묶어줌
    
    // 서버가 클라이언트 연결을 받기 위해 반복적으로 수행하는 핵심 루프
    while (1)
    {
        listen(serv_sock, 5); // 클라이언트 연결 요청 대기 (두번째 인자 - 백로그 큐 크기 : 연결 요청이 밀릴 때 최대 5명까지 줄 설 수 있음)
        clnt_addr_size = sizeof(clnt_addr); // accept() 호출 전에 클라이언트 주소를 저장할 구조체 clnt_addr의 크기를 계산
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size); // 클라이언트가 접속하면, 연결을 수락하고 새 소켓을 하나 반환

        // 연결된 상태의 코드....
        // char message[] = "Hello, TCP IP!!";
        // write(clnt_sock, message, sizeof(message));
        
        char message[30];                               // 클라이언트에게 받아올 데이터(문자열), 스택에 저장
        read(clnt_sock, message, sizeof(message) - 1);  
        message[30] = '\0';
        printf("서버 받은 메세지: %s \n", message);         // read()는 문자열을 인식하지 않고 그냥 "바이트 덩어리"를 읽을 뿐이라 널문자 삽입 수동으로 해줘야 함
        close(clnt_sock);
    }

    close(serv_sock); // close() 를 호출하지 않으면 소켓이 계속 열린 채로 남고 커널이 파일 디스크립터를 회수하지 못하여 fd 누수 발생
    return 0;
}

//./hello_server 8888