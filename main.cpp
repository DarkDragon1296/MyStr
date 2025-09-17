#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyStr.h"

const char BUFF_SIZE = 10;
const char STR_LEN = 10;

int main(void)
{
    char ** str_ptr = NULL;
    size_t *n = NULL;
    char str[STR_LEN] = {}, str1[STR_LEN] = {}, str2[STR_LEN] = {};
    size_t temp_size_t = 10;
    char *temp_str = NULL;
    char ch = 0;
    size_t result_getline = 0;

    n = &temp_size_t;
    str_ptr = &temp_str;

    printf("Testing...\n");

    printf("Enter something to check MyFGetS & MyPutS & MyStrLen : ");
    MyFGetS(str, BUFF_SIZE, stdin);
    printf("(%d symbols)\n", MyPutS(str));
    printf("\nLen = %d\n", MyStrLen(str));
    printf("Enter the character you want to find : ");

    ch = getchar();
    printf("Str[0] = %p, symbol = %p\n", str, MyStrChr(str, ch));

    ch = getchar(); // Чистим от \n

    printf("Input str to test MyGetLine:\n");

    result_getline = MyGetLine(str_ptr, n, stdin);
    printf("%d %s", *n, *str_ptr);

    if (result_getline != 0)
        free(*str_ptr);

    return 0;
}