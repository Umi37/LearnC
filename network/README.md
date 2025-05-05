# 🌐 C Network Programming

이 디렉토리는 C 언어 기반의 네트워크 프로그래밍을 학습하며 실습한 결과물을 정리한 공간입니다.  
TCP/UDP 소켓, IPC, 멀티 프로세스, 네트워크 유틸리티 등 다양한 주제를 실제 코드로 구현해보며 네트워크 구조를 체득하는 것이 목표입니다.

---

## 📁 디렉토리 구조 및 학습 주제

### 📂 ipc/ — 프로세스 간 통신(IPC, Inter-Process Communication)

- **파이프 (Pipe)**: `pipe.c`, `pipe_server.c`, `pipe_client.c` 등
- **메시지 큐 (Message Queue)**: `mq_client.c`, `mq_server.c`
- **공유 메모리 (Shared Memory)**: `shm_client.c`, `shm_server.c`, `shm_test.c` 등
- **세마포어 (Semaphore)**: `shm_semaphore.c`, `shm_semaphore2.c`
- **시그널 처리**: `signal.c`, `sigaction.c`
- **응용 예제**: 멀티 프로세스를 결합한 에코 서버 `echo_mpserver.c`

> 다양한 IPC 방식을 직접 구현하고, 프로세스 간 데이터를 어떻게 안전하고 효율적으로 주고받는지 학습합니다.

---

### 📂 multiProcess/ — 멀티 프로세스 네트워크 프로그래밍

- **에코 서버 클라이언트**: `echo_selectsrv.c`, `echo_selectcli.c`
- **뉴스 송수신 예제**: `news_sender.c`, `news_receiver.c` 등
- **좀비 프로세스 처리**: `zombie.c`, `remove_zombie.c`, `wait.c`, `waitpid.c`

> `fork()`를 이용한 자식 프로세스 생성, 프로세스 간 통신, select 기반 IO multiplexing, 좀비 프로세스 처리 등을 중심으로 실습합니다.

---

### 📂 tcp/ — TCP 기반 소켓 프로그래밍

- **기초 예제**: `hello_client.c`, `hello_server.c`, `echo_client.c`, `echo_server.c`
- **파일 전송**: `file_client.c`, `file_server.c`
- **간단한 명령 처리 서버**: `op_client.c`, `op_server.c`
- **기타 실습**: `info.c` 등

> 신뢰성 있는 데이터 전송을 위한 TCP의 특성과 소켓의 생명 주기를 실제 코드로 구현하며 익힙니다.

---

### 📂 udp/ — UDP 기반 소켓 프로그래밍

- **UDP 에코 서버 클라이언트**: `Uecho_client.c`, `Uecho_server.c`
- **포트 바인딩 실습**: `bound_host0.c`, `bound_host1.c`

> 비연결형 통신 UDP의 특성과 `sendto`, `recvfrom` 함수 사용법을 실습합니다.

---

### 📂 utile/ — 유틸리티 함수 및 실습 코드

- **바이트 순서 변환**: `endian_conv.c`
- **호스트 이름/주소 조회**: `getHostByName.c`, `getHostByAddr.c`
- **IP 주소 변환**: `inet_addr.c`
- **IO 멀티플렉싱 기초**: `select.c`

> 네트워크 프로그래밍의 기초 도구와 함수들을 따로 정리한 유틸 폴더입니다. 반복 사용되는 기능들을 모듈화합니다.

---

## ⚙️ 컴파일 & 실행

모든 예제는 GCC로 컴파일 가능하며, 각 디렉토리마다 `CMakeLists.txt` 파일을 통해 빌드 자동화 설정도 함께 구성되어 있습니다.

```bash
gcc echo_client.c -o client
gcc echo_server.c -o server
./server
./client 127.0.0.1 8888
