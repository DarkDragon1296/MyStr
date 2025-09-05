#include <stdio.h>
#include <string.h>
#include "MyStr.h"

int main(void)
{
    const char *str1 = "123";
    const char *str2 = "-456";
    const char *str3 = "7.89";    // Преобразуется в 7
    const char *str4 = "12abc";   // Преобразуется в 12
    const char *str5 = "abc123";  // Преобразуется в 0
    
    int num1 = MyAtoi(str1);
    int num2 = MyAtoi(str2);
    int num3 = MyAtoi(str3);
    int num4 = MyAtoi(str4);
    int num5 = MyAtoi(str5);
    
    printf("'%s' -> %d\n", str1, num1); // 123
    printf("'%s' -> %d\n", str2, num2); // -456
    printf("'%s' -> %d\n", str3, num3); // 7
    printf("'%s' -> %d\n", str4, num4); // 12
    printf("'%s' -> %d\n", str5, num5); // 0
}