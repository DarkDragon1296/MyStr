#ifndef MY_STR_H
#define MY_STR_H

int MyPutS(const char *str); // Выводит строку

int MyStrLen(const char *str); // Возвращает длину строки

char * MyStrChr(char *str, const int ch); // Поиск символа в строке

char * MyStrCat(char *dest, const char *src); // объединение строк

char * MyStrNCat(char *dest, const char *src, const int n); //Объединение строк с контроем длины

int MyAtoi(const char *str); // Преобразует строку в число

char * MyFGetS(char *str, int n, FILE *stream); // Получение строки из файла

char * MyStrDup(const char *str); // Дублирует строку с выделением памяти

size_t MyGetLine(char **str_ptr, size_t *n, FILE * stream);

#endif