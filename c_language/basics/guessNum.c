
// 10이하의 난수 생성하여 사용자에게 값 입력 받아 대조하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess;

    // 1. 시드 설정
    srand(time(NULL));

    // 2. 1~10 사이의 난수 생성
    secret = rand() % 10 + 1;

    printf("1부터 10 사이의 숫자를 맞춰보세요!\n");

    while (1) {
        printf("입력: ");
        scanf("%d", &guess);

        if (guess == secret) {
            printf("정답입니다!\n");
            break;
        } else {
            printf("틀렸어요. 다시 시도해보세요.\n");
        }
    }

    return 0;
}

