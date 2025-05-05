
// 반복문 실습 : 1부터 10까지의 합을 구하는 프로그램

#include <iostream>

int main()
{
	int num = 0;
	
	for (int i = 0; i < 10; i ++)
	{
		num += i + 1 ;
	}
    
	
	std::cout << "1부터 10까지의 합은 " << num << "입니다." << std::endl;
    
}
