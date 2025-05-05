# 🔁 IPC (Inter-Process Communication)

이 디렉토리는 C 언어에서 다양한 **프로세스 간 통신 (IPC)** 방식을 실습하며, 각 방식의 동작 원리와 사용법을 체득하기 위한 공간입니다.  
파이프, 메시지 큐, 공유 메모리, 세마포어, 시그널 처리까지 폭넓게 다루고 있습니다.

---

## 📌 주요 학습 항목 및 예제

### 1. 🧵 Pipe (파이프)

| 파일명 | 설명 |
|--------|------|
| `pipe.c` | 기본 파이프 사용 예제 |
| `pipe_client.c`, `pipe_server.c` | 파이프를 이용한 서버-클라이언트 통신 구현 |
| `pipe_server_epoll.c` | epoll 기반 다중 입출력 처리 서버 |
| `pipe_server_select.c`, `pipe_server_select2.c` | select 기반 IO 멀티플렉싱 서버 구현 |

---

### 2. 📨 Message Queue (메시지 큐)

| 파일명 | 설명 |
|--------|------|
| `mq_client.c`, `mq_server.c` | System V 메시지 큐를 이용한 클라이언트-서버 메시지 통신 |

---

### 3. 🧠 Shared Memory (공유 메모리)

| 파일명 | 설명 |
|--------|------|
| `shm_client.c`, `shm_server.c` | 공유 메모리를 이용한 기본 통신 |
| `shm_test.c`, `shm_test2.c` | 테스트용 공유 메모리 예제 |
| `shm_semaphore.c`, `shm_semaphore2.c` | 공유 메모리 + 세마포어 동기화 실습 |

---

### 4. 🚦 Signal (시그널 처리)

| 파일명 | 설명 |
|--------|------|
| `signal.c` | 기본적인 시그널 처리 (`SIGINT`, `SIGTERM` 등) |
| `sigaction.c` | `sigaction()` 함수를 사용한 고급 시그널 처리 |

---

### 5. 🔄 기타

| 파일명 | 설명 |
|--------|------|
| `echo_mpserver.c`, `echo_mpclient.c` | 멀티프로세스를 이용한 에코 서버-클라이언트 구현 |

---

## ⚙️ 실행 예시

```bash
# 메시지 큐 서버 실행
gcc mq_server.c -o mq_server
./mq_server

# 메시지 큐 클라이언트 실행 (다른 터미널에서)
gcc mq_client.c -o mq_client
./mq_client
