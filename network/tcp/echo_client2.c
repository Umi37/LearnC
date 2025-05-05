#include <stdio.h>      // 소켓 관련 함수 사용
#include <stdlib.h>     // exit() 함수 사용
#include <string.h>     // memset() 함수 사용
#include <unistd.h>     // close() 함수 사용
#include <arpa/inet.h>  // inet_addr() 함수 사용
#include <sys/socket.h> // socket() 함수 사용

#define BUF_SIZE 1024   // 버퍼 크기 정의
void error_handling(char *message); // 오류 처리 함수 선언

int main(int argc, char *argv[]) // 명령줄 인자 argc, argv 사용
// argc: 명령줄 인자의 개수, argv: 명령줄 인자 배열

{
	int sock;                           // 소켓을 위한 변수 선언
	char message[BUF_SIZE];             // 메시지를 저장할 버퍼
	int str_len, recv_len, recv_cnt;    // 전송 및 수신한 바이트 수를 저장할 변수
	struct sockaddr_in serv_adr;        // 서버 주소 정보를 담을 구조체 변수

    // 명령줄 인자의 개수가 올바르지 않으면 사용법 안내 후 종료
	if(argc!=3) { // 인자 개수가 3개가 아닐 경우
        // argv[0]: 프로그램 이름, argv[1]: IP 주소, argv[2]: 포트 번호
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1); // 오류 코드 1을 반환하며 비정상 종료
	}
	
	sock=socket(PF_INET, SOCK_STREAM, 0);   // IPv4, TCP 소켓 생성
	if(sock==-1)                            // 소켓 생성 실패 시
		error_handling("socket() error");   
	
	memset(&serv_adr, 0, sizeof(serv_adr));         // 주소 구조체 초기화
	serv_adr.sin_family=AF_INET;                    // 주소 체계 설정 (IPv4 사용)
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);    // 문자열 IP 주소를 32비트 정수형으로 변환
	serv_adr.sin_port=htons(atoi(argv[2]));         // 문자열 포트 번호를 정수로 바꾼 뒤, 네트워크 바이트 순서로 변환
	
    // 서버에 연결 요청 (3-way handshake 수행됨)
	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");
	
    // while 루프를 통해 사용자로부터 메시지를 입력받고 서버에 전송    
	while(1) 
	{
		fputs("Input message(Q to quit): ", stdout); // 사용자에게 메시지 입력 요청
		fgets(message, BUF_SIZE, stdin);             // 표준 입력으로부터 메시지 읽기 (\n 포함)
		
        // 사용자가 "q" 또는 "Q"를 입력하면 종료
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
			break;

		str_len=write(sock, message, strlen(message));  // 서버에 메시지 전송하며, 전송한 바이트 수를 str_len에 저장
		
		recv_len=0; // 수신한 바이트 수를 누적 카운팅하여 저장할 변수
		while(recv_len<str_len)
		{
			recv_cnt=read(sock, &message[recv_len], BUF_SIZE-1);    // 서버로부터 메시지 수신하며, 수신한 바이트 수를 recv_cnt에 저장
			if(recv_cnt==-1)
				error_handling("read() error!");
			recv_len+=recv_cnt;                                     // 수신한 바이트 수를 recv_len에 누적
		}
		
		message[recv_len]=0; // 수신한 메시지의 끝에 NULL 문자 추가
		printf("Message from server: %s", message);
	}
	
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
