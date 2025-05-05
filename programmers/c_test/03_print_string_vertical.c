#include <stdio.h>
#include <string.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    scanf("%10s", s1);
    int length = strlen(s1);
    
    for (int i=0; i < length ; i++)
    {
        printf("%c\n",s1[i]);
    }

    return 0;
}
