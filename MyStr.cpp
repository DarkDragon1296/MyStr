#include <stdio.h>
#include <stdlib.h>
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

char * MyStrCat(char * dest, const char * src)
{
    int dest_len = MyStrLen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}

char * MyStrNCat(char * dest, const char * src, const int n)
{
    int dest_len = MyStrLen(dest);
    int i = 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}

int MyAtoi(const char * str)
{
    bool is_sign = (str[0] == '-'); // Получаем значение 
    int i = is_sign; // Начальный индекс строки. 0, если нет знака; 1, если знак есть
    int result = 0;

    for (; '0' <= str[i] && str[i] <= '9' ; i++)
    {
        result *= 10;
        result += str[i] - '0'; // Получаем значение числа
    }

    result *= is_sign ? -1 : 1;

    return result;
}

char * MyFGetS(char *str, int n, FILE * stream)
{
    char ch = fgetc(stream);
    int i = 0;

    if (ch == EOF)
        return NULL;

    while (ch != EOF && ch != '\0' && i < n)
    {
        str[i++] = ch;
        ch = fgetc(stream);
    }
    
    str[i] = '\0';

    return str;
}

char * MyStrDup(const char * str)
{
    int str_len = MyStrLen(str);
    int i = 0;
    char * str_dup = (char *) calloc(str_len + 1, sizeof(char));

    for (; str[i] != '\0'; i++)
        str_dup[i] = str[i];

    str_dup[i] = '\0';

    return str_dup;
}

int MyGetLine(char ** str_ptr, int * n, FILE * stream)
{
    int result = 0;

    *str_ptr = (char *)calloc(*n + 1, sizeof(char));

    char * NULL_check = MyFGetS(*str_ptr, *n, stream);

    if (NULL_check == NULL)
        return -1;

    result = MyStrLen(*str_ptr);

    return result;
}
