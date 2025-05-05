#include <iostream> // C++ 에서 표준입출력 함수를 사용하기 위한 라이브러리. std::cout 등을 사용할 수 있게 해줌
#include <vector>   // 내부적으로 동적할당(new/delete)을 써서 힙 메모리를 관리할 수 있는 자료구조(클래스)

int main() {
    std::vector<int> v; // 빈 벡터 생성

    v.push_back(10);    // 10 추가
    v.push_back(20);    // 20 추가
    v.push_back(30);    // 30 추가

    // 인덱스 접근
    std::cout << v[0] << std::endl; // 10 출력
    std::cout << v.at(1) << std::endl; // 20 출력 (범위 체크 포함)

    // 전체 출력
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
