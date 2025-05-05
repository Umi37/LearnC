# 👥 Multi-Process Programming

이 디렉토리는 C 언어를 기반으로 **멀티 프로세스를 활용한 네트워크 프로그래밍** 실습 내용을 정리한 공간입니다.  
`fork()`와 `wait()`, `zombie process` 처리부터, `select()`를 활용한 동시성 처리까지 다양한 개념을 실제로 구현해보았습니다.

---

## 📌 주요 학습 항목 및 예제

### 1. 🗣 Echo Server with select()

| 파일명 | 설명 |
|--------|------|
| `echo_selectsrv.c` | `select()` 기반 멀티 클라이언트 에코 서버 |
| `echo_selectcli.c` | 클라이언트: 서버에 메시지를 보내고 응답을 받는 구조 |

---

### 2. 📰 News Sender/Receiver 통신 예제

| 파일명 | 설명 |
|--------|------|
| `news_sender.c`, `news_reciever.c` | 뉴스 송신/수신 단일 메시지 버전 |
| `news_sender_brd.c`, `news_reciever_brd.c` | 브로드캐스트 버전 (다수의 리시버에게 전송) |

---

### 3. 🧟 Zombie Process 관리

| 파일명 | 설명 |
|--------|------|
| `zombie.c` | 부모가 자식 프로세스를 `wait()` 없이 방치하여 좀비 프로세스 발생 |
| `remove_zombie.c` | 시그널 핸들링으로 `SIGCHLD` 수신 시 `wait()` 실행해 좀비 제거 |
| `wait.c`, `waitpid.c` | `wait()`와 `waitpid()` 차이 및 활용법 실습 |

---

## ⚙️ 실행 예시

```bash
# 에코 서버 실행
gcc echo_selectsrv.c -o server
./server

# 클라이언트 실행 (다른 터미널)
gcc echo_selectcli.c -o client
./client 127.0.0.1 8888
