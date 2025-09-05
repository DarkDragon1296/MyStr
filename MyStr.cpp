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

