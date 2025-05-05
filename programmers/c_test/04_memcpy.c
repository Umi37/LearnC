//문자열 덮어 쓰기

/*
my_string, overwrite_string과 정수 s가 주어짐.
문자열 my_string의 인덱스 s부터 overwrite_string의 길이만큼을
문자열 overwrite_string으로 바꾼 문자열을 return 하는 solution 함수를 작성하기.
*/

// 나의 코드
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) // ✅ 매개변수(parameter)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요.
    // 할당 길이는 상황에 맞게 변경해주세요.
    
    int my_len = strlen(my_string);
    int overwrite_len = strlen(overwrite_string);
    
    char* answer = (char*)malloc(my_len + 1);
    
    
    for (int i = 0; i < my_len; i++)
    {
        if (i >= s && i < s + overwrite_len)
        {
            answer[i] = overwrite_string[i - s];  // 덮어쓰기
        }
        else
        {
            answer[i] = my_string[i];  // 원래 문자 복사
        }
    }
    
    answer[my_len] = '\0';
    
    return answer;
}

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    int len = strlen(my_string);
    char* answer = (char*)malloc(len + 1);

    strcpy(answer, my_string);

    len = strlen(overwrite_string);
    memcpy(&answer[s], overwrite_string, len);

    return answer;
}

int main(void)
{
    char my_string[1001];   // 1️⃣ 스택에 1001칸 짜리 문자 배열 생성 (값 수정 가능) 
    char overwrite_string[1001];
    int s;

    // 문자열과 정수 입력 받기
    printf("my_string 입력: ");
    scanf("%s", my_string);

    printf("overwrite_string 입력: ");
    scanf("%s", overwrite_string);

    printf("시작 인덱스 s 입력: ");
    scanf("%d", &s);

    // solution 호출
    char* result = solution(my_string, overwrite_string, s);            // ✅ 인자(argument) 넘김 (스택에 원본이 살아있고, 그 주소를 const char*로 받아서 읽는 것. 즉 주소를 넘김)

    printf("결과 문자열: %s\n", result);

    free(result);  // 동적 메모리 해제 꼭!

    return 0;
}