// 영어 알파벳으로 이루어진 문자열 str이 주어집니다. 각 알파벳을 대문자는 소문자로 소문자는 대문자로 변환해서 출력하는 코드를 작성해 보세요.

/*
제한사항
1 ≤ str의 길이 ≤ 20
str은 알파벳으로 이루어진 문자열입니다.
*/

#include <stdio.h>
#include <string.h>
#define LEN_INPUT 21

int main(void) {
    char s1[LEN_INPUT]; // 입력받은 문자열
    char s2[LEN_INPUT]; // 대소문자 변환해서 새로 담을 문자열
    int length = 0;     // 어차피 바로 덮어 쓸 값이라 0으로 굳이 초기화 하지 않아도 되지만 실수로 strlen() 대입을 빼먹었을 경우 쓰레기 값이 들어갈 수 있어 0으로 초기화 하는것이 안전한 습관

    printf("문자를 입력하세요 : ");

    scanf("%20s", s1);

    // 문자열에서 문자를 하나씩 꺼내 숫자로 변환하여 range 검사
    // 먼저 입력받은 문자열의 길이 측정

    length = strlen(s1);

    for (int i=0; i < length ; i ++)
    {
        if(65 <= s1[i] && s1[i] <= 90)
        {
            s2[i] = s1[i] + 32;
        }
        else if(97 <= s1[i] && s1[i] <= 122)
        {
            s2[i] = s1[i] - 32;
        }
    }

    s2[length] = '\0';

    printf("입력된 문자열: %s \n", s1);
    printf("변환된 문자열: %s \n", s2);


    return 0;
}
