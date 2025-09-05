#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyStr.h"

const char BUFF_SIZE = 10;
const char STR_LEN = 10;

int main(void)
{
    char str[STR_LEN];
    char ch = 0;

    printf("Testing...\n");

    printf("Enter something to check MyFGetS & MyPutS & MyStrLen : ");
    MyFGetS(str, BUFF_SIZE, stdin);
    MyPutS(str);
    printf("\nLen = %d\n", MyStrLen(str));

    printf("Enter the character you want to find : ");
    ch = getchar();
    printf("%p %p", str, MyStrChr(str, ch));



    return 0;
}