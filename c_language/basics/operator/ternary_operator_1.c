// printf 내에서 삼항연산자의 사용

#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    printf("%d is %s", a, a%2==0?"even":"odd");
    return 0;
}

// #include <stdio.h>

// int main(void) {
//     int a;
//     scanf("%d", &a);
//     if(a%2 == 0)
//     {
//         printf("%d is even", a);
//     }
//     else
//     {
//         printf("%d is odd", a);
//     }

//     return 0;
// }