#include <stdio.h>
#include <string.h>
#include "MyStr.h"

int main(void)
{
    char str[] = "acdefder";
    printf("%d\n", strchr(str, 'b'));
    printf("%d\n", MyStrChr(str, 'b'));

    return 0;
}