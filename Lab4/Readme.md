# Лабораторная работа №4

Задача 1.

Познакомиться с библиотечными функциями работы со строками:
1) strlen() - определение длины строки
2) strcat() - конкатенация строк
3) strcpy() - копирование строк
4) strcmp() - сравнение строк


Задача 2.

Написать программу которая будет использовать свои варианты следующих функций:
1) определения длины строки (тремя разными способами)
2) копирования строк
3) сравнения строк
4) конкатенации строк

   Функции для определения длины строки:

int lenghtStr1(const char* str) {
    int length = 0;
    while (*str++) length++;
    return length;
}

int lenghtStr2(const char* str) {
    int length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

int lenghtStr3(const char* str) {
    const char* s = str;
    while (*s) ++s;
    return s - str;
}

  Функция копирования строк:

int comparyStr(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

  Функция конкатенации строк:

  void concatStr(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

Код исходной программы: https://github.com/TorhovKonstantin/labs/blob/main/Lab4/lab4.1.cpp

Результаты решения:

![image](https://github.com/TorhovKonstantin/labs/assets/122263721/d8730711-5c3a-442e-85b0-60abdd47a899)

