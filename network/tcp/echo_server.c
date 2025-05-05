//echo_server.c
#include <stdio.h>       // printf(), perror(), fputs() 등 표준 입출력 함수 사용
#include <stdlib.h>      // exit(), atoi() 등 프로그램 종료 및 변환 함수 사용
#include <sys/socket.h>  // socket(), bind(), listen(), accept() 등 소켓 관련 함수
#include <arpa/inet.h>   // htonl(), htons(), inet_ntoa() 등 네트워크 바이트 변환 함수
#include <unistd.h>      // close() 함수 사용
#include <string.h>      // memset() 함수 사용

// 메시지 송수신 시 사용할 버퍼의 최대 크기 정의
#define BUF_SIZE 1024

// 에러 메시지를 출력하고 프로그램을 종료하는 함수 선언
void error_handling(char *message);

int main(int argc, char *argv[]){
    int serv_sock;      // 클라이언트 요청을 수신할 서버 소켓 파일 디스크립터
    int clnt_sock;      // 개별 클라이언트와 통신할 클라이언트 소켓 파일 디스크립터
    int str_len;        // read()로 수신한 문자열의 길이를 저장할 변수

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    // 포트번호 인자가 제대로 전달되지 않았을 경우 사용법 출력 후 종료
    if (argc != 2){
        printf("사용법: %s <PORT>\n", argv[0]);
        exit(1);
    }
    
    // IPv4 + TCP 방식으로 소켓 생성
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1){
        error_handling("socket() error"); // 소켓 생성 실패 시 에러 처리
    }

    // 서버 주소 구조체 초기화 (모든 필드를 0으로 설정)
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;                 // IPv4 주소 체계 설정
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 모든 IP에서의 접속 허용 (0.0.0.0)
    serv_addr.sin_port = htons(atoi(argv[1]));      // 문자열로 받은 포트번호를 정수로 변환 후 네트워크 바이트 순서로 변환

    int option = 1;
    // 포트 재사용 옵션 설정 (서버 재시작 시 "Address already in use" 방지)
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    // 소켓과 주소를 연결 (bind)
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1){
        error_handling("bind() error"); // 바인딩 실패 시 에러 처리
    }

    // 클라이언트 연결 요청을 수신 대기 상태로 전환
    if(listen(serv_sock, 5)){
        error_handling("listen() error"); // 리슨 실패 시 에러 처리
    } // 5개의 클라이언트 대기

    // 최대 5명의 클라이언트를 처리하는 루프
    for(int i = 0; i < 5; ++i){
        clnt_addr_size = sizeof(clnt_addr); // 클라이언트 주소 크기 지정 (루프 안에서 크기 지정하여 초기화 하는 것이 안정적이고 예측 가능)

        // 클라이언트 접속 요청 수락 및 클라이언트 소켓 생성
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1){
            error_handling("accept() error");   // 연결 수락 실패 시 처리
        }else{
            printf("connected client %d : %s \n", i + 1, inet_ntoa(clnt_addr.sin_addr)); // 접속 성공 시 클라이언트 번호와 IP 주소 출력
        }
        // 연결된 상태의 코드....
        // 클라이언트와 메시지를 주고받는 루프 (Echo 처리)
        char message[BUF_SIZE];
        while((str_len = read(clnt_sock, message, sizeof(message) - 1))){ // 읽을 때는 버퍼사이즈 전체를 읽어야함 공백문자 남을 수도 있음 / 보낼 땐 사이즈를 줄여도 됨
            message[str_len] = '\0'; // 문자열 끝에 널 문자 추가 (출력 안정성 확보)
            printf("서버 받은 메세지: %s \n", message);
            write(clnt_sock, message, str_len); // 클라이언트에게 받은 메시지를 다시 전송
        }
        close(clnt_sock); // 통신 종료 후 클라이언트 소켓 닫기
    }

    close(serv_sock);   // 서버 종료 시 서버 소켓 닫기
    return 0;           // 프로그램 정상 종료
}

// 에러 메시지를 표준 에러로 출력하고 프로그램 종료
void error_handling(char *message){
    fputs(message, stderr); // 문자열 출력
    fputc('\n', stderr);    // 개행 출력
    exit(1);                // 비정상 종료
}
//./echo_server 8890