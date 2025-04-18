#include <stdio.h>
#include <stdlib.h>

void generate() {
    rand();  // 1st call
}

int main() {
    srand(1);
    generate();  // rand() 한번 호출됨
    printf("%d\n", rand());  // 2nd call
    printf("%d\n", rand());  // 3rd call
}

// 846930886
// 1681692777