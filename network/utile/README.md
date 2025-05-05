# 🛠️ Network Utilities

이 디렉토리는 네트워크 프로그래밍에서 자주 사용되는 **유틸리티 함수**와 도구들을 실습하며 정리한 공간입니다.  
바이트 순서 변환, IP 주소 변환, 도메인 이름 검색, IO 멀티플렉싱 등 핵심 함수 사용법을 체득할 수 있습니다.

---

## 📌 주요 유틸리티 실습 항목

### 1. 🔄 바이트 순서 변환 (Endian Conversion)

| 파일명 | 설명 |
|--------|------|
| `endian_conv.c` | 호스트 바이트 순서 ↔ 네트워크 바이트 순서 변환 (`htons`, `htonl`, `ntohs`, `ntohl`) |

---

### 2. 🌐 호스트 이름/주소 조회

| 파일명 | 설명 |
|--------|------|
| `getHostByName.c` | 도메인 이름으로 IP 주소 조회 (`gethostbyname`) |
| `getHostByAddr.c` | IP 주소로 도메인 이름 조회 (`gethostbyaddr`) |

---

### 3. 🧮 IP 주소 변환 함수

| 파일명 | 설명 |
|--------|------|
| `inet_addr.c` | 문자열 IP 주소를 숫자로 변환 (`inet_addr`) |
| `inet_ntoa.c` | 숫자 IP 주소를 문자열로 변환 (`inet_ntoa`) |

---

### 4. 🧵 IO 멀티플렉싱

| 파일명 | 설명 |
|--------|------|
| `select.c` | `select()` 시스템 호출을 이용한 파일 디스크립터 감시 예제 |

---

## ⚙️ 실행 예시

```bash
# 바이트 순서 변환
gcc endian_conv.c -o endian
./endian

# 도메인 이름 → IP
gcc getHostByName.c -o getname
./getname

# IP → 도메인 이름
gcc getHostByAddr.c -o getaddr
./getaddr
