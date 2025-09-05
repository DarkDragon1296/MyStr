#ifndef MY_STR_H
#define MY_STR_H

int MyPutS(const char * str); // Выводит строку

int MyStrLen(const char * str); // Возвращает длину строки

char * MyStrChr(char * str, const char ch); // Поиск символа в строке

char * MyStrCat(char * dest, const char * src); // объединение строк

char * MyStrNCat(char * dest, const char * src, const int n); //Объединение строк с контроем длины

int MyAtoi(const char * str);

#endif