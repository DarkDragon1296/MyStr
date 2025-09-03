#include <stdio.h>
#include "MyStr.h"

int MyPutS(const char * str)
{
    int result = printf("%s", str);
    result = result < 0 ? EOF : '\n';

    return result;
}

int MyStrLen(const char * str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        continue;

    return i;
}

char * MyStrChr(char * str, const char ch)
{

    while (true)
    {

        str++;

        if (*str == '\0')
            return NULL;
        else if(*str == ch)
            return str;
    }
}

