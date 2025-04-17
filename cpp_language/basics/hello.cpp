#include <iostream> // C++ 표준 입출력 스트림
#include <stdio.h>  // C 표준 입출력 함수

int main()
{
    int num = 42;
    double pi = 3.14;
    char ch = 'A';
    std::string name = "Umi";

    std::cout << "Hello, C++!" << std::endl; // C++ 방식 출력
    std::cout << "정수: " << num << std::endl;
    std::cout << "실수: " << pi << std::endl;
    std::cout << "문자: " << ch << std::endl;
    std::cout << "문자열: " << name << std::endl << std::endl;

    printf("Let's learn C & C++!\n"); // C 방식 출력
    printf("정수: %d\n", num);
    printf("실수: %f\n", pi);
    printf("문자: %c\n", ch);
    printf("문자열: %s\n", name.c_str());  // ✅ 수정!
}

// .c_str()은 내부 문자열 데이터를 복사하거나 변환하지 않음
// 단지 힙에 존재하는 문자열 데이터의 주소를 const char* 형식으로 포장해서 반환
// 이 주소는 C 스타일 문자열을 요구하는 C 함수(예: printf)에 전달할 수 있음
