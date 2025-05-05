// #include <stdio.h>

// int main(void) {
    
//     printf("!@#$%^&*(\\'\"<>?:;");
//     return 0;
// }

#include <stdio.h>

int main(void) {
    printf("트라이그래프 테스트 시작!\n");

    // 트라이그래프 ??) → ]
    printf("이 문자열은 트라이그래프가 없으면 그대로 보입니다: ??)\n");

    // 트라이그래프 ??< → {
    // 트라이그래프 ??> → }
    printf("트라이그래프 중괄호 시도: ??< 내용 ??>\n");

    return 0;
}

// MacBookPro c_test % gcc -trigraphs print_special_character.c -o print_special_character

// print_special_character.c:15:86: warning: trigraph converted to ']' character [-Wtrigraphs]
//    15 |     printf("이 문자열은 트라이그래프가 없으면 그대로 보입니다: ??)\n");
//       |                                                                ^
// print_special_character.c:19:50: warning: trigraph converted to '{' character [-Wtrigraphs]
//    19 |     printf("트라이그래프 중괄호 시도: ??< 내용 ??>\n");
//       |                                       ^
// print_special_character.c:19:61: warning: trigraph converted to '}' character [-Wtrigraphs]
//    19 |     printf("트라이그래프 중괄호 시도: ??< 내용 ??>\n");
//       |                                                ^
// 3 warnings generated.
// MacBookPro c_test % ./print_special_character 
// 트라이그래프 테스트 시작!
// 이 문자열은 트라이그래프가 없으면 그대로 보입니다: ]
// 트라이그래프 중괄호 시도: { 내용 }
// MacBookPro c_test % 