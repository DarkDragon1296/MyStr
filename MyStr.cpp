#include <stdio.h>
#include <stdlib.h>
#include "MyStr.h"

int MyPutS(const char *str)
{
    int i = 0, result = 0;
    while (str[i] != '\0' && str[i] != EOF)
    {
        int result = putchar(str[i]);
        i++;
    }

    result = result == EOF ? EOF : i;

    return result;
}

int MyStrLen(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        continue;

    return i;
}

char * MyStrChr(char *str, const int ch)
{
    while (true)
    {
        if (*str == '\0')
            return NULL;
        else if(*str == ch)
            return str;

        str++;
    }
}

char * MyStrCat(char *dest, const char *src)
{
    int dest_len = MyStrLen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}

char * MyStrNCat(char *dest, const char *src, const int n)
{
    int dest_len = MyStrLen(dest);
    int i = 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}

int MyAtoi(const char *str)
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

    return result - 1;
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

char * MyStrDup(const char *str)
{
    int str_len = MyStrLen(str);
    int i = 0;
    char *str_dup = (char *) calloc(str_len + 1, sizeof(char));

    for (; i < str_len; i++)
        str_dup[i] = str[i];

    str_dup[i] = '\0';

    return str_dup;
}

size_t MyGetLine(char **str_ptr, size_t *n, FILE * stream)
{
    char *str_ptr_check = NULL;
    str_ptr_check = (char *)calloc(*n, sizeof (char));

    if (str_ptr_check == NULL)
        return 0;

    *str_ptr = str_ptr_check;

    int ch = 0;
    int i = 0;

    while (true)
    {
        ch = getc(stream);
        
        if (i >= *n - 2)
        {
            str_ptr_check = (char *)realloc(*str_ptr, *n * 2);

            if (str_ptr_check == NULL)
                break;

            *n *= 2;
            *str_ptr = str_ptr_check;
        }

        if (ch == '\n')
        {
            (*str_ptr)[i] = '\n';
            (*str_ptr)[i + 1] = '\0';

            break;
        }
        else if (ch == EOF)
        {
            (*str_ptr)[i] = '\0';

            break;
        }

        (*str_ptr)[i] = ch;
        i++;
    }

    return MyStrLen(*str_ptr);
}