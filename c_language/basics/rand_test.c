// 파일명: rand_test.c  또는 rand_test.cpp 로 저장 가능

#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(1);  // 고정된 시드
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }
    return 0;
}

// 1804289383
// 846930886
// 1681692777
// 1714636915
// 1957747793