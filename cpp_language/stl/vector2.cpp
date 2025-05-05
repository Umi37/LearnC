#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    // reserve: 메모리 여유 공간 미리 확보 (초기 capacity 확인)
    v.reserve(10);
    std::cout << "초기 capacity: " << v.capacity() << std::endl;

    // push_back: 요소 추가
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // size: 현재 원소 수 확인
    std::cout << "현재 size: " << v.size() << std::endl;

    // front, back: 첫 번째, 마지막 요소 확인
    std::cout << "첫 번째 원소 (front): " << v.front() << std::endl;
    std::cout << "마지막 원소 (back): " << v.back() << std::endl;

    // at: 범위 체크하면서 요소 접근
    std::cout << "2번 인덱스 원소 (at): " << v.at(2) << std::endl;

    // insert: 두 번째 위치(인덱스 1)에 15 삽입
    v.insert(v.begin() + 1, 15);

    // erase: 3번 인덱스(원래 30 있었던 자리) 삭제
    v.erase(v.begin() + 3);

    // 전체 출력
    std::cout << "벡터 요소들: ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    // pop_back: 맨 뒤 요소 제거
    v.pop_back();

    // size, capacity 다시 확인
    std::cout << "pop_back 후 size: " << v.size() << std::endl;
    std::cout << "pop_back 후 capacity: " << v.capacity() << std::endl;

    // empty: 벡터가 비었는지 확인
    std::cout << "벡터가 비었나요? " << (v.empty() ? "네" : "아니오") << std::endl;

    // resize: 크기를 5로 늘림 (새로 추가된 요소는 0으로 초기화됨)
    v.resize(5);

    std::cout << "resize 후 벡터 요소들: ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    // clear: 모든 요소 삭제
    v.clear();
    std::cout << "clear 후 size: " << v.size() << std::endl;
    std::cout << "clear 후 capacity: " << v.capacity() << " (capacity는 그대로)" << std::endl;

    return 0;
}
