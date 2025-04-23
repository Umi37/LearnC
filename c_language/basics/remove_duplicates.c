// 사용자에게 문자열을 입력받아, 중복된 문자를 제거한 결과를 출력하는 프로그램
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char new_str[100];

    printf("문자를 입력하세요: ");

    // 문자열 입력
    scanf("%s", str);

    // 입력된 문자열 길이 계산
    int length = strlen(str);

    printf("\n중복 문자 제거중 🧹\n");

    int new_length = 0;
    new_str[new_length++] = str[0]; // 첫 번째 문자는 항상 추가

    // 중복된 문자 제거
    for (int i = 1; i < length ; i++)
    {          
        int is_duplicate = 0; // 중복 여부 플래그 초기화

        for (int j = 0; j < new_length ; j++)
        {
            if (str[i] == new_str[j])
            {
                is_duplicate = 1; // 중복된 문자 발견
                break; 
            }
        }

        if (!is_duplicate)
        {
            new_str[new_length++] = str[i]; // 중복되지 않은 문자 추가 
        }
    }

    // 중복된 문자가 제거된 문자열의 길이를 계산
    new_length = strlen(new_str);
    new_str[new_length] = '\0'; // 문자열 끝에 널 문자 추가

    // 중복된 문자가 제거된 문자열 출력
    printf("중복되지 않은 문자는 %s 입니다.", new_str);

    return 0;
}
