# 🛠️ Day5: CMake 자동 빌드 구조와 설정 완료기록

작성일: 2025-04-22  

---

## 📁 적용 위치
- 루트 디렉토리: `LearnC/`
- 관련 파일 :
  - [`LearnC/CMakeLists.txt`](../../../CMakeLists.txt)
  - [`LearnC/c_language/CMakeLists.txt`](../../CMakeLists.txt)
  - [`LearnC/c_language/basics/CMakeLists.txt`](../../basics/CMakeLists.txt)
  - [`LearnC/cpp_language/CMakeLists.txt`](../../../cpp_language/CMakeLists.txt)
  - [`LearnC/cpp_language/basics/CMakeLists.txt`](../../../cpp_language/basics/CMakeLists.txt)

## ✅ 주요 목표
- `c_language` 및 `cpp_language` 디렉토리를 재귀적으로 탐색하여 모든 `.c`, `.cpp` 소스 파일을 자동으로 인식 및 수집
- 각 소스파일에 대해 실행파일을 자동 생성

---

## 📂 프로젝트 구조

```
LearnC/
├── CMakeLists.txt              ← [1] 루트 CMake
│
├── c_language/
│   │
│   ├── CMakeLists.txt         ← [2] C언어 서브 모듈 용
│   │
│   └── basics/
│       │
│       └── CMakeLists.txt     ← [3] C파일 자동 빌드
│
└── cpp_language/
     │
     ├── CMakeLists.txt         ← [4] C++ 서브 모듈 용
     │
     └── basics/
          │
          └── CMakeLists.txt    ← [5] C++ 파일 자동 빌드

```

---

## ⚙️ CMake 설정 방식

### 1. LearnC/CMakeLists.txt

```cmake

cmake_minimum_required(VERSION 3.10)
project(LearnC_Project)

# C & C++ 공통 설정
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

# 하위 디렉토리 추가
add_subdirectory(c_language)
add_subdirectory(cpp_language)

```

---

### 2. c_language/CMakeLists.txt

```cmake

# C 언어 관련 서브디렉토리 추가
add_subdirectory(basics)

```

---

### 3. c_language/basics/CMakeLists.txt

```cmake

cmake_minimum_required(VERSION 3.10)
project(Basics_C)

file(GLOB BASICS_C_FILES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${BASICS_C_FILES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME}_c ${EXECUTABLE})
endforeach()

```

---

### 4. cpp_language/CMakeLists.txt

```cmake

# C 언어 관련 서브디렉토리 추가
add_subdirectory(basics)

```

---

### 5. cpp_language/basics/CMakeLists.txt

```cmake

cmake_minimum_required(VERSION 3.10)
project(Basics_CPP)

# 이 디렉토리 안에 있는 .cpp 파일 전부 찾아서 각각 실행파일 생성
file(GLOB BASICS_CPP_FILES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

foreach(EXECUTABLE ${BASICS_CPP_FILES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME}_cpp ${EXECUTABLE})
    set_target_properties(${EXE_NAME}_cpp PROPERTIES LINKER_LANGUAGE CXX)
endforeach()


```

---



## 🧱 CMake 파일을 폴더마다 나눠서 작성하는 이유와 인식 구조

### ✅ 왜 폴더마다 `CMakeLists.txt`를 만들어야 할까?

#### 1. 모듈화(Modularization)를 위함
- 각 폴더를 하나의 **논리적 단위(모듈)** 로 나눌 수 있다.
- 해당 폴더 내에서만 관리할 빌드 타겟, 소스 파일을 구분할 수 있어 유지보수에 유리하다.

#### 2. 확장성과 재사용성 확보
- 새로운 디렉토리를 추가할 때 해당 폴더에 `CMakeLists.txt`만 작성하면 간편하게 연결할 수 있다.
- 예: `stack`, `queue`, `linked_list` 등의 구조가 각자 독립적인 빌드 단위로 추가 가능

#### 3. CMake의 철학과 구조에 맞는 작성 방식
- CMake는 디렉토리 기반의 재귀적 빌드를 지원한다.
- 하위 디렉토리를 `add_subdirectory()`로 포함시켜 상위-하위 구조를 만들 수 있다.

---

## 🔗 각각의 CMake 파일은 어떻게 서로를 인식할까?

### 🔑 핵심은 `add_subdirectory()` 명령어

#### 예시 구조:

```text
LearnC/
├── CMakeLists.txt                    ← 루트 (최상위)
├── c_language/
│   ├── CMakeLists.txt               ← 중간 디렉토리
│   └── basics/
│       ├── CMakeLists.txt           ← 하위 타겟 설정
│       └── rand_test_2.c

```

- 각 CMake 파일은 "위에서 아래로" 연결되며, 하위 디렉토리는 상위 디렉토리가 호출해야 인식됨


## 실습 중 생긴 오해와 진실

- 1. CMake를 통해 빌드, 실행을 하는 과정에서 컴파일 명령어로 컴파일 - 실행 할 때와는 달리, 실행파일이 해당 폴더 안에 생성되지 않는다는 것을 발견

- 2. `.c` , `.cpp` 파일을 실행 파일 없이 빌드, 실행될리 없는데, 파일이 생겨나지 않아 당황

- 3. `build/` 아래 실행파일을 생성해서 실행하고 있었음

- 4. CMake를 쓰면 실행파일이 **소스 디렉토리가 아니라 `build/` 디렉토리에 생김**

- 5. [clean.sh](../../../clean.sh) 파일로 build 폴더 내부의 실행 파일 삭제가 역시 가능했음.

- 6. CMake는 실행 타겟을 정리된 방식으로 관리 할 수 있어 간편했음

---

## 📝 앞으로 확장할 수 있는 부분

- `tasks.json`으로 자동 빌드까지 통합 가능할까?
- `stack`, `queue`, `linked_list` 디렉토리도 같은 방식으로 확장해보기
- 선택 빌드 기능 (`--target`) 또는 CMake GUI 자동 타겟 설정이 가능할지?
