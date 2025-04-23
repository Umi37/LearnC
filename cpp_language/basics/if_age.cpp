
// 나이에 따른 등급 출력해보기

#include <iostream>

int main()
{
    int age;
    std::cout << "나이를 입력하세요.:";
    std::cin >> age;

    if (age < 0)
    {
        std::cout << "잘못된 나이입니다." << std::endl;
    }
    else if (age < 20)
    {
        std::cout << "청소년 입니다." << std::endl;
    }
    else if (age < 65)
    {
        std::cout << "성인 입니다." << std::endl;

    }
    else
    {
        std::cout << "노인 입니다." << std::endl;
    }

}
