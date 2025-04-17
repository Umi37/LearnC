#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout << "이름을 입력하세요: ";
    std::cin >> name;
    std::cout << "나이를 입력하세요: ";
    std::cin >> age;

    std::cout << "안녕하세요, " << name << "님! 당신의 나이는 " << age << "살 이군요" << std::endl;

}