#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyStr.h"

const char BUFF_SIZE = 10;
const char STR_LEN = 10;

int main(void)
{
    char ** str_ptr;
    int *n;
    char str[STR_LEN] = {}, str1[STR_LEN] = {}, str2[STR_LEN] = {};
    char ch = 0;

    *n = 10;

    printf("Testing...\n");

    printf("Enter something to check MyFGetS & MyPutS & MyStrLen : ");
    MyFGetS(str, BUFF_SIZE, stdin);
    printf("(%d symbols)\n", MyPutS(str));
    printf("\nLen = %d\n", MyStrLen(str));
    printf("Enter the character you want to find : ");
    ch = getchar();
    printf("Str[0] = %p, symbol = %p\n", str, MyStrChr(str, ch));
    printf("Input str1 & str2 :\n");

    MyGetLine(str_ptr, n, stdin);
    printf("%d %s", *n, *str_ptr);

    return 0;
}