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

int MyGetLine(char **str_ptr, int *n, FILE * stream) // TODO:  переделать
{
    *str_ptr = (char *)calloc(*n, sizeof (char));
    int ch = 0;
    int i = 0;

    while (true)
    {
        printf("MEOW\n");
        ch = getc(stream);

        if (ch == '\n')
        {
            char *temp = (char *)realloc(*str_ptr, (i + 2) * sizeof(char));
        
            (*n)++;

            if (!temp)
            {
                (*str_ptr)[i] = '\n';
                (*str_ptr)[i + 1] = '\0';
                return i + 1;
            }

            *str_ptr = temp;

            break;
        }
        else if (ch == EOF)
        {
            char *temp = (char *)realloc(*str_ptr, *n);

            if (!temp) {
                (*str_ptr)[i] = '\0';
                return -1;
            }

            *str_ptr = temp;

            break;
        }

        if (i >= *n)
        {
            char *temp = (char *)realloc(*str_ptr, (i + 1) * sizeof(char));

            if (!temp)
                return -1;
            
            *str_ptr = temp;
            
            (*n)++;
        }

        (*str_ptr)[i] = ch;
        i++;
    }

    return MyStrLen(*str_ptr);
}