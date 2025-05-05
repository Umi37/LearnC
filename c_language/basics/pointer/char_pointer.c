#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* makeStr_stack() {
    char str[] = "hello";
    return str;  // ❌ 위험! 함수 끝나면 str은 소멸됨
}
// warning: address of stack memory associated with local variable 'str' returned [-Wreturn-stack-address]

char* makeStr_heap() {
    char* str2 = (char*)malloc(100);
    strcpy(str2, "hello");
    return str2;  // ✅ 안전! 함수가 끝나도 힙 메모리는 남아 있음
}

int main(void)
{
    char *str = makeStr_stack();    // 위험한 포인터
    char *str2 = makeStr_heap();    // 안전한 포인터

    printf("스택 메모리에 저장되어 있는 문자열 : %s\n", str);
    printf("힙 메모리에 저장되어 있는 문자열 : %s\n", str2);

    free(str2); // 할당한 메모리는 꼭 해제해줘야 함
    return 0;
}


/*
MacBookPro pointer % 
스택 메모리에 저장되어 있는 문자열 : �H�
힙 메모리에 저장되어 있는 문자열 : hello
MacBookPro pointer % 
스택 메모리에 저장되어 있는 문자열 : �
힙 메모리에 저장되어 있는 문자열 : hello
MacBookPro pointer % 
스택 메모리에 저장되어 있는 문자열 : �H%
힙 메모리에 저장되어 있는 문자열 : hello
MacBookPro pointer % 
스택 메모리에 저장되어 있는 문자열 : ��>
힙 메모리에 저장되어 있는 문자열 : hello
MacBookPro pointer % 
*/