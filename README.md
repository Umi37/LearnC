# 📘 C & C++ 공부 기록 – LearnC

이 레포지토리는 C와 C++ 프로그래밍 언어를 **기초부터 체계적으로 학습하고 실습한 내용**을 정리한 공간입니다.  
C언어는 절차지향 기반의 자료구조 학습을, C++은 객체지향과 고급 기능(STL, 템플릿 등)까지 확장합니다.

---


## 📅 학습 시작일

- 2025년 4월 17일

## 📅 학습 log

- [Day1] 2025년 4월 17일 : 학습 시작일
    - 학습을 위한 디렉토리 초기 세팅
    - C++ basic : 변수, 입출력
    - C와 C++ 의 입출력 방식 차이에 대한 이해 : 메모리 관리, 메모리 접근 방식, 문법적 측면
    - 스택과 힙의 내부 작동 방식 및 특성

- [Day2] 2025년 4월 18일
    - C++ basic : 제어문 (if, for, while)
    - rand() 함수 및 선형 합동 생성기 (LCG) - 의사 난수 생성 알고리즘에 대한 이해

---

## 📌 C 언어 학습 목차

| 주제 | 설명 | 예제 |
|------|------|------|
| 1️⃣ 기본문법 (basics) | 변수, 입출력, 제어문, 흐름제어, C표준 라이브러리 | [`c_language/basics`](./c_language/basics) |
| 2️⃣ 스택 (Stack) | 배열 기반 스택 구현 | [`c_language/stack/stack.c`](./c_language/stack/stack.c) |
| 3️⃣ 큐 (Queue) | 배열 기반 큐 구현 | [`c_language/queue/queue.c`](./c_language/queue/queue.c) |
| 4️⃣ 연결 리스트 | 단일 연결 리스트 구현 | [`c_language/linked_list/singly_list.c`](./c_language/linked_list/singly_list.c) |

---

## 📌 C++ 학습 목차

| 주제 | 설명 | 예제 |
|------|------|------|
| 1️⃣ 기본 문법 (basic) | 변수, 입출력, 제어문 | [`cpp_language/basics/hello.cpp_language`](./cpp_language/basics/hello.cpp_language) |
| 2️⃣ 함수와 참조 (fuction) | 함수 정의, call by reference | [`cpp_language/function/ref_example.cpp_language`](./cpp_language/function/ref_example.cpp_language) |
| 3️⃣ 기본 문법 (basics) | 변수, 입출력, 제어문 | [`cpp_language/basics`](./cpp_language/basics) |
| 4️⃣ 함수와 참조 (fuction) | 함수 정의, call by reference | [`cpp_language/function`](./cpp_language/function) |
| 5️⃣ 클래스와 객체 (opp) | 클래스 정의, 생성자/소멸자 | [`cpp_language/oop/class_intro.cpp_language`](./cpp_language/oop/class_intro.cpp_language) |
| 6️⃣ 상속 (opp) | `public` 상속, `virtual` 함수 | [`cpp_language/oop/inheritance.cpp_language`](./cpp_language/oop/inheritance.cpp_language) |
| 7️⃣ 다형성 (opp) | 오버라이딩, 추상 클래스 | [`cpp_language/oop/polymorphism.cpp_language`](./cpp_language/oop/polymorphism.cpp_language) |
| 8️⃣ 템플릿 (template) | 함수 템플릿, 클래스 템플릿 | [`cpp_language/template/max_func.cpp_language`](./cpp_language/template/max_func.cpp_language) |
| 9️⃣ 예외 처리 (exception) | `try`, `catch`, `throw` | [`cpp_language/exception/trycatch.cpp_language`](./cpp_language/exception/trycatch.cpp_language) |
| 🔟 STL | `vector`, `map`, `set`, `algorithm` | [`cpp_language/stl/vector_sort.cpp_language`](./cpp_language/stl/vector_sort.cpp_language) |

---

## 📘 이론 정리 노트

이론은 각 언어별로 `docs/` 폴더에 마크다운으로 작성합니다.

### 📄 C 언어 노트
- `C/docs/stack.md`
- `C/docs/queue.md`
- `C/docs/linked_list.md`

### 📄 C++ 노트
- `cpp_language/docs/01_기본문법.md`
- `cpp_language/docs/02_객체지향.md`
- `cpp_language/docs/03_STL_활용.md`

---

## 🔖 Git 커밋 컨벤션

| Prefix   | 설명                            |
|----------|---------------------------------|
| Add:     | 새로운 기능, 파일 추가          |
| Fix:     | 버그 수정                       |
| Update:  | 기존 코드나 문서의 변경 (보완) |
| Remove:  | 삭제된 파일이나 코드            |
| Refactor:| 기능 변화 없이 구조 개선        |
| Chore:   | 빌드 설정, 폴더 정리, 기타 잡일 |
| Docs:    | 문서 (README 등) 관련 변경      |

---

## 💬 커밋 메시지 규칙

- `[Day1] Add: C++ 디렉토리 구조 세팅 및 README 작성`
- `[Day2] Fix: Stack 구현 오류 수정`
- `[Day3] Update: queue.c에 주석 추가`
- 날짜별로 `DayN`을 붙여서 학습 흐름을 기록합니다.

---

## 📁 폴더 구조

```bash
LearnC/
├── c_language/                   # 절차지향 언어 C 학습 (자료구조 중심)
│   ├── basics/          # 변수, 제어문, 입출력 등 기초 문법
│   ├── stack/           # 스택 구현 및 응용
│   ├── queue/           # 큐 구현 및 응용
│   ├── linked_list/     # 연결리스트 구현
│   ├── docs/            # 이론 정리 마크다운
│   │    └── stdlib/    # 표준 라이브러리
│   └── README.md
│
├── cpp_language_language/                 # 객체지향 언어 C++ 학습
│   ├── basics/          # 변수, 제어문, 입출력 등 기초 문법
│   ├── function/        # 함수, 참조자 등 함수 관련 문법
│   ├── oop/             # 클래스, 상속, 다형성 등 객체지향
│   ├── template/        # 템플릿 함수/클래스
│   ├── stl/             # 벡터, 맵, 알고리즘 등 STL
│   ├── exception/       # 예외 처리 관련
│   ├── docs/            # 이론 정리 마크다운
│   └── README.md
│
└── README.md            # 루트 안내 파일 (바로 이 파일)
